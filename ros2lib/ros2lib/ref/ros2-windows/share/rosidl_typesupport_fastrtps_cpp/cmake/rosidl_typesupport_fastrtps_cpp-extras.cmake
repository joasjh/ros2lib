# generated from
# rosidl_typesupport_fastrtps_cpp/
#   rosidl_typesupport_fastrtps_cpp-extras.cmake.in

find_package(fastrtps_cmake_module QUIET)
find_package(fastcdr REQUIRED CONFIG)

if(NOT fastcdr_FOUND)
  message(STATUS
    "Could not find eProsima Fast CDR - skip rosidl_typesupport_fastrtps_cpp"
  )
else()
  find_package(ament_cmake_core QUIET REQUIRED)

  # This generator generates code dependent on code generated by rosidl_generator_cpp
  # Find it first so it registers it's extensions first
  find_package(rosidl_generator_cpp REQUIRED)

  ament_register_extension(
    "rosidl_generate_idl_interfaces"
    "rosidl_typesupport_fastrtps_cpp"
    "rosidl_typesupport_fastrtps_cpp_generate_interfaces.cmake")

  set(rosidl_typesupport_fastrtps_cpp_BIN
    "${rosidl_typesupport_fastrtps_cpp_DIR}/../../../lib/rosidl_typesupport_fastrtps_cpp/rosidl_typesupport_fastrtps_cpp")
  normalize_path(rosidl_typesupport_fastrtps_cpp_BIN
    "${rosidl_typesupport_fastrtps_cpp_BIN}")

  set(rosidl_typesupport_fastrtps_cpp_GENERATOR_FILES
    "${rosidl_typesupport_fastrtps_cpp_DIR}/../../../Lib/site-packages/rosidl_typesupport_fastrtps_cpp/__init__.py")
  normalize_path(rosidl_typesupport_fastrtps_cpp_GENERATOR_FILES
    "${rosidl_typesupport_fastrtps_cpp_GENERATOR_FILES}")

  set(rosidl_typesupport_fastrtps_cpp_TEMPLATE_DIR
    "${rosidl_typesupport_fastrtps_cpp_DIR}/../resource")
  normalize_path(rosidl_typesupport_fastrtps_cpp_TEMPLATE_DIR
    "${rosidl_typesupport_fastrtps_cpp_TEMPLATE_DIR}")
endif()
