#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "fun::fun_objects" for configuration "Release"
set_property(TARGET fun::fun_objects APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(fun::fun_objects PROPERTIES
  IMPORTED_COMMON_LANGUAGE_RUNTIME_RELEASE ""
  IMPORTED_OBJECTS_RELEASE "${_IMPORT_PREFIX}/fun_ert_rtw/objects-Release/fun_objects/fun.cpp.obj"
  )

list(APPEND _cmake_import_check_targets fun::fun_objects )
list(APPEND _cmake_import_check_files_for_fun::fun_objects "${_IMPORT_PREFIX}/fun_ert_rtw/objects-Release/fun_objects/fun.cpp.obj" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
