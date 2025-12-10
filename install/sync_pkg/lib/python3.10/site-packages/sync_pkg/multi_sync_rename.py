#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2
from collections import deque
import numpy as np
from cv_bridge import CvBridge
import cv2
import time


class StrictSync(Node):
    def __init__(self):
        super().__init__('strict_sync')

        self.bridge = CvBridge()

        # 相机 topic 映射表
        self.cam_topic_map = {
            0: "/cam_front_left/raw",
            1: "/cam_front/raw",
            2: "/cam_front_right/raw",
            3: "/cam_back_right/raw",
            4: "/cam_back/raw",
            5: "/cam_back_left/raw"
        }

        # 同步参数
        self.strict_time_threshold = 0.05   # 严格模式: 50ms
        self.relaxed_time_threshold = 0.15  # 宽松模式: 150ms
        self.min_publish_interval = 1.0     # 最小发布间隔: 1秒
        self.last_publish_time = 0.0
        
        # 缓存最后成功发布的帧(用于降级发布)
        self.last_valid_frames = [None] * 6
        self.last_valid_lidar = None

        # 订阅 lidar
        self.create_subscription(PointCloud2, '/lidar_top', self.lidar_cb, 10)

        # 订阅相机
        self.cam_subs = []
        self.cam_buffers = []
        for i in range(6):
            sub = self.create_subscription(
                Image, f'/miivii_gmsl/image{i}',
                lambda msg, i=i: self.cam_cb(msg, i), 10
            )
            self.cam_subs.append(sub)
            self.cam_buffers.append(deque(maxlen=10))  # 增加缓冲区

        # 发布 lidar
        self.lidar_pub = self.create_publisher(PointCloud2, '/synced/lidar_top', 10)

        # 发布相机
        self.cam_pubs = {
            i: self.create_publisher(Image, topic, 10)
            for i, topic in self.cam_topic_map.items()
        }
        
        # 统计信息
        self.strict_count = 0
        self.relaxed_count = 0
        self.fallback_count = 0

    def cam_cb(self, msg, idx):
        """缓存每路相机消息并统一为 bgr8"""
        try:
            cv_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            new_msg = self.bridge.cv2_to_imgmsg(cv_img, encoding='bgr8')
            new_msg.header = msg.header
            t = new_msg.header.stamp.sec + new_msg.header.stamp.nanosec * 1e-9
            self.cam_buffers[idx].append((t, new_msg))
        except Exception as e:
            self.get_logger().warn(f"cam_cb conversion failed: {e}")

    def find_best_match(self, buf, t_lidar, threshold):
        """在缓冲区中查找最佳匹配帧"""
        if not buf:
            return None, float('inf')
        
        times = np.array([t for t, _ in buf])
        diffs = np.abs(times - t_lidar)
        idx = np.argmin(diffs)
        
        if diffs[idx] <= threshold:
            return buf[idx][1], diffs[idx]
        return None, diffs[idx]

    def lidar_cb(self, msg):
        """雷达触发，使用多级降级策略"""
        t_lidar = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        current_time = time.time()
        
        # 尝试严格同步 (50ms内)
        selected = []
        max_diff = 0
        
        for i, buf in enumerate(self.cam_buffers):
            cam_msg, diff = self.find_best_match(buf, t_lidar, self.strict_time_threshold)
            if cam_msg is None:
                break
            selected.append(cam_msg)
            max_diff = max(max_diff, diff)
        
        # 策略1: 严格同步成功
        if len(selected) == 6:
            self._publish_sync(msg, selected, t_lidar, f"STRICT (max_diff={max_diff*1000:.1f}ms)")
            self.strict_count += 1
            # 更新最后成功帧
            self.last_valid_frames = selected.copy()
            self.last_valid_lidar = msg
            self.last_publish_time = current_time
            return
        
        # 策略2: 宽松同步 (150ms内)
        selected = []
        for i, buf in enumerate(self.cam_buffers):
            cam_msg, diff = self.find_best_match(buf, t_lidar, self.relaxed_time_threshold)
            if cam_msg is None:
                break
            selected.append(cam_msg)
        
        if len(selected) == 6:
            self._publish_sync(msg, selected, t_lidar, f"RELAXED (max_diff={max_diff*1000:.1f}ms)")
            self.relaxed_count += 1
            self.last_valid_frames = selected.copy()
            self.last_valid_lidar = msg
            self.last_publish_time = current_time
            return
        
        # 策略3: 降级发布 - 超过1秒没发布则使用最后有效帧
        time_since_last = current_time - self.last_publish_time
        if time_since_last >= self.min_publish_interval and all(self.last_valid_frames):
            self.get_logger().warn(
                f"Fallback mode: using last valid frames (age={time_since_last:.1f}s)"
            )
            self._publish_sync(msg, self.last_valid_frames, t_lidar, "FALLBACK")
            self.fallback_count += 1
            self.last_publish_time = current_time
            return
        
        # 如果都失败，记录警告
        if time_since_last > 2.0:
            self.get_logger().error(
                f"No sync for {time_since_last:.1f}s! "
                f"Buffer status: {[len(b) for b in self.cam_buffers]}"
            )

    def _publish_sync(self, lidar_msg, cam_msgs, t_lidar, mode):
        """发布同步消息"""
        self.lidar_pub.publish(lidar_msg)
        for i, cam_msg in enumerate(cam_msgs):
            cam_msg.header.stamp = lidar_msg.header.stamp
            self.cam_pubs[i].publish(cam_msg)
        
        self.get_logger().info(
            f"[{mode}] t={t_lidar:.3f} | "
            f"Stats: strict={self.strict_count} relaxed={self.relaxed_count} "
            f"fallback={self.fallback_count}"
        )


def main():
    rclpy.init()
    node = StrictSync()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

