#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Image, PointCloud2
from visualization_msgs.msg import MarkerArray
from collections import deque
import numpy as np

class StrictSync(Node):
    def __init__(self):
        super().__init__('strict_sync')

        # 订阅器
        self.create_subscription(PointCloud2, '/lidar_top', self.lidar_cb, 10)
        self.create_subscription(MarkerArray, '/ARS408_CAN/visualization_marker_radar', self.radar_cb, 10)
        
        self.cam_subs = []
        self.cam_buffers = []
        for i in range(6):
            sub = self.create_subscription(Image, f'/miivii_gmsl/image{i}',
                                           lambda msg, i=i: self.cam_cb(msg, i), 10)
            self.cam_subs.append(sub)
            self.cam_buffers.append(deque(maxlen=5))  # 每路相机缓存 5 帧
        
        # 毫米波雷达缓存
        self.radar_buffer = deque(maxlen=5)

        # 发布器
        self.lidar_pub = self.create_publisher(PointCloud2, '/synced/lidar_top', 10)
        self.cam_pubs = [self.create_publisher(Image, f'/synced/image{i}', 10) for i in range(6)]
        self.radar_pub = self.create_publisher(MarkerArray, '/synced/radar_markers', 10)

    def cam_cb(self, msg, idx):
        """缓存每路相机消息"""
        t = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        self.cam_buffers[idx].append((t, msg))
    
    def radar_cb(self, msg):
        """缓存毫米波雷达消息"""
        if msg.markers:  # 确保有markers
            t = msg.markers[0].header.stamp.sec + msg.markers[0].header.stamp.nanosec * 1e-9
            self.radar_buffer.append((t, msg))

    def lidar_cb(self, msg):
        """激光雷达作为触发源"""
        t_lidar = msg.header.stamp.sec + msg.header.stamp.nanosec * 1e-9
        selected = []

        # 1. 检查并匹配相机数据
        for buf in self.cam_buffers:
            if not buf:
                return  # 有相机没数据 -> 丢弃
            # 找最接近激光雷达时间戳的相机帧
            times = np.array([t for t, _ in buf])
            diffs = np.abs(times - t_lidar)
            idx = np.argmin(diffs)
            if diffs[idx] > 0.05:  # 超过 50ms 差异就丢弃
                return
            selected.append(buf[idx][1])
        
        # 2. 检查并匹配毫米波雷达数据
        radar_msg = None
        if self.radar_buffer:
            radar_times = np.array([t for t, _ in self.radar_buffer])
            radar_diffs = np.abs(radar_times - t_lidar)
            radar_idx = np.argmin(radar_diffs)
            if radar_diffs[radar_idx] <= 0.05:  # 50ms以内认为同步
                radar_msg = self.radar_buffer[radar_idx][1]
            else:
                self.get_logger().warn(f"Radar data too old, diff={radar_diffs[radar_idx]:.3f}s")
                return  # 雷达数据不同步，丢弃整组

        # 发布严格对齐的消息
        self.lidar_pub.publish(msg)
        
        for pub, cam_msg in zip(self.cam_pubs, selected):
            # 替换时间戳为激光雷达时间，保证 1:1
            cam_msg.header.stamp = msg.header.stamp
            pub.publish(cam_msg)
        
        if radar_msg:
            # 更新雷达markers的时间戳
            for marker in radar_msg.markers:
                marker.header.stamp = msg.header.stamp
            self.radar_pub.publish(radar_msg)
            self.get_logger().info("Published 1 lidar + 6 cameras + 1 radar @ t=%.3f" % t_lidar)
        else:
            self.get_logger().info("Published 1 lidar + 6 cameras (no radar) @ t=%.3f" % t_lidar)


def main():
    rclpy.init()
    node = StrictSync()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

