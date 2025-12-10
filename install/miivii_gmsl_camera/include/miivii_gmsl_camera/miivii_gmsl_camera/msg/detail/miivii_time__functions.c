// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from miivii_gmsl_camera:msg/MiiviiTime.idl
// generated code does not contain a copyright notice
#include "miivii_gmsl_camera/msg/detail/miivii_time__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `nodes`
#include "rosidl_runtime_c/string_functions.h"
// Member `jitter`
// Member `latency`
#include "builtin_interfaces/msg/detail/duration__functions.h"

bool
miivii_gmsl_camera__msg__MiiviiTime__init(miivii_gmsl_camera__msg__MiiviiTime * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    miivii_gmsl_camera__msg__MiiviiTime__fini(msg);
    return false;
  }
  // nodes
  if (!rosidl_runtime_c__String__Sequence__init(&msg->nodes, 0)) {
    miivii_gmsl_camera__msg__MiiviiTime__fini(msg);
    return false;
  }
  // jitter
  if (!builtin_interfaces__msg__Duration__Sequence__init(&msg->jitter, 0)) {
    miivii_gmsl_camera__msg__MiiviiTime__fini(msg);
    return false;
  }
  // latency
  if (!builtin_interfaces__msg__Duration__Sequence__init(&msg->latency, 0)) {
    miivii_gmsl_camera__msg__MiiviiTime__fini(msg);
    return false;
  }
  return true;
}

void
miivii_gmsl_camera__msg__MiiviiTime__fini(miivii_gmsl_camera__msg__MiiviiTime * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // nodes
  rosidl_runtime_c__String__Sequence__fini(&msg->nodes);
  // jitter
  builtin_interfaces__msg__Duration__Sequence__fini(&msg->jitter);
  // latency
  builtin_interfaces__msg__Duration__Sequence__fini(&msg->latency);
}

bool
miivii_gmsl_camera__msg__MiiviiTime__are_equal(const miivii_gmsl_camera__msg__MiiviiTime * lhs, const miivii_gmsl_camera__msg__MiiviiTime * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // nodes
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->nodes), &(rhs->nodes)))
  {
    return false;
  }
  // jitter
  if (!builtin_interfaces__msg__Duration__Sequence__are_equal(
      &(lhs->jitter), &(rhs->jitter)))
  {
    return false;
  }
  // latency
  if (!builtin_interfaces__msg__Duration__Sequence__are_equal(
      &(lhs->latency), &(rhs->latency)))
  {
    return false;
  }
  return true;
}

bool
miivii_gmsl_camera__msg__MiiviiTime__copy(
  const miivii_gmsl_camera__msg__MiiviiTime * input,
  miivii_gmsl_camera__msg__MiiviiTime * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // nodes
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->nodes), &(output->nodes)))
  {
    return false;
  }
  // jitter
  if (!builtin_interfaces__msg__Duration__Sequence__copy(
      &(input->jitter), &(output->jitter)))
  {
    return false;
  }
  // latency
  if (!builtin_interfaces__msg__Duration__Sequence__copy(
      &(input->latency), &(output->latency)))
  {
    return false;
  }
  return true;
}

miivii_gmsl_camera__msg__MiiviiTime *
miivii_gmsl_camera__msg__MiiviiTime__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  miivii_gmsl_camera__msg__MiiviiTime * msg = (miivii_gmsl_camera__msg__MiiviiTime *)allocator.allocate(sizeof(miivii_gmsl_camera__msg__MiiviiTime), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(miivii_gmsl_camera__msg__MiiviiTime));
  bool success = miivii_gmsl_camera__msg__MiiviiTime__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
miivii_gmsl_camera__msg__MiiviiTime__destroy(miivii_gmsl_camera__msg__MiiviiTime * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    miivii_gmsl_camera__msg__MiiviiTime__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
miivii_gmsl_camera__msg__MiiviiTime__Sequence__init(miivii_gmsl_camera__msg__MiiviiTime__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  miivii_gmsl_camera__msg__MiiviiTime * data = NULL;

  if (size) {
    data = (miivii_gmsl_camera__msg__MiiviiTime *)allocator.zero_allocate(size, sizeof(miivii_gmsl_camera__msg__MiiviiTime), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = miivii_gmsl_camera__msg__MiiviiTime__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        miivii_gmsl_camera__msg__MiiviiTime__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
miivii_gmsl_camera__msg__MiiviiTime__Sequence__fini(miivii_gmsl_camera__msg__MiiviiTime__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      miivii_gmsl_camera__msg__MiiviiTime__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

miivii_gmsl_camera__msg__MiiviiTime__Sequence *
miivii_gmsl_camera__msg__MiiviiTime__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  miivii_gmsl_camera__msg__MiiviiTime__Sequence * array = (miivii_gmsl_camera__msg__MiiviiTime__Sequence *)allocator.allocate(sizeof(miivii_gmsl_camera__msg__MiiviiTime__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = miivii_gmsl_camera__msg__MiiviiTime__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
miivii_gmsl_camera__msg__MiiviiTime__Sequence__destroy(miivii_gmsl_camera__msg__MiiviiTime__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    miivii_gmsl_camera__msg__MiiviiTime__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
miivii_gmsl_camera__msg__MiiviiTime__Sequence__are_equal(const miivii_gmsl_camera__msg__MiiviiTime__Sequence * lhs, const miivii_gmsl_camera__msg__MiiviiTime__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!miivii_gmsl_camera__msg__MiiviiTime__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
miivii_gmsl_camera__msg__MiiviiTime__Sequence__copy(
  const miivii_gmsl_camera__msg__MiiviiTime__Sequence * input,
  miivii_gmsl_camera__msg__MiiviiTime__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(miivii_gmsl_camera__msg__MiiviiTime);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    miivii_gmsl_camera__msg__MiiviiTime * data =
      (miivii_gmsl_camera__msg__MiiviiTime *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!miivii_gmsl_camera__msg__MiiviiTime__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          miivii_gmsl_camera__msg__MiiviiTime__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!miivii_gmsl_camera__msg__MiiviiTime__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
