// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice

#ifndef MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__STRUCT_H_
#define MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'nodes'
#include "rosidl_runtime_c/string.h"
// Member 'jitter'
// Member 'latency'
#include "builtin_interfaces/msg/detail/duration__struct.h"

/// Struct defined in msg/MiiviiTime in the package miivii_gmsl_camera.
typedef struct miivii_gmsl_camera__msg__MiiviiTime
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String__Sequence nodes;
  builtin_interfaces__msg__Duration__Sequence jitter;
  builtin_interfaces__msg__Duration__Sequence latency;
} miivii_gmsl_camera__msg__MiiviiTime;

// Struct for a sequence of miivii_gmsl_camera__msg__MiiviiTime.
typedef struct miivii_gmsl_camera__msg__MiiviiTime__Sequence
{
  miivii_gmsl_camera__msg__MiiviiTime * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} miivii_gmsl_camera__msg__MiiviiTime__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MIIVII_GMSL_CAMERA__MSG__DETAIL__MIIVII_TIME__STRUCT_H_
