#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "diagnostic_msgs::diagnostic_msgs__rosidl_typesupport_c" for configuration "RelWithDebInfo"
set_property(TARGET diagnostic_msgs::diagnostic_msgs__rosidl_typesupport_c APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(diagnostic_msgs::diagnostic_msgs__rosidl_typesupport_c PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/diagnostic_msgs__rosidl_typesupport_c.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELWITHDEBINFO "rosidl_runtime_c::rosidl_runtime_c;rosidl_typesupport_c::rosidl_typesupport_c"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/diagnostic_msgs__rosidl_typesupport_c.dll"
  )

list(APPEND _cmake_import_check_targets diagnostic_msgs::diagnostic_msgs__rosidl_typesupport_c )
list(APPEND _cmake_import_check_files_for_diagnostic_msgs::diagnostic_msgs__rosidl_typesupport_c "${_IMPORT_PREFIX}/lib/diagnostic_msgs__rosidl_typesupport_c.lib" "${_IMPORT_PREFIX}/bin/diagnostic_msgs__rosidl_typesupport_c.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
