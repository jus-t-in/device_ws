#!/usr/bin/env python3
"""
一键启动所有传感器、TF发布器和同步节点
包含：TF发布器 + 毫米波雷达 + 数据同步
注意：相机和激光雷达需要按照readme中的步骤手动启动
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    """生成launch描述"""
    
    # 获取ARS408雷达的launch文件路径
    ars408_launch = os.path.join(
        get_package_share_directory('ARS408_driver'),
        'launch',
        'ARS408_CAN_node.launch.xml'
    )
    
    return LaunchDescription([
        # 1. 静态TF发布器
        Node(
            package='sensor_tf_publisher',
            executable='static_tf_publisher',
            name='sensor_static_tf_publisher',
            output='screen',
        ),
        
        # 2. 毫米波雷达
        IncludeLaunchDescription(
            AnyLaunchDescriptionSource(ars408_launch),
            launch_arguments={
                'can_interface': 'can0',
                'out_object_topic': 'radar_object',
            }.items()
        ),
        
        # 3. 同步节点
        Node(
            package='sync_pkg',
            executable='multi_sync_pub',
            name='strict_sync',
            output='screen',
        ),
    ])
