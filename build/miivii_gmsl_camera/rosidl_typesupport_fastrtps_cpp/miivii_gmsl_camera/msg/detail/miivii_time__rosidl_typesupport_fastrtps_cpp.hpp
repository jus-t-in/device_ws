// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice

#ifndef MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "miivii_gmsl_camera/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "miivii_gmsl_camera/msg/detail/miivii_time__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace miivii_gmsl_camera
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_miivii_gmsl_camera
cdr_serialize(
  const miivii_gmsl_camera::msg::MiiviiTime & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_miivii_gmsl_camera
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  miivii_gmsl_camera::msg::MiiviiTime & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_miivii_gmsl_camera
get_serialized_size(
  const miivii_gmsl_camera::msg::MiiviiTime & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_miivii_gmsl_camera
max_serialized_size_MiiviiTime(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace miivii_gmsl_camera

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_miivii_gmsl_camera
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, miivii_gmsl_camera, msg, MiiviiTime)();

#ifdef __cplusplus
}
#endif

#endif  // MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
