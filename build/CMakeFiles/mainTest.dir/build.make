# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build

# Include any dependencies generated for this target.
include CMakeFiles/mainTest.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/mainTest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/mainTest.dir/flags.make

CMakeFiles/mainTest.dir/mainTest.cpp.o: CMakeFiles/mainTest.dir/flags.make
CMakeFiles/mainTest.dir/mainTest.cpp.o: ../mainTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mainTest.dir/mainTest.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/mainTest.dir/mainTest.cpp.o -c /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/mainTest.cpp

CMakeFiles/mainTest.dir/mainTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mainTest.dir/mainTest.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/mainTest.cpp > CMakeFiles/mainTest.dir/mainTest.cpp.i

CMakeFiles/mainTest.dir/mainTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mainTest.dir/mainTest.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/mainTest.cpp -o CMakeFiles/mainTest.dir/mainTest.cpp.s

CMakeFiles/mainTest.dir/mainTest.cpp.o.requires:

.PHONY : CMakeFiles/mainTest.dir/mainTest.cpp.o.requires

CMakeFiles/mainTest.dir/mainTest.cpp.o.provides: CMakeFiles/mainTest.dir/mainTest.cpp.o.requires
	$(MAKE) -f CMakeFiles/mainTest.dir/build.make CMakeFiles/mainTest.dir/mainTest.cpp.o.provides.build
.PHONY : CMakeFiles/mainTest.dir/mainTest.cpp.o.provides

CMakeFiles/mainTest.dir/mainTest.cpp.o.provides.build: CMakeFiles/mainTest.dir/mainTest.cpp.o


# Object files for target mainTest
mainTest_OBJECTS = \
"CMakeFiles/mainTest.dir/mainTest.cpp.o"

# External object files for target mainTest
mainTest_EXTERNAL_OBJECTS =

mainTest: CMakeFiles/mainTest.dir/mainTest.cpp.o
mainTest: CMakeFiles/mainTest.dir/build.make
mainTest: CMakeFiles/mainTest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable mainTest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mainTest.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/mainTest.dir/build: mainTest

.PHONY : CMakeFiles/mainTest.dir/build

CMakeFiles/mainTest.dir/requires: CMakeFiles/mainTest.dir/mainTest.cpp.o.requires

.PHONY : CMakeFiles/mainTest.dir/requires

CMakeFiles/mainTest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/mainTest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/mainTest.dir/clean

CMakeFiles/mainTest.dir/depend:
	cd /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles/mainTest.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/mainTest.dir/depend
