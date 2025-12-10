#!/usr/bin/env python3
"""
启动所有传感器和TF发布器的launch文件
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """生成launch描述"""
    
    return LaunchDescription([
        # 静态TF发布器
        Node(
            package='sensor_tf_publisher',
            executable='static_tf_publisher',
            name='sensor_static_tf_publisher',
            output='screen',
        ),
    ])
