#!/usr/bin/env python3
"""
启动所有传感器和TF发布器的完整launch文件
包含：毫米波雷达、激光雷达、相机、同步节点和TF发布器
"""

from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import IncludeLaunchDescription
from launch.launch_description_sources import AnyLaunchDescriptionSource
import os
from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    """生成launch描述"""
    
    # 获取各个包的launch文件路径
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
        
        # 3. 相机节点 (需要手动启动: ros2 launch miivii_gmsl_camera small_delivery_car_profile1.launch)
        # 4. 激光雷达节点 (需要手动启动: ros2 launch rslidar_sdk start.py)
        # 5. 同步节点 (可选)
        # Node(
        #     package='sync_pkg',
        #     executable='multi_sync_pub',
        #     name='strict_sync',
        #     output='screen',
        # ),
    ])
