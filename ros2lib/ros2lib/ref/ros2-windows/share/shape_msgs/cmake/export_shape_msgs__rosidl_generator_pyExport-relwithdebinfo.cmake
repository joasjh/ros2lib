#----------------------------------------------------------------
# Generated CMake target import file for configuration "RelWithDebInfo".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "shape_msgs::shape_msgs__rosidl_generator_py" for configuration "RelWithDebInfo"
set_property(TARGET shape_msgs::shape_msgs__rosidl_generator_py APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(shape_msgs::shape_msgs__rosidl_generator_py PROPERTIES
  IMPORTED_IMPLIB_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/shape_msgs__rosidl_generator_py.lib"
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/bin/shape_msgs__rosidl_generator_py.dll"
  )

list(APPEND _cmake_import_check_targets shape_msgs::shape_msgs__rosidl_generator_py )
list(APPEND _cmake_import_check_files_for_shape_msgs::shape_msgs__rosidl_generator_py "${_IMPORT_PREFIX}/lib/shape_msgs__rosidl_generator_py.lib" "${_IMPORT_PREFIX}/bin/shape_msgs__rosidl_generator_py.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)