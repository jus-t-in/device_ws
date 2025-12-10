// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice

#ifndef MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__BUILDER_HPP_
#define MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "miivii_gmsl_camera/msg/detail/miivii_time__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace miivii_gmsl_camera
{

namespace msg
{

namespace builder
{

class Init_MiiviiTime_latency
{
public:
  explicit Init_MiiviiTime_latency(::miivii_gmsl_camera::msg::MiiviiTime & msg)
  : msg_(msg)
  {}
  ::miivii_gmsl_camera::msg::MiiviiTime latency(::miivii_gmsl_camera::msg::MiiviiTime::_latency_type arg)
  {
    msg_.latency = std::move(arg);
    return std::move(msg_);
  }

private:
  ::miivii_gmsl_camera::msg::MiiviiTime msg_;
};

class Init_MiiviiTime_jitter
{
public:
  explicit Init_MiiviiTime_jitter(::miivii_gmsl_camera::msg::MiiviiTime & msg)
  : msg_(msg)
  {}
  Init_MiiviiTime_latency jitter(::miivii_gmsl_camera::msg::MiiviiTime::_jitter_type arg)
  {
    msg_.jitter = std::move(arg);
    return Init_MiiviiTime_latency(msg_);
  }

private:
  ::miivii_gmsl_camera::msg::MiiviiTime msg_;
};

class Init_MiiviiTime_nodes
{
public:
  explicit Init_MiiviiTime_nodes(::miivii_gmsl_camera::msg::MiiviiTime & msg)
  : msg_(msg)
  {}
  Init_MiiviiTime_jitter nodes(::miivii_gmsl_camera::msg::MiiviiTime::_nodes_type arg)
  {
    msg_.nodes = std::move(arg);
    return Init_MiiviiTime_jitter(msg_);
  }

private:
  ::miivii_gmsl_camera::msg::MiiviiTime msg_;
};

class Init_MiiviiTime_header
{
public:
  Init_MiiviiTime_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MiiviiTime_nodes header(::miivii_gmsl_camera::msg::MiiviiTime::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MiiviiTime_nodes(msg_);
  }

private:
  ::miivii_gmsl_camera::msg::MiiviiTime msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::miivii_gmsl_camera::msg::MiiviiTime>()
{
  return miivii_gmsl_camera::msg::builder::Init_MiiviiTime_header();
}

}  // namespace miivii_gmsl_camera

#endif  // MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__BUILDER_HPP_
