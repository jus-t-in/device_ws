// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "miivii_gmsl_camera/msg/detail/miivii_time__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace miivii_gmsl_camera
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void MiiviiTime_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) miivii_gmsl_camera::msg::MiiviiTime(_init);
}

void MiiviiTime_fini_function(void * message_memory)
{
  auto typed_message = static_cast<miivii_gmsl_camera::msg::MiiviiTime *>(message_memory);
  typed_message->~MiiviiTime();
}

size_t size_function__MiiviiTime__nodes(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MiiviiTime__nodes(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__MiiviiTime__nodes(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__MiiviiTime__nodes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__MiiviiTime__nodes(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__MiiviiTime__nodes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__MiiviiTime__nodes(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__MiiviiTime__nodes(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MiiviiTime__jitter(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MiiviiTime__jitter(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  return &member[index];
}

void * get_function__MiiviiTime__jitter(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  return &member[index];
}

void fetch_function__MiiviiTime__jitter(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const builtin_interfaces::msg::Duration *>(
    get_const_function__MiiviiTime__jitter(untyped_member, index));
  auto & value = *reinterpret_cast<builtin_interfaces::msg::Duration *>(untyped_value);
  value = item;
}

void assign_function__MiiviiTime__jitter(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<builtin_interfaces::msg::Duration *>(
    get_function__MiiviiTime__jitter(untyped_member, index));
  const auto & value = *reinterpret_cast<const builtin_interfaces::msg::Duration *>(untyped_value);
  item = value;
}

void resize_function__MiiviiTime__jitter(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  member->resize(size);
}

size_t size_function__MiiviiTime__latency(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MiiviiTime__latency(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  return &member[index];
}

void * get_function__MiiviiTime__latency(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  return &member[index];
}

void fetch_function__MiiviiTime__latency(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const builtin_interfaces::msg::Duration *>(
    get_const_function__MiiviiTime__latency(untyped_member, index));
  auto & value = *reinterpret_cast<builtin_interfaces::msg::Duration *>(untyped_value);
  value = item;
}

void assign_function__MiiviiTime__latency(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<builtin_interfaces::msg::Duration *>(
    get_function__MiiviiTime__latency(untyped_member, index));
  const auto & value = *reinterpret_cast<const builtin_interfaces::msg::Duration *>(untyped_value);
  item = value;
}

void resize_function__MiiviiTime__latency(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<builtin_interfaces::msg::Duration> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MiiviiTime_message_member_array[4] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera::msg::MiiviiTime, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "nodes",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera::msg::MiiviiTime, nodes),  // bytes offset in struct
    nullptr,  // default value
    size_function__MiiviiTime__nodes,  // size() function pointer
    get_const_function__MiiviiTime__nodes,  // get_const(index) function pointer
    get_function__MiiviiTime__nodes,  // get(index) function pointer
    fetch_function__MiiviiTime__nodes,  // fetch(index, &value) function pointer
    assign_function__MiiviiTime__nodes,  // assign(index, value) function pointer
    resize_function__MiiviiTime__nodes  // resize(index) function pointer
  },
  {
    "jitter",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Duration>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera::msg::MiiviiTime, jitter),  // bytes offset in struct
    nullptr,  // default value
    size_function__MiiviiTime__jitter,  // size() function pointer
    get_const_function__MiiviiTime__jitter,  // get_const(index) function pointer
    get_function__MiiviiTime__jitter,  // get(index) function pointer
    fetch_function__MiiviiTime__jitter,  // fetch(index, &value) function pointer
    assign_function__MiiviiTime__jitter,  // assign(index, value) function pointer
    resize_function__MiiviiTime__jitter  // resize(index) function pointer
  },
  {
    "latency",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<builtin_interfaces::msg::Duration>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera::msg::MiiviiTime, latency),  // bytes offset in struct
    nullptr,  // default value
    size_function__MiiviiTime__latency,  // size() function pointer
    get_const_function__MiiviiTime__latency,  // get_const(index) function pointer
    get_function__MiiviiTime__latency,  // get(index) function pointer
    fetch_function__MiiviiTime__latency,  // fetch(index, &value) function pointer
    assign_function__MiiviiTime__latency,  // assign(index, value) function pointer
    resize_function__MiiviiTime__latency  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MiiviiTime_message_members = {
  "miivii_gmsl_camera::msg",  // message namespace
  "MiiviiTime",  // message name
  4,  // number of fields
  sizeof(miivii_gmsl_camera::msg::MiiviiTime),
  MiiviiTime_message_member_array,  // message members
  MiiviiTime_init_function,  // function to initialize message memory (memory has to be allocated)
  MiiviiTime_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MiiviiTime_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MiiviiTime_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace miivii_gmsl_camera


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<miivii_gmsl_camera::msg::MiiviiTime>()
{
  return &::miivii_gmsl_camera::msg::rosidl_typesupport_introspection_cpp::MiiviiTime_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, miivii_gmsl_camera, msg, MiiviiTime)() {
  return &::miivii_gmsl_camera::msg::rosidl_typesupport_introspection_cpp::MiiviiTime_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
