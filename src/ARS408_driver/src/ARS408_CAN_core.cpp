#include "ARS408_driver/ARS408_CAN_core.hpp"

Radar_408_60b radar_60b = {0,0,0,0,0,0,0,0};//dbc结构体
Radar_408_200 radar_200 = {0,0,0,0,0,0,0};//dbc结构体
Radar_408_202 radar_202 = {0,0,0,0,0,0};//dbc结构体
Radar_408_60d radar_60d = {0,0,0,0,0,0};

ARS408_CAN::ARS408_CAN(const std::string & node_name, const rclcpp::NodeOptions & node_options)
: rclcpp::Node(node_name, node_options)
{
    pub_object_ = create_publisher<radar_msgs::msg::RadarTrack>("~/input/radar_object", 10);
    pub_objects_ = create_publisher<radar_msgs::msg::RadarTracks>("~/input/radar_objects", 10);
    pub_markers_ = create_publisher<visualization_msgs::msg::MarkerArray>("~/visualization_marker_radar", 10);

    init_param();
    CanPortInit();
    // Radar_cfg();
    ReceiveDate();
}

void ARS408_CAN::init_param()
{
    _out_object_topic = declare_parameter("out_object_topic", "/dev/ttyUSB0");
    RCLCPP_INFO(this->get_logger(),"[%s] the param out_object_topic value is... %s", "ARS408_CAN_node", _out_object_topic.c_str());

    _can_interface = declare_parameter("can_interface", "can0");
    RCLCPP_INFO(this->get_logger(),"[%s] the param can_interface value is... %s", "ARS408_CAN_node", _can_interface.c_str());

    out_hz_ = declare_parameter("out_hz", 1000);
    RCLCPP_INFO(this->get_logger(),"[%s] the param out_hz value is... %lf", "ARS408_CAN_node", out_hz_);

    Threshold_x_ = declare_parameter("Threshold_x", 150);
    RCLCPP_INFO(this->get_logger(),"[%s] the param Threshold_x_ value is... %d", "ARS408_CAN_node", Threshold_x_);

    Threshold_y_ = declare_parameter("Threshold_y", 4);
    RCLCPP_INFO(this->get_logger(),"[%s] the param Threshold_y_ value is... %d", "ARS408_CAN_node", Threshold_y_);
}

void ARS408_CAN::CanPortInit()
{
    std::cout << "***************** SocketCAN Initialization *****************" << std::endl;
    
    // 创建 socket
    can_socket_ = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if (can_socket_ < 0) {
        RCLCPP_ERROR(this->get_logger(), "Error while opening socket");
        exit(1);
    }
    
    // 指定 CAN 接口
    std::strcpy(ifr_.ifr_name, _can_interface.c_str());
    if (ioctl(can_socket_, SIOCGIFINDEX, &ifr_) < 0) {
        RCLCPP_ERROR(this->get_logger(), "Error in ioctl for interface: %s", _can_interface.c_str());
        close(can_socket_);
        exit(1);
    }
    
    // 绑定 socket
    addr_.can_family = AF_CAN;
    addr_.can_ifindex = ifr_.ifr_ifindex;
    
    if (bind(can_socket_, (struct sockaddr *)&addr_, sizeof(addr_)) < 0) {
        RCLCPP_ERROR(this->get_logger(), "Error in socket bind");
        close(can_socket_);
        exit(1);
    }
    
    RCLCPP_INFO(this->get_logger(), ">> >>SocketCAN interface %s opened successfully!", _can_interface.c_str());
}

void ARS408_CAN::Radar_cfg()
{
    while(Radar_cfg_can_send()==false){
	               if (Radar_cfg_can_send()==true){
	                        break;
	               }
	               printf("Radar继续配置.\n");
	               sleep(1);
	         }
	         
	         printf("Radar配置完成.\n");
	         return;
}

bool ARS408_CAN::Radar_cfg_can_send()
{
    radar_200.DATA0.bit.RadarCfg_MaxDistance_Valid = 1;//允许配置最大距离
    radar_200.DATA0.bit.RadarCfg_SensorID_Valid    = 1;//允许配置radarID
    radar_200.DATA0.bit.RadarCfg_RadarPower_Valid  = 1;//允许配置radar功率
    radar_200.DATA0.bit.RadarCfg_OutputType_Valid  = 1;//允许配置radar输出模式
    radar_200.DATA0.bit.RadarCfg_SendQuality_Valid = 1;//允许配置radar输出cluster和object的质量信息
    radar_200.DATA0.bit.RadarCfg_SendExtInfo_Valid = 1;//允许配置radar输出object的扩展信息
    radar_200.DATA0.bit.RadarCfg_SortIndex_Valid   = 1;//Object目标列表的当前排序索引值配置
    radar_200.DATA0.bit.RadarCfg_StoreInNVM_Valid  = 1;//使能；+++++++++++++++++++++++++++++++++
    //radar相关参数配置
    //最大距离设置
    radar_200.DATA12.bit.RadarCfg_MaxDistance = ((150 - 0)/2);//150为真实物理值：150m
    radar_200.DATA12.bit.reserved             =0;
    //保留位
    radar_200.DATA3.bit.reserved              =0;
    //设置radarID，输出类型，radar功率
    radar_200.DATA4.bit.RadarCfg_sensorID   = (0-0)/1;//radarID：为0
    radar_200.DATA4.bit.RadarCfg_OutputType =(1-0)/1;//object模式
    radar_200.DATA4.bit.RadarCfg_RadarPower =(1-0)/1;//标准发射功率
    //
    radar_200.DATA5.bit.RadarCfg_CtrlRelay_Valid = 0;
    radar_200.DATA5.bit.RadarCfg_CtrlRelay       = 0;
    radar_200.DATA5.bit.RadarCfg_SendQuality     = 1;
    radar_200.DATA5.bit.RadarCfg_SendExtInfo     = 1;
    radar_200.DATA5.bit.RadarCfg_SortIndex       = 1;//按距离排序输出
    radar_200.DATA5.bit.RadarCfg_StoreInNVM      = 1;//使能；+++++++++++++++++++++++++++++++++
    //
    radar_200.DATA6.bit.RadarCfg_RCS_threshold_Valid   = 1;
    radar_200.DATA6.bit.RadarCfg_RCS_threshold         = 0;//标准灵敏度
    radar_200.DATA6.bit.RadarCfg_InvalidClusters_Valid = 0;
    radar_200.DATA6.bit.reserved                       = 0;
    //
    radar_200.DATA7.bit.RadarCfg_InvalidClusters       = 0;

    // 准备 SocketCAN 帧
    struct can_frame frame;
    frame.can_id = 0x200;
    frame.can_dlc = 8;
    frame.data[0] = radar_200.DATA0.D;
    frame.data[1] = radar_200.DATA12.D >> 8;
    frame.data[2] = radar_200.DATA12.D;
    frame.data[3] = radar_200.DATA3.D;
    frame.data[4] = radar_200.DATA4.D;
    frame.data[5] = radar_200.DATA5.D;
    frame.data[6] = radar_200.DATA6.D;
    frame.data[7] = radar_200.DATA7.D;

    // 发送配置帧
    if (write(can_socket_, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        RCLCPP_ERROR(this->get_logger(), "Error sending CAN frame 0x200");
        return false;
    }

    //radar过滤器配置----------
    //过滤器使能
    radar_202.DATA0.bit.reserved         = 0;
    radar_202.DATA0.bit.FilterCfg_Valid  = 1;//使能过滤器  
    radar_202.DATA0.bit.FilterCfg_Active = 1;//激活过滤器
    radar_202.DATA0.bit.FilterCfg_Index  = 0x9;//筛选y方向的距离用过滤条件为:0x9(长度为12bit),0x5为
    radar_202.DATA0.bit.FilterCfg_Type   = 1;//object过滤器
    //最小距离设置
    radar_202.DATA12.bit.FilterCfg_Min_X =(-2 + 409.5)/0.2;//车头右边1.8米以外的目标筛选掉
    radar_202.DATA12.bit.reserved        = 0;
    //最大距离设置   
    radar_202.DATA34.bit.FilterCfg_Max_X =(2 + 409.5)/0.2;//车头左边1.8米以外的目标筛选掉
    radar_202.DATA34.bit.reserved        = 0;
    //
    radar_202.DATA5.bit.reserved = 0;
    radar_202.DATA6.bit.reserved = 0;
    radar_202.DATA7.bit.reserved = 0;
    
    // 准备过滤器配置帧
    frame.can_id = 0x202;
    frame.can_dlc = 8;
    frame.data[0] = radar_202.DATA0.D;
    frame.data[1] = radar_202.DATA12.D >> 8;
    frame.data[2] = radar_202.DATA12.D;
    frame.data[3] = radar_202.DATA34.D >> 8;
    frame.data[4] = radar_202.DATA34.D;
    frame.data[5] = radar_202.DATA5.D;
    frame.data[6] = radar_202.DATA6.D;
    frame.data[7] = radar_202.DATA7.D;
       
    if (write(can_socket_, &frame, sizeof(struct can_frame)) != sizeof(struct can_frame)) {
        RCLCPP_ERROR(this->get_logger(), "Error sending CAN frame 0x202");
        return false;
    }
    
    RCLCPP_INFO(this->get_logger(), "Radar configuration sent successfully");
    return true;
}


void ARS408_CAN::ReceiveDate()
{
    radar_rec_thread_ = std::thread(&ARS408_CAN::ARS408_Analyze_func, this);
    usleep(100000);
    radar_rec_thread_.join();  //线程阻塞，让调用线程等待子线程执行完毕，然后再往下执行

    usleep(100000);
    close(can_socket_);  // 关闭 SocketCAN
    RCLCPP_INFO(this->get_logger(), "SocketCAN closed");
}

void ARS408_CAN::ARS408_Analyze_func()
{
    struct can_frame frame;
    
    while(1)
    {
        int nbytes = read(can_socket_, &frame, sizeof(struct can_frame));
        
        if (nbytes < 0) {
            RCLCPP_ERROR(this->get_logger(), "CAN raw socket read error");
            continue;
        }
        
        if (nbytes < sizeof(struct can_frame)) {
            RCLCPP_WARN(this->get_logger(), "Incomplete CAN frame");
            continue;
        }
        
        // 处理接收到的 CAN 帧
        if(frame.can_id == 0x60b || frame.can_id == 0x60d) 
        {   
            // 清空之前的数据
            static bool is_first_frame_of_cycle = true;
            if (frame.can_id == 0x60b && is_first_frame_of_cycle) {
                radar_datas.tracks.clear();
                is_first_frame_of_cycle = false;
            }
            
            if(frame.can_id == 0x60b)
            {   
                printf("%#x in \n", frame.can_id);
                radar_60b.DATA0.D  = frame.data[0];
                radar_60b.DATA12.D = (frame.data[1] << 8) + frame.data[2];
                radar_60b.DATA23.D = (frame.data[2] << 8) + frame.data[3];
                radar_60b.DATA45.D = (frame.data[4] << 8) + frame.data[5];
                radar_60b.DATA56.D = (frame.data[5] << 8) + frame.data[6];

                radar_datas.header.stamp = this->now();
                radar_datas.header.frame_id = "radar_frame";
                radar_data.uuid.uuid[0] = radar_60b.DATA0.bit.obj_id;
                radar_data.position.x = radar_60b.DATA12.bit.obj_long*0.2 - 500;
                radar_data.position.y = radar_60b.DATA23.bit.obj_lat*0.2 - 204.6;
                radar_data.velocity.x = radar_60b.DATA45.bit.obj_vlong*0.25 - 128;
                radar_data.velocity.y = radar_60b.DATA56.bit.obj_vlat*0.25 - 64;

                radar_datas.tracks.push_back(radar_data);

            }else{
                printf("%#x in \n", frame.can_id);
                radar_60d.DATA0.D = frame.data[0];
                radar_60d.DATA12.D = (frame.data[1] << 8) + frame.data[2];
                radar_60d.DATA23.D = (frame.data[2] << 8) + frame.data[3];
                radar_60d.DATA45.D = (frame.data[4] << 8) + frame.data[5];
                radar_60d.DATA6.D = frame.data[6];
                radar_60d.DATA7.D = frame.data[7];

                radar_datas.header.stamp = this->now();
                radar_datas.header.frame_id = "radar_frame";
                radar_data.uuid.uuid[0] = radar_60d.DATA0.bit.obj_id;
                radar_data.size.x = radar_60d.DATA7.bit.obj_width*0.2;
                radar_data.size.y = radar_60d.DATA6.bit.obj_length*0.2;
                radar_datas.tracks.push_back(radar_data);
                is_first_frame_of_cycle = true; // 准备下一个周期
            }
            
            // 发布雷达数据
            pub_objects_->publish(radar_datas);
            
            // 创建并发布Marker可视化
            visualization_msgs::msg::MarkerArray marker_array;
            for (size_t i = 0; i < radar_datas.tracks.size(); i++) {
                const auto& track = radar_datas.tracks[i];
                
                // 创建立方体Marker
                visualization_msgs::msg::Marker marker;
                marker.header = radar_datas.header;
                marker.ns = "radar_objects";
                marker.id = i;
                marker.type = visualization_msgs::msg::Marker::CUBE;
                marker.action = visualization_msgs::msg::Marker::ADD;
                
                marker.pose.position.x = track.position.x;
                marker.pose.position.y = track.position.y;
                marker.pose.position.z = 0.0;
                marker.pose.orientation.w = 1.0;
                
                marker.scale.x = track.size.x > 0.1 ? track.size.x : 1.0;
                marker.scale.y = track.size.y > 0.1 ? track.size.y : 1.0;
                marker.scale.z = 1.0;
                
                marker.color.r = 1.0;
                marker.color.g = 0.0;
                marker.color.b = 0.0;
                marker.color.a = 0.7;
                
                marker.lifetime = rclcpp::Duration::from_seconds(0.5);
                
                marker_array.markers.push_back(marker);
                
                // 添加速度箭头
                visualization_msgs::msg::Marker arrow;
                arrow.header = radar_datas.header;
                arrow.ns = "radar_velocity";
                arrow.id = i + 1000;
                arrow.type = visualization_msgs::msg::Marker::ARROW;
                arrow.action = visualization_msgs::msg::Marker::ADD;
                
                arrow.points.resize(2);
                arrow.points[0].x = track.position.x;
                arrow.points[0].y = track.position.y;
                arrow.points[0].z = 0.5;
                arrow.points[1].x = track.position.x + track.velocity.x;
                arrow.points[1].y = track.position.y + track.velocity.y;
                arrow.points[1].z = 0.5;
                
                arrow.scale.x = 0.1;
                arrow.scale.y = 0.2;
                arrow.scale.z = 0.0;
                
                arrow.color.r = 0.0;
                arrow.color.g = 1.0;
                arrow.color.b = 0.0;
                arrow.color.a = 0.8;
                
                arrow.lifetime = rclcpp::Duration::from_seconds(0.5);
                
                marker_array.markers.push_back(arrow);
            }
            
            pub_markers_->publish(marker_array);
        }
        
        usleep(out_hz_);

        if(!(rclcpp::ok())){
            break;
        }
    }
}

// ARS408_CAN::~ARS408_CAN();