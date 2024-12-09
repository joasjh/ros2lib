// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from rosbag2_storage_mcap_testdata:msg\ComplexMsg.idl
// generated code does not contain a copyright notice
#include "rosbag2_storage_mcap_testdata/msg/detail/complex_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `b`
#include "rosbag2_storage_mcap_testdata/msg/detail/basic_msg__functions.h"

bool
rosbag2_storage_mcap_testdata__msg__ComplexMsg__init(rosbag2_storage_mcap_testdata__msg__ComplexMsg * msg)
{
  if (!msg) {
    return false;
  }
  // b
  if (!rosbag2_storage_mcap_testdata__msg__BasicMsg__init(&msg->b)) {
    rosbag2_storage_mcap_testdata__msg__ComplexMsg__fini(msg);
    return false;
  }
  return true;
}

void
rosbag2_storage_mcap_testdata__msg__ComplexMsg__fini(rosbag2_storage_mcap_testdata__msg__ComplexMsg * msg)
{
  if (!msg) {
    return;
  }
  // b
  rosbag2_storage_mcap_testdata__msg__BasicMsg__fini(&msg->b);
}

bool
rosbag2_storage_mcap_testdata__msg__ComplexMsg__are_equal(const rosbag2_storage_mcap_testdata__msg__ComplexMsg * lhs, const rosbag2_storage_mcap_testdata__msg__ComplexMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // b
  if (!rosbag2_storage_mcap_testdata__msg__BasicMsg__are_equal(
      &(lhs->b), &(rhs->b)))
  {
    return false;
  }
  return true;
}

bool
rosbag2_storage_mcap_testdata__msg__ComplexMsg__copy(
  const rosbag2_storage_mcap_testdata__msg__ComplexMsg * input,
  rosbag2_storage_mcap_testdata__msg__ComplexMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // b
  if (!rosbag2_storage_mcap_testdata__msg__BasicMsg__copy(
      &(input->b), &(output->b)))
  {
    return false;
  }
  return true;
}

rosbag2_storage_mcap_testdata__msg__ComplexMsg *
rosbag2_storage_mcap_testdata__msg__ComplexMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_storage_mcap_testdata__msg__ComplexMsg * msg = (rosbag2_storage_mcap_testdata__msg__ComplexMsg *)allocator.allocate(sizeof(rosbag2_storage_mcap_testdata__msg__ComplexMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(rosbag2_storage_mcap_testdata__msg__ComplexMsg));
  bool success = rosbag2_storage_mcap_testdata__msg__ComplexMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
rosbag2_storage_mcap_testdata__msg__ComplexMsg__destroy(rosbag2_storage_mcap_testdata__msg__ComplexMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    rosbag2_storage_mcap_testdata__msg__ComplexMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__init(rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_storage_mcap_testdata__msg__ComplexMsg * data = NULL;

  if (size) {
    data = (rosbag2_storage_mcap_testdata__msg__ComplexMsg *)allocator.zero_allocate(size, sizeof(rosbag2_storage_mcap_testdata__msg__ComplexMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = rosbag2_storage_mcap_testdata__msg__ComplexMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        rosbag2_storage_mcap_testdata__msg__ComplexMsg__fini(&data[i - 1]);
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
rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__fini(rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * array)
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
      rosbag2_storage_mcap_testdata__msg__ComplexMsg__fini(&array->data[i]);
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

rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence *
rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * array = (rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence *)allocator.allocate(sizeof(rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__destroy(rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__are_equal(const rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * lhs, const rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!rosbag2_storage_mcap_testdata__msg__ComplexMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence__copy(
  const rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * input,
  rosbag2_storage_mcap_testdata__msg__ComplexMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(rosbag2_storage_mcap_testdata__msg__ComplexMsg);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    rosbag2_storage_mcap_testdata__msg__ComplexMsg * data =
      (rosbag2_storage_mcap_testdata__msg__ComplexMsg *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!rosbag2_storage_mcap_testdata__msg__ComplexMsg__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          rosbag2_storage_mcap_testdata__msg__ComplexMsg__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!rosbag2_storage_mcap_testdata__msg__ComplexMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
