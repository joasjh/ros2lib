// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from example_interfaces:msg\ByteMultiArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "example_interfaces/msg/detail/byte_multi_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace example_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void ByteMultiArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) example_interfaces::msg::ByteMultiArray(_init);
}

void ByteMultiArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<example_interfaces::msg::ByteMultiArray *>(message_memory);
  typed_message->~ByteMultiArray();
}

size_t size_function__ByteMultiArray__data(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<unsigned char> *>(untyped_member);
  return member->size();
}

const void * get_const_function__ByteMultiArray__data(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<unsigned char> *>(untyped_member);
  return &member[index];
}

void * get_function__ByteMultiArray__data(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<unsigned char> *>(untyped_member);
  return &member[index];
}

void fetch_function__ByteMultiArray__data(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const unsigned char *>(
    get_const_function__ByteMultiArray__data(untyped_member, index));
  auto & value = *reinterpret_cast<unsigned char *>(untyped_value);
  value = item;
}

void assign_function__ByteMultiArray__data(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<unsigned char *>(
    get_function__ByteMultiArray__data(untyped_member, index));
  const auto & value = *reinterpret_cast<const unsigned char *>(untyped_value);
  item = value;
}

void resize_function__ByteMultiArray__data(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<unsigned char> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember ByteMultiArray_message_member_array[2] = {
  {
    "layout",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<example_interfaces::msg::MultiArrayLayout>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(example_interfaces::msg::ByteMultiArray, layout),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "data",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_OCTET,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(example_interfaces::msg::ByteMultiArray, data),  // bytes offset in struct
    nullptr,  // default value
    size_function__ByteMultiArray__data,  // size() function pointer
    get_const_function__ByteMultiArray__data,  // get_const(index) function pointer
    get_function__ByteMultiArray__data,  // get(index) function pointer
    fetch_function__ByteMultiArray__data,  // fetch(index, &value) function pointer
    assign_function__ByteMultiArray__data,  // assign(index, value) function pointer
    resize_function__ByteMultiArray__data  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers ByteMultiArray_message_members = {
  "example_interfaces::msg",  // message namespace
  "ByteMultiArray",  // message name
  2,  // number of fields
  sizeof(example_interfaces::msg::ByteMultiArray),
  ByteMultiArray_message_member_array,  // message members
  ByteMultiArray_init_function,  // function to initialize message memory (memory has to be allocated)
  ByteMultiArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t ByteMultiArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &ByteMultiArray_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace example_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<example_interfaces::msg::ByteMultiArray>()
{
  return &::example_interfaces::msg::rosidl_typesupport_introspection_cpp::ByteMultiArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, example_interfaces, msg, ByteMultiArray)() {
  return &::example_interfaces::msg::rosidl_typesupport_introspection_cpp::ByteMultiArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
