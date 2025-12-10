
## 编译工作空间

```bash
cd ~/work/device_ws
colcon build
```

---

# 一、GMSL 相机驱动

## 1.1 WebSetting 中配置相机参数

在 MIIVII WebSetting 中完成 GMSL 相机参数设置。

## 1.2 相机 v4l2 初始化

```bash
MIIVII_WIDTH=640     # 每路显示宽度
MIIVII_HEIGHT=360    # 每路显示高度

gst-launch-1.0 nvcompositor name=comp \
  sink_0::xpos=0   sink_0::ypos=0   sink_0::width=$MIIVII_WIDTH sink_0::height=$MIIVII_HEIGHT \
  sink_1::xpos=$MIIVII_WIDTH sink_1::ypos=0 sink_1::width=$MIIVII_WIDTH sink_1::height=$MIIVII_HEIGHT \
  sink_2::xpos=$(($MIIVII_WIDTH*2)) sink_2::ypos=0 sink_2::width=$MIIVII_WIDTH sink_2::height=$MIIVII_HEIGHT \
  sink_3::xpos=0   sink_3::ypos=$MIIVII_HEIGHT sink_3::width=$MIIVII_WIDTH sink_3::height=$MIIVII_HEIGHT \
  sink_4::xpos=$MIIVII_WIDTH sink_4::ypos=$MIIVII_HEIGHT sink_4::width=$MIIVII_WIDTH sink_4::height=$MIIVII_HEIGHT \
  sink_5::xpos=$(($MIIVII_WIDTH*2)) sink_5::ypos=$MIIVII_HEIGHT sink_5::width=$MIIVII_WIDTH sink_5::height=$MIIVII_HEIGHT \
  ! nv3dsink sync=false \
  v4l2src device="/dev/video0" \
    ! "video/x-raw,format=UYVY,width=1920,height=1080,framerate=30/1" \
    ! nvvidconv ! "video/x-raw(memory:NVMM),format=NV12" ! comp.sink_0 \
  v4l2src device="/dev/video1" \
    ! "video/x-raw,format=UYVY,width=1920,height=1080,framerate=30/1" \
    ! nvvidconv ! "video/x-raw(memory:NVMM),format=NV12" ! comp.sink_1 \
  v4l2src device="/dev/video2" \
    ! "video/x-raw,format=UYVY,width=1920,height=1080,framerate=30/1" \
    ! nvvidconv ! "video/x-raw(memory:NVMM),format=NV12" ! comp.sink_2 \
  v4l2src device="/dev/video3" \
    ! "video/x-raw,format=UYVY,width=1920,height=1080,framerate=30/1" \
    ! nvvidconv ! "video/x-raw(memory:NVMM),format=NV12" ! comp.sink_3 \
  v4l2src device="/dev/video4" \
    ! "video/x-raw,format=UYVY,width=1920,height=1080,framerate=30/1" \
    ! nvvidconv ! "video/x-raw(memory:NVMM),format=NV12" ! comp.sink_4 \
  v4l2src device="/dev/video5" \
    ! "video/x-raw,format=UYVY,width=1920,height=1080,framerate=30/1" \
    ! nvvidconv ! "video/x-raw(memory:NVMM),format=NV12" ! comp.sink_5
```

## 1.3 启动相机节点

```bash
source install/setup.bash
ros2 launch miivii_gmsl_camera small_delivery_car_profile1.launch
```

**提示：如遇黑屏，重新执行 1.1 的相机参数配置。**

---

# 二、Rslidar 激光雷达驱动

## 2.1 配置 IP

* 电脑：`192.168.1.102`
* 雷达：`192.168.1.200`

## 2.2 启动

```bash
source install/setup.bash
ros2 launch rslidar_sdk start.py
```

## 2.3 配置文件

编辑：

```
src/rslidar_sdk/config/config.yaml
```

---

# 三、ARS408 毫米波雷达驱动

## 3.1 配置 CAN

```bash
sudo ip link set can0 up type can bitrate 500000
candump can0
```

## 3.2 启动

```bash
source install/setup.bash
ros2 launch pe_ars408_ros continental_ars408_socket_can.launch.xml
```

---

# 四、传感器 TF 变换

## 4.1 坐标系布局

* **base_link**：车辆中心（地面）
* **radar_frame**：毫米波雷达

  * (x=0.2, y=0.0, z=0.4)
* **rslidar**：激光雷达

  * (x=0.15, y=0.0, z=0.5)
* **camera0~5**：环视相机
    ( z=0.3)
  * camera0：前方
  * camera1：右前 60°
  * camera2：右后 120°
  * camera3：后 180°
  * camera4：左后 240°
  * camera5：左前 300°

## 4.2 启动 TF 发布器（必需）

```bash
ros2 launch sensor_tf_publisher sensor_tf.launch.py
```

## 4.3 查看 TF 树

```bash
ros2 run tf2_tools view_frames
```

## 4.4 查看指定 TF

```bash
ros2 run tf2_ros tf2_echo base_link radar_frame
ros2 run tf2_ros tf2_echo base_link rslidar
ros2 run tf2_ros tf2_echo base_link camera0
```

## 4.5 一键启动 TF + 毫米波雷达

```bash
ros2 launch sensor_tf_publisher all_sensors.launch.py
```

## 4.6 修改传感器位置

编辑：

```
src/sensor_tf_publisher/sensor_tf_publisher/static_tf_publisher.py
```

---

# 五、传感器数据时间同步（sync_pkg）

## 5.1 功能说明

* 激光雷达为主时钟
* 匹配时间最接近的相机帧与雷达帧
* 时间阈值：50 ms
* 所有同步数据使用激光雷达时间戳

## 5.2 话题映射

### 输入

* `/lidar_top`
* `/miivii_gmsl/image0~5`
* `/ARS408_CAN/visualization_marker_radar`

### 输出（同步后）

* `/synced/lidar_top`
* `/synced/image0~5`
* `/synced/radar_markers`

## 5.3 启动同步节点

```bash
ros2 launch sync_pkg sync.launch.py
```

## 5.4 验证同步效果

```bash
ros2 topic echo /synced/lidar_top --field header.stamp
ros2 topic echo /synced/image0 --field header.stamp
ros2 topic echo /synced/radar_markers --field markers[0].header.stamp
```

## 5.5 参数修改

编辑：

```
src/sync_pkg/sync_pkg/multi_sync_pub.py
```

---

# 六、完整启动流程（推荐）

## 6.1 准备步骤

```bash
# 编译
cd ~/work/device_ws
colcon build

# 配置 CAN
sudo ip link set can0 up type can bitrate 500000

# 配置网络
# PC: 192.168.1.102, Lidar: 192.168.1.200

# 初始化相机 v4l2（见章节 1.2）
```

## 6.2 多终端启动系统

### 终端 1：TF + 毫米波雷达 + 同步

```bash
ros2 launch sensor_tf_publisher all_with_sync.launch.py
```

### 终端 2：相机

```bash
ros2 launch miivii_gmsl_camera small_delivery_car_profile1.launch
```

### 终端 3：激光雷达

```bash
ros2 launch rslidar_sdk start.py
```

## 6.3 RViz 显示

```bash
rviz2
```

配置：

* Fixed Frame = `base_link`
* 添加：

  * PointCloud2：`/synced/lidar_top`
  * Image：`/synced/image0~5`
  * MarkerArray：`/synced/radar_markers`
  * TF

---

# 七、常见问题 FAQ

## 7.1 RViz 报错 frame 不存在

启动 TF 发布器：

```bash
ros2 launch sensor_tf_publisher sensor_tf.launch.py
```

## 7.2 同步节点无输出

检查是否所有传感器都在发布：

```bash
ros2 topic list | grep -E "lidar|image|radar"
```

## 7.3 相机黑屏

重新执行 WebSetting 参数配置并重新初始化。

## 7.4 激光雷达无数据

检查网络并 ping：

```bash
ping 192.168.1.200
```

## 7.5 毫米波雷达无数据

```bash
candump can0
sudo ip link set can0 down
sudo ip link set can0 up type can bitrate 500000
```

---

# 八、包结构说明

* **ARS408_driver**：毫米波雷达驱动
* **miivii_gmsl_camera**：GMSL 六路相机驱动
* **rslidar_sdk**：速腾雷达驱动
* **sensor_tf_publisher**：TF 发布器
* **sync_pkg**：多传感器时间同步

