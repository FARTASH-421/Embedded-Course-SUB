# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\Matlab\bin\win64\cmake\bin\cmake.exe

# The command to remove a file.
RM = D:\Matlab\bin\win64\cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\build"

# Include any dependencies generated for this target.
include CMakeFiles/fun_objects.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fun_objects.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fun_objects.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fun_objects.dir/flags.make

CMakeFiles/fun_objects.dir/fun.cpp.obj: CMakeFiles/fun_objects.dir/flags.make
CMakeFiles/fun_objects.dir/fun.cpp.obj: CMakeFiles/fun_objects.dir/includes_CXX.rsp
CMakeFiles/fun_objects.dir/fun.cpp.obj: D:/Private/Class\ Term\ 8/Embedd/HW/EX3/fun_ert_rtw/fun.cpp
CMakeFiles/fun_objects.dir/fun.cpp.obj: CMakeFiles/fun_objects.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fun_objects.dir/fun.cpp.obj"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fun_objects.dir/fun.cpp.obj -MF CMakeFiles\fun_objects.dir\fun.cpp.obj.d -o CMakeFiles\fun_objects.dir\fun.cpp.obj -c "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\fun.cpp"

CMakeFiles/fun_objects.dir/fun.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fun_objects.dir/fun.cpp.i"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\fun.cpp" > CMakeFiles\fun_objects.dir\fun.cpp.i

CMakeFiles/fun_objects.dir/fun.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fun_objects.dir/fun.cpp.s"
	C:\PROGRA~1\MinGW\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\fun.cpp" -o CMakeFiles\fun_objects.dir\fun.cpp.s

fun_objects: CMakeFiles/fun_objects.dir/fun.cpp.obj
fun_objects: CMakeFiles/fun_objects.dir/build.make
.PHONY : fun_objects

# Rule to build all files generated by this target.
CMakeFiles/fun_objects.dir/build: fun_objects
.PHONY : CMakeFiles/fun_objects.dir/build

CMakeFiles/fun_objects.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fun_objects.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fun_objects.dir/clean

CMakeFiles/fun_objects.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw" "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw" "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\build" "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\build" "D:\Private\Class Term 8\Embedd\HW\EX3\fun_ert_rtw\build\CMakeFiles\fun_objects.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/fun_objects.dir/depend

