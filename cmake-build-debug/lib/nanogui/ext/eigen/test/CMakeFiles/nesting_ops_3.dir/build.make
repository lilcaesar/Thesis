# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/mattia/Programmi/Clion/clion-2016.3.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/mattia/Programmi/Clion/clion-2016.3.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mattia/CLionProjects/Thesis

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mattia/CLionProjects/Thesis/cmake-build-debug

# Include any dependencies generated for this target.
include lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/depend.make

# Include the progress variables for this target.
include lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/flags.make

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/flags.make
lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o: ../lib/nanogui/ext/eigen/test/nesting_ops.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o -c /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test/nesting_ops.cpp

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.i"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test/nesting_ops.cpp > CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.i

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.s"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test/nesting_ops.cpp -o CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.s

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.requires:

.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.requires

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.provides: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.requires
	$(MAKE) -f lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/build.make lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.provides.build
.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.provides

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.provides.build: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o


# Object files for target nesting_ops_3
nesting_ops_3_OBJECTS = \
"CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o"

# External object files for target nesting_ops_3
nesting_ops_3_EXTERNAL_OBJECTS =

lib/nanogui/ext/eigen/test/nesting_ops_3: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o
lib/nanogui/ext/eigen/test/nesting_ops_3: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/build.make
lib/nanogui/ext/eigen/test/nesting_ops_3: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable nesting_ops_3"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/nesting_ops_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/build: lib/nanogui/ext/eigen/test/nesting_ops_3

.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/build

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/requires: lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/nesting_ops.cpp.o.requires

.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/requires

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/clean:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/nesting_ops_3.dir/cmake_clean.cmake
.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/clean

lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/depend:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mattia/CLionProjects/Thesis /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test /home/mattia/CLionProjects/Thesis/cmake-build-debug /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/nesting_ops_3.dir/depend

