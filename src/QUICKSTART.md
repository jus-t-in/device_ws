# 小型配送车多传感器系统 - 快速启动指南

## 📋 系统组成
- **毫米波雷达**: ARS408 (CAN接口)
- **激光雷达**: 速腾 (网络接口)
- **相机**: 6路GMSL环视相机
- **TF变换**: 所有传感器坐标系发布
- **时间同步**: 三种传感器严格时间对齐

## 🚀 快速启动（一键启动推荐）

### 准备工作
```bash
# 1. 编译
cd ~/work/device_ws
colcon build

# 2. 配置CAN
sudo ip link set can0 up type can bitrate 500000

# 3. 相机v4l2初始化（见readme详细命令）
```

### 启动传感器（3个终端）

**终端1** - 激光雷达

```bash
source install/setup.bash
ros2 launch rslidar_sdk start.py
```
**终端2** - 相机
```bash
source install/setup.bash
ros2 launch miivii_gmsl_camera small_delivery_car_profile1.launch
```

**终端3** - TF + 毫米波雷达 + 同步节点
```bash
source install/setup.bash
ros2 launch sensor_tf_publisher all_with_sync.launch.py
```

## 📊 数据话题

### 原始话题
- `/lidar_top` - 激光雷达点云
- `/miivii_gmsl/image0~5` - 6路相机图像
- `/ARS408_CAN/visualization_marker_radar` - 毫米波雷达

### 同步话题（推荐使用）
- `/synced/lidar_top` - 同步的激光雷达
- `/synced/image0~5` - 同步的相机
- `/synced/radar_markers` - 同步的雷达

## 🔍 RViz可视化

```bash
rviz2
```

配置：
1. **Fixed Frame**: `base_link`
2. 添加：
   - PointCloud2 → `/synced/lidar_top`
   - Image → `/synced/image0~5`
   - MarkerArray → `/synced/radar_markers`
   - TF → 显示所有坐标系

## 🛠️ 常用调试命令

```bash
# 查看所有话题
ros2 topic list

# 检查话题频率
ros2 topic hz /synced/lidar_top

# 查看TF树
ros2 run tf2_tools view_frames

# 验证时间同步
ros2 topic echo /synced/lidar_top --field header.stamp
ros2 topic echo /synced/image0 --field header.stamp
```

## ⚠️ 故障排除

| 问题 | 解决方案 |
|------|---------|
| RViz报错frame不存在 | 启动TF发布器 |
| 相机黑屏 | 重新配置websetting和v4l2初始化 |
| 激光雷达无数据 | 检查网络：`ping 192.168.1.200` |
| 毫米波雷达无数据 | 检查CAN：`candump can0` |
| 同步节点无输出 | 确认所有传感器话题都在发布 |

## 📁 重要文件位置

- TF配置: `src/sensor_tf_publisher/sensor_tf_publisher/static_tf_publisher.py`
- 同步参数: `src/sync_pkg/sync_pkg/multi_sync_pub.py`
- 激光雷达配置: `src/rslidar_sdk/config/config.yaml`
- 详细文档: `src/readme.md`

## 📐 传感器布局

```
                [camera0]
                   ↑
        [camera5] base_link [camera1]
                   │
        [camera4] [camera3] [camera2]
                   │
            [rslidar: 0.2,0,0.5]
                   │
         [radar_frame: 0.5,0,0.3] →
```

---
更多详情请查看 `src/readme.md`
