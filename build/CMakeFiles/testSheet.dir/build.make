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
include CMakeFiles/testSheet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/testSheet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/testSheet.dir/flags.make

CMakeFiles/testSheet.dir/testSheet.cpp.o: CMakeFiles/testSheet.dir/flags.make
CMakeFiles/testSheet.dir/testSheet.cpp.o: ../testSheet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/testSheet.dir/testSheet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSheet.dir/testSheet.cpp.o -c /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/testSheet.cpp

CMakeFiles/testSheet.dir/testSheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSheet.dir/testSheet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/testSheet.cpp > CMakeFiles/testSheet.dir/testSheet.cpp.i

CMakeFiles/testSheet.dir/testSheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSheet.dir/testSheet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/testSheet.cpp -o CMakeFiles/testSheet.dir/testSheet.cpp.s

CMakeFiles/testSheet.dir/testSheet.cpp.o.requires:

.PHONY : CMakeFiles/testSheet.dir/testSheet.cpp.o.requires

CMakeFiles/testSheet.dir/testSheet.cpp.o.provides: CMakeFiles/testSheet.dir/testSheet.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSheet.dir/build.make CMakeFiles/testSheet.dir/testSheet.cpp.o.provides.build
.PHONY : CMakeFiles/testSheet.dir/testSheet.cpp.o.provides

CMakeFiles/testSheet.dir/testSheet.cpp.o.provides.build: CMakeFiles/testSheet.dir/testSheet.cpp.o


CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o: CMakeFiles/testSheet.dir/flags.make
CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o: ../src/BPlusTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o -c /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/src/BPlusTree.cpp

CMakeFiles/testSheet.dir/src/BPlusTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSheet.dir/src/BPlusTree.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/src/BPlusTree.cpp > CMakeFiles/testSheet.dir/src/BPlusTree.cpp.i

CMakeFiles/testSheet.dir/src/BPlusTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSheet.dir/src/BPlusTree.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/src/BPlusTree.cpp -o CMakeFiles/testSheet.dir/src/BPlusTree.cpp.s

CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.requires:

.PHONY : CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.requires

CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.provides: CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSheet.dir/build.make CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.provides.build
.PHONY : CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.provides

CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.provides.build: CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o


CMakeFiles/testSheet.dir/src/Sheet.cpp.o: CMakeFiles/testSheet.dir/flags.make
CMakeFiles/testSheet.dir/src/Sheet.cpp.o: ../src/Sheet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/testSheet.dir/src/Sheet.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/testSheet.dir/src/Sheet.cpp.o -c /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/src/Sheet.cpp

CMakeFiles/testSheet.dir/src/Sheet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testSheet.dir/src/Sheet.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/src/Sheet.cpp > CMakeFiles/testSheet.dir/src/Sheet.cpp.i

CMakeFiles/testSheet.dir/src/Sheet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testSheet.dir/src/Sheet.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/src/Sheet.cpp -o CMakeFiles/testSheet.dir/src/Sheet.cpp.s

CMakeFiles/testSheet.dir/src/Sheet.cpp.o.requires:

.PHONY : CMakeFiles/testSheet.dir/src/Sheet.cpp.o.requires

CMakeFiles/testSheet.dir/src/Sheet.cpp.o.provides: CMakeFiles/testSheet.dir/src/Sheet.cpp.o.requires
	$(MAKE) -f CMakeFiles/testSheet.dir/build.make CMakeFiles/testSheet.dir/src/Sheet.cpp.o.provides.build
.PHONY : CMakeFiles/testSheet.dir/src/Sheet.cpp.o.provides

CMakeFiles/testSheet.dir/src/Sheet.cpp.o.provides.build: CMakeFiles/testSheet.dir/src/Sheet.cpp.o


# Object files for target testSheet
testSheet_OBJECTS = \
"CMakeFiles/testSheet.dir/testSheet.cpp.o" \
"CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o" \
"CMakeFiles/testSheet.dir/src/Sheet.cpp.o"

# External object files for target testSheet
testSheet_EXTERNAL_OBJECTS =

testSheet: CMakeFiles/testSheet.dir/testSheet.cpp.o
testSheet: CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o
testSheet: CMakeFiles/testSheet.dir/src/Sheet.cpp.o
testSheet: CMakeFiles/testSheet.dir/build.make
testSheet: CMakeFiles/testSheet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable testSheet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testSheet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/testSheet.dir/build: testSheet

.PHONY : CMakeFiles/testSheet.dir/build

CMakeFiles/testSheet.dir/requires: CMakeFiles/testSheet.dir/testSheet.cpp.o.requires
CMakeFiles/testSheet.dir/requires: CMakeFiles/testSheet.dir/src/BPlusTree.cpp.o.requires
CMakeFiles/testSheet.dir/requires: CMakeFiles/testSheet.dir/src/Sheet.cpp.o.requires

.PHONY : CMakeFiles/testSheet.dir/requires

CMakeFiles/testSheet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/testSheet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/testSheet.dir/clean

CMakeFiles/testSheet.dir/depend:
	cd /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build /home/zhoujiaqing/projects/projects_on_campus/linux_project/My_project/build/CMakeFiles/testSheet.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/testSheet.dir/depend

