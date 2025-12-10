#!/usr/bin/env python3
"""
静态TF发布器 - 发布所有传感器相对于base_link的固定变换
适用于小型配送车的传感器布局
"""

import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros import StaticTransformBroadcaster


class SensorStaticTFPublisher(Node):
    """发布传感器静态TF变换"""

    def __init__(self):
        super().__init__('sensor_static_tf_publisher')
        
        self.tf_broadcaster = StaticTransformBroadcaster(self)
        
        # 发布所有静态变换
        self.publish_static_transforms()
        
        self.get_logger().info('传感器静态TF已发布')
        self.get_logger().info('  - base_link -> radar_frame')
        self.get_logger().info('  - base_link -> rslidar')
        self.get_logger().info('  - base_link -> camera0~5 (环视布局)')

    def publish_static_transforms(self):
        """发布所有静态TF变换"""
        transforms = []
        
        # 1. 毫米波雷达 - 车头前方
        transforms.append(self.create_transform(
            parent='base_link',
            child='radar_frame',
            x=0.2, y=0.0, z=0.4,
            roll=0.0, pitch=0.0, yaw=0.0
        ))
        
        # 2. 激光雷达 - 车顶中央
        transforms.append(self.create_transform(
            parent='base_link',
            child='rslidar',
            x=0.15, y=0.0, z=0.5,
            roll=0.0, pitch=0.0, yaw=0.0
        ))
        
        # 3. 6个环视相机 - 车顶环视布局，半径0.3m
        # camera0: 正前方
        transforms.append(self.create_transform(
            parent='base_link',
            child='camera0',
            x=0.3, y=0.0, z=0.3,
            roll=0.0, pitch=0.0, yaw=0.0
        ))
        
        # camera1: 右前方 (60度)
        angle1 = math.radians(60)
        transforms.append(self.create_transform(
            parent='base_link',
            child='camera1',
            x=0.3 * math.cos(angle1), 
            y=-0.3 * math.sin(angle1), 
            z=0.3,
            roll=0.0, pitch=0.0, yaw=-60.0
        ))
        
        # camera2: 右后方 (120度)
        angle2 = math.radians(120)
        transforms.append(self.create_transform(
            parent='base_link',
            child='camera2',
            x=0.3 * math.cos(angle2), 
            y=-0.3 * math.sin(angle2), 
            z=0.3,
            roll=0.0, pitch=0.0, yaw=-120.0
        ))
        
        # camera3: 正后方 (180度)
        transforms.append(self.create_transform(
            parent='base_link',
            child='camera3',
            x=- 0.3, y=0.0, z=0.3,
            roll=0.0, pitch=0.0, yaw=180.0
        ))
        
        # camera4: 左后方 (240度 = -120度)
        angle4 = math.radians(-120)
        transforms.append(self.create_transform(
            parent='base_link',
            child='camera4',
            x=0.3 * math.cos(angle4), 
            y=-0.3 * math.sin(angle4), 
            z=0.3,
            roll=0.0, pitch=0.0, yaw=120.0
        ))
        
        # camera5: 左前方 (300度 = -60度)
        angle5 = math.radians(-60)
        transforms.append(self.create_transform(
            parent='base_link',
            child='camera5',
            x=0.3 * math.cos(angle5), 
            y=-0.3 * math.sin(angle5), 
            z=0.3,
            roll=0.0, pitch=0.0, yaw=60.0
        ))
        
        # 发布所有静态变换
        self.tf_broadcaster.sendTransform(transforms)

    def create_transform(self, parent, child, x, y, z, roll, pitch, yaw):
        """
        创建TF变换
        
        Args:
            parent: 父坐标系
            child: 子坐标系
            x, y, z: 平移 (米)
            roll, pitch, yaw: 旋转角度 (度)
        """
        t = TransformStamped()
        t.header.stamp = self.get_clock().now().to_msg()
        t.header.frame_id = parent
        t.child_frame_id = child
        
        # 设置平移
        t.transform.translation.x = x
        t.transform.translation.y = y
        t.transform.translation.z = z
        
        # 将欧拉角转换为四元数
        quat = self.euler_to_quaternion(roll, pitch, yaw)
        t.transform.rotation.x = quat[0]
        t.transform.rotation.y = quat[1]
        t.transform.rotation.z = quat[2]
        t.transform.rotation.w = quat[3]
        
        return t

    def euler_to_quaternion(self, roll, pitch, yaw):
        """
        欧拉角转四元数 (角度输入)
        
        Args:
            roll, pitch, yaw: 欧拉角 (度)
            
        Returns:
            [x, y, z, w]: 四元数
        """
        # 转换为弧度
        roll = math.radians(roll)
        pitch = math.radians(pitch)
        yaw = math.radians(yaw)
        
        # 计算四元数
        cy = math.cos(yaw * 0.5)
        sy = math.sin(yaw * 0.5)
        cp = math.cos(pitch * 0.5)
        sp = math.sin(pitch * 0.5)
        cr = math.cos(roll * 0.5)
        sr = math.sin(roll * 0.5)
        
        w = cr * cp * cy + sr * sp * sy
        x = sr * cp * cy - cr * sp * sy
        y = cr * sp * cy + sr * cp * sy
        z = cr * cp * sy - sr * sp * cy
        
        return [x, y, z, w]


def main(args=None):
    rclpy.init(args=args)
    node = SensorStaticTFPublisher()
    
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
