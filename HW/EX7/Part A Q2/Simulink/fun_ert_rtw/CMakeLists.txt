###########################################################################
# CMakeLists.txt generated for component fun
# Product type: executable
###########################################################################
cmake_minimum_required(VERSION 3.12)
project(fun)

# Propagate the CMAKE_EXPORT_COMPILE_COMMANDS variable from the 
# environment if it is defined as an environment variable, but not as a 
# CMake variable. This is to work around a bug in CMake 3.19 when the 
# "NMake Makefiles" generator is selected.
if(DEFINED ENV{CMAKE_EXPORT_COMPILE_COMMANDS} AND NOT DEFINED CMAKE_EXPORT_COMPILE_COMMANDS)
    set(CMAKE_EXPORT_COMPILE_COMMANDS $ENV{CMAKE_EXPORT_COMPILE_COMMANDS})
endif()

# Define common variables that are used within the whole project.
set(SYSLIB_PREFIX $<IF:$<AND:$<BOOL:${WIN32}>,$<NOT:$<BOOL:${MINGW}>>>,lib,>)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

###########################################################################
## Path variables
###########################################################################
# Derive an absolute path to the code generation anchor folder.
get_filename_component(START_DIR .. ABSOLUTE)

# Special directories defined by using CACHE variables can be overridden 
# by setting the variable from the command line, e.g.,
# 
# 	cmake . -DMATLAB_ROOT=/path/to/another/matlab/root
set(MATLAB_ROOT D:/Matlab CACHE PATH "")

###########################################################################
## System Libraries
###########################################################################
find_library(FOUND_LIBM m NO_SYSTEM_ENVIRONMENT_PATH PATHS ${CMAKE_C_IMPLICIT_LINK_DIRECTORIES} ${CMAKE_CXX_IMPLICIT_LINK_DIRECTORIES})

###########################################################################
## Target definition and commands
###########################################################################

# When a CMakeLists.txt defines multiple targets that have a common set of 
# tool flags and preprocessor definitions, define variables containing 
# data that is common to all targets defined in the file.
set(FUN_COMMON_DEFINES -DMODEL=fun
    -DNUMST=1
    -DNCSTATES=0
    -DHAVESTDIO
    -DMODEL_HAS_DYNAMICALLY_LOADED_SFCNS=0
    -DCLASSIC_INTERFACE=0
    -DALLOCATIONFCN=0
    -DTID01EQ=0
    -DTERMFCN=1
    -DONESTEPFCN=1
    -DMAT_FILE=0
    -DMULTI_INSTANCE_CODE=1
    -DINTEGER_CODE=0
    -DMT=0)
set(FUN_COMMON_LINKER_FLAGS -static
    -m64)

# Definition of target "fun_objects".
add_library(fun_objects OBJECT ${START_DIR}/fun_ert_rtw/fun.cpp)

# Set properties for target "fun_objects".
set_target_properties(fun_objects PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON)

# Specify language features required for target "fun_objects".
target_compile_features(fun_objects PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target "fun_objects".
target_compile_definitions(fun_objects PRIVATE ${FUN_COMMON_DEFINES})

# Specify include directories for target "fun_objects".
target_include_directories(fun_objects PUBLIC $<BUILD_INTERFACE:${START_DIR}>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>>
    $<BUILD_INTERFACE:${START_DIR}/fun_ert_rtw>
    $<INSTALL_INTERFACE:$<INSTALL_PREFIX>/fun_ert_rtw>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/extern/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/simulink/include>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/src/ext_mode/common>
    $<BUILD_INTERFACE:${MATLAB_ROOT}/rtw/c/ert>)

# Specify linker flags for target "fun_objects".
target_link_libraries(fun_objects PRIVATE ${FUN_COMMON_LINKER_FLAGS})

# Specify library link dependencies for target "fun_objects".  CMake 
# generator expressions are used to create a CMakeLists.txt file that 
# supports multiple platforms with differently named system library 
# dependencies.
target_link_libraries(fun_objects PUBLIC $<$<BOOL:${FOUND_LIBM}>:m>)


# Definition of target "fun".
add_executable(fun  ${START_DIR}/fun_ert_rtw/ert_main.cpp)

# Set properties for target "fun".
set_target_properties(fun PROPERTIES PREFIX ""
    POSITION_INDEPENDENT_CODE ON)

# Specify language features required for target "fun".
target_compile_features(fun PUBLIC cxx_std_11)

# Specify compiler preprocessor definitions for target "fun".
target_compile_definitions(fun PRIVATE ${FUN_COMMON_DEFINES})

# Specify linker flags for target "fun".
target_link_libraries(fun PRIVATE ${FUN_COMMON_LINKER_FLAGS})

# Specify library link dependencies for target "fun".  CMake generator 
# expressions are used to create a CMakeLists.txt file that supports 
# multiple platforms with differently named system library dependencies.
target_link_libraries(fun PRIVATE fun_objects
    $<$<BOOL:${WIN32}>:kernel32>
    $<$<BOOL:${WIN32}>:ws2_32>
    $<$<BOOL:${WIN32}>:mswsock>
    $<$<BOOL:${WIN32}>:advapi32>)

# Extract DWARF debug symbols into a separate file when building 
# executable programs for Apple platforms.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    string(APPEND _dsymutilcmd "$<IF:$<CONFIG:DEBUG,RELWITHDEBINFO>,"
                "xcrun;dsymutil;$<TARGET_FILE:fun>;--flat,"
                "true"
        >)
    add_custom_command(TARGET fun
            POST_BUILD
            COMMAND "${_dsymutilcmd}"
            COMMAND_EXPAND_LISTS
            BYPRODUCTS fun.dwarf)
endif()


###########################################################################
## Target install rules
###########################################################################

# Install rule for objects of target "fun_objects" to allow support for 
# SIL/PIL.
install(TARGETS fun_objects
    EXPORT funTargets
    OBJECTS DESTINATION "fun_ert_rtw")

# Install rule for executable target "fun". The "OPTIONAL" keyword is 
# required to support SIL/PIL when build of the final executable is 
# suppressed.
install(TARGETS fun
    RUNTIME DESTINATION "."
    OPTIONAL)

# Install rule for Microsoft PDB debug symbols, if required.
if(CMAKE_C_LINKER_SUPPORTS_PDB)
    install(FILES $<TARGET_PDB_FILE:fun>
        DESTINATION .
        OPTIONAL
        CONFIGURATIONS Debug RelWithDebInfo)
endif()

# Install rule for Apple DWARF debug symbols, if required.
if(APPLE AND (CMAKE_C_COMPILER_ID STREQUAL "AppleClang"))
    install(FILES $<TARGET_FILE_DIR:fun>/fun.dwarf
        DESTINATION .
        OPTIONAL
        CONFIGURATIONS Debug RelWithDebInfo)
endif()

# Write a rule that generates a wrapper around exported targets to 
# preserve tokenization of "special" directories (e.g., MATLAB_ROOT).  
# This avoids hard-coding absolute paths in the CMake file with the code 
# used to import the targets, and avoids errors when include paths that do 
# not exist in the current filesystem are defined, for example, after 
# relocating code using PackNGo.
file(WRITE "${CMAKE_CURRENT_BINARY_DIR}/fun.cmake" [=[include("${CMAKE_CURRENT_LIST_DIR}/funTargets.cmake")]=] \n)
file(APPEND "${CMAKE_CURRENT_BINARY_DIR}/fun.cmake" [=[set(FUN_OBJECTS_TOK_INC_DIRS_ALL]=] \n
    [=[    ${MATLAB_ROOT}/extern/include]=] \n
    [=[    ${MATLAB_ROOT}/simulink/include]=] \n
    [=[    ${MATLAB_ROOT}/rtw/c/src]=] \n
    [=[    ${MATLAB_ROOT}/rtw/c/src/ext_mode/common]=] \n
    [=[    ${MATLAB_ROOT}/rtw/c/ert)]=] \n
    [=[foreach(TOKDIR_LOOP IN LISTS FUN_OBJECTS_TOK_INC_DIRS_ALL)]=] \n
    [=[    if(IS_DIRECTORY ${TOKDIR_LOOP})]=] \n
    [=[        list(APPEND FUN_OBJECTS_TOK_INC_DIRS ${TOKDIR_LOOP})]=] \n
    [=[    endif()]=] \n
    [=[endforeach()]=] \n
    [=[target_include_directories(fun::fun_objects INTERFACE ${FUN_OBJECTS_TOK_INC_DIRS})]=] \n)
install(FILES "${CMAKE_CURRENT_BINARY_DIR}/fun.cmake"
    DESTINATION "fun_ert_rtw/export")

# Generate and install a file that allows the targets generated from this 
# CMakeLists.txt file to be imported into another project.
install(EXPORT funTargets NAMESPACE fun:: DESTINATION fun_ert_rtw/export)

###########################################################################
## Build success message
###########################################################################
add_custom_command(TARGET fun POST_BUILD
     COMMAND ${CMAKE_COMMAND} -E cmake_echo_color --cyan "\\#\\#\\# Created executable: $<TARGET_FILE:fun>")

###########################################################################
## Call toolchain hook function if defined
###########################################################################
if(COMMAND toolchain_target_hook)
    toolchain_target_hook(fun)
endif()
