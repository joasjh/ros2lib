#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "tf2_msgs::tf2_msgs__rosidl_typesupport_cpp" for configuration "RelWithDebInfo"
set_property(TARGET tf2_msgs::tf2_msgs__rosidl_typesupport_cpp APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(tf2_msgs::tf2_msgs__rosidl_typesupport_cpp PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/tf2_msgs__rosidl_typesupport_cpp.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rosidl_runtime_c::rosidl_runtime_c;rosidl_typesupport_cpp::rosidl_typesupport_cpp;rosidl_typesupport_c::rosidl_typesupport_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/tf2_msgs__rosidl_typesupport_cpp.dll"
  )

list(APPEND _cmake_import_check_targets tf2_msgs::tf2_msgs__rosidl_typesupport_cpp )
list(APPEND _cmake_import_check_files_for_tf2_msgs::tf2_msgs__rosidl_typesupport_cpp "${_IMPORT_PREFIX}/lib/tf2_msgs__rosidl_typesupport_cpp.lib" "${_IMPORT_PREFIX}/bin/tf2_msgs__rosidl_typesupport_cpp.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
