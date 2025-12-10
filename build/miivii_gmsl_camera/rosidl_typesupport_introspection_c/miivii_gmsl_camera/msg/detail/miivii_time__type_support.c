// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "miivii_gmsl_camera/msg/detail/miivii_time__rosidl_typesupport_introspection_c.h"
#include "miivii_gmsl_camera/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "miivii_gmsl_camera/msg/detail/miivii_time__functions.h"
#include "miivii_gmsl_camera/msg/detail/miivii_time__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `nodes`
#include "rosidl_runtime_c/string_functions.h"
// Member `jitter`
// Member `latency`
#include "builtin_interfaces/msg/duration.h"
// Member `jitter`
// Member `latency`
#include "builtin_interfaces/msg/detail/duration__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  miivii_gmsl_camera__msg__MiiviiTime__init(message_memory);
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_fini_function(void * message_memory)
{
  miivii_gmsl_camera__msg__MiiviiTime__fini(message_memory);
}

size_t miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__size_function__MiiviiTime__nodes(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__nodes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__nodes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__fetch_function__MiiviiTime__nodes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__nodes(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__assign_function__MiiviiTime__nodes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__nodes(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__resize_function__MiiviiTime__nodes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__size_function__MiiviiTime__jitter(
  const void * untyped_member)
{
  const builtin_interfaces__msg__Duration__Sequence * member =
    (const builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  return member->size;
}

const void * miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__jitter(
  const void * untyped_member, size_t index)
{
  const builtin_interfaces__msg__Duration__Sequence * member =
    (const builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  return &member->data[index];
}

void * miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__jitter(
  void * untyped_member, size_t index)
{
  builtin_interfaces__msg__Duration__Sequence * member =
    (builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  return &member->data[index];
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__fetch_function__MiiviiTime__jitter(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const builtin_interfaces__msg__Duration * item =
    ((const builtin_interfaces__msg__Duration *)
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__jitter(untyped_member, index));
  builtin_interfaces__msg__Duration * value =
    (builtin_interfaces__msg__Duration *)(untyped_value);
  *value = *item;
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__assign_function__MiiviiTime__jitter(
  void * untyped_member, size_t index, const void * untyped_value)
{
  builtin_interfaces__msg__Duration * item =
    ((builtin_interfaces__msg__Duration *)
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__jitter(untyped_member, index));
  const builtin_interfaces__msg__Duration * value =
    (const builtin_interfaces__msg__Duration *)(untyped_value);
  *item = *value;
}

bool miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__resize_function__MiiviiTime__jitter(
  void * untyped_member, size_t size)
{
  builtin_interfaces__msg__Duration__Sequence * member =
    (builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  builtin_interfaces__msg__Duration__Sequence__fini(member);
  return builtin_interfaces__msg__Duration__Sequence__init(member, size);
}

size_t miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__size_function__MiiviiTime__latency(
  const void * untyped_member)
{
  const builtin_interfaces__msg__Duration__Sequence * member =
    (const builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  return member->size;
}

const void * miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__latency(
  const void * untyped_member, size_t index)
{
  const builtin_interfaces__msg__Duration__Sequence * member =
    (const builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  return &member->data[index];
}

void * miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__latency(
  void * untyped_member, size_t index)
{
  builtin_interfaces__msg__Duration__Sequence * member =
    (builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  return &member->data[index];
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__fetch_function__MiiviiTime__latency(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const builtin_interfaces__msg__Duration * item =
    ((const builtin_interfaces__msg__Duration *)
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__latency(untyped_member, index));
  builtin_interfaces__msg__Duration * value =
    (builtin_interfaces__msg__Duration *)(untyped_value);
  *value = *item;
}

void miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__assign_function__MiiviiTime__latency(
  void * untyped_member, size_t index, const void * untyped_value)
{
  builtin_interfaces__msg__Duration * item =
    ((builtin_interfaces__msg__Duration *)
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__latency(untyped_member, index));
  const builtin_interfaces__msg__Duration * value =
    (const builtin_interfaces__msg__Duration *)(untyped_value);
  *item = *value;
}

bool miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__resize_function__MiiviiTime__latency(
  void * untyped_member, size_t size)
{
  builtin_interfaces__msg__Duration__Sequence * member =
    (builtin_interfaces__msg__Duration__Sequence *)(untyped_member);
  builtin_interfaces__msg__Duration__Sequence__fini(member);
  return builtin_interfaces__msg__Duration__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera__msg__MiiviiTime, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "nodes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera__msg__MiiviiTime, nodes),  // bytes offset in struct
    NULL,  // default value
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__size_function__MiiviiTime__nodes,  // size() function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__nodes,  // get_const(index) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__nodes,  // get(index) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__fetch_function__MiiviiTime__nodes,  // fetch(index, &value) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__assign_function__MiiviiTime__nodes,  // assign(index, value) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__resize_function__MiiviiTime__nodes  // resize(index) function pointer
  },
  {
    "jitter",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera__msg__MiiviiTime, jitter),  // bytes offset in struct
    NULL,  // default value
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__size_function__MiiviiTime__jitter,  // size() function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__jitter,  // get_const(index) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__jitter,  // get(index) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__fetch_function__MiiviiTime__jitter,  // fetch(index, &value) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__assign_function__MiiviiTime__jitter,  // assign(index, value) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__resize_function__MiiviiTime__jitter  // resize(index) function pointer
  },
  {
    "latency",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(miivii_gmsl_camera__msg__MiiviiTime, latency),  // bytes offset in struct
    NULL,  // default value
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__size_function__MiiviiTime__latency,  // size() function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_const_function__MiiviiTime__latency,  // get_const(index) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__get_function__MiiviiTime__latency,  // get(index) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__fetch_function__MiiviiTime__latency,  // fetch(index, &value) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__assign_function__MiiviiTime__latency,  // assign(index, value) function pointer
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__resize_function__MiiviiTime__latency  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_members = {
  "miivii_gmsl_camera__msg",  // message namespace
  "MiiviiTime",  // message name
  4,  // number of fields
  sizeof(miivii_gmsl_camera__msg__MiiviiTime),
  miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_member_array,  // message members
  miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_init_function,  // function to initialize message memory (memory has to be allocated)
  miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_type_support_handle = {
  0,
  &miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_miivii_gmsl_camera
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, miivii_gmsl_camera, msg, MiiviiTime)() {
  miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Duration)();
  if (!miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_type_support_handle.typesupport_identifier) {
    miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &miivii_gmsl_camera__msg__MiiviiTime__rosidl_typesupport_introspection_c__MiiviiTime_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
