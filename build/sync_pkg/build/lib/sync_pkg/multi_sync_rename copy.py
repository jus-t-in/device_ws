#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2
from collections import deque
import numpy as np
from cv_bridge import CvBridge
import cv2


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
            self.cam_buffers.append(deque(maxlen=5))

        # 发布 lidar
        self.lidar_pub = self.create_publisher(PointCloud2, '/synced/lidar_top', 10)

        # 发布相机 (使用映射后的名字)
        self.cam_pubs = {
            i: self.create_publisher(Image, topic, 10)
            for i, topic in self.cam_topic_map.items()
        }

    def cam_cb(self, msg, idx):
        """缓存每路相机消息并统一为 bgr8"""
        try:
            # 转为 OpenCV 格式
            cv_img = self.bridge.imgmsg_to_cv2(msg, desired_encoding='bgr8')
            # 转回 ROS Image 消息
            new_msg = self.bridge.cv2_to_imgmsg(cv_img, encoding='bgr8')
            new_msg.header = msg.header
            t = new_msg.header.stamp.sec + new_msg.header.stamp.nanosec * 1e-9
            self.cam_buffers[idx].append((t, new_msg))
        except Exception as e:
            self.get_logger().warn(f"cam_cb conversion failed: {e}")

    def lidar_cb(self, msg):
        """雷达触发，发布严格同步消息"""
        t_lidar = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        selected = []

        for buf in self.cam_buffers:
            if not buf:
                return  # 有相机没数据 -> 丢掉
            # 找最接近雷达时间戳的相机帧
            times = np.array([t for t, _ in buf])
            diffs = np.abs(times - t_lidar)
            idx = np.argmin(diffs)
            if diffs[idx] > 0.1:  # 超过 50ms 差异就丢弃
                return
            selected.append(buf[idx][1])

        # 发布严格对齐的消息
        self.lidar_pub.publish(msg)
        for i, cam_msg in enumerate(selected):
            cam_msg.header.stamp = msg.header.stamp
            self.cam_pubs[i].publish(cam_msg)

        self.get_logger().info(
            f"Published 1 lidar + 6 cameras @ t={t_lidar:.3f}"
        )


def main():
    rclpy.init()
    node = StrictSync()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()

