#!/usr/bin/env python3
"""
启动同步节点的launch文件
同步激光雷达、相机和毫米波雷达的数据
"""

from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    """生成launch描述"""
    
    return LaunchDescription([
        # 同步节点
        Node(
            package='sync_pkg',
            executable='multi_sync_pub',
            name='strict_sync',
            output='screen',
            parameters=[{
                'use_sim_time': False,
            }]
        ),
    ])
