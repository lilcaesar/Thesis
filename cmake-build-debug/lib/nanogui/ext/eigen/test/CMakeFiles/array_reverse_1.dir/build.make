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
include lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/depend.make

# Include the progress variables for this target.
include lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/flags.make

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/flags.make
lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o: ../lib/nanogui/ext/eigen/test/array_reverse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o -c /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test/array_reverse.cpp

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/array_reverse_1.dir/array_reverse.cpp.i"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test/array_reverse.cpp > CMakeFiles/array_reverse_1.dir/array_reverse.cpp.i

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/array_reverse_1.dir/array_reverse.cpp.s"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test/array_reverse.cpp -o CMakeFiles/array_reverse_1.dir/array_reverse.cpp.s

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.requires:

.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.requires

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.provides: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.requires
	$(MAKE) -f lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/build.make lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.provides.build
.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.provides

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.provides.build: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o


# Object files for target array_reverse_1
array_reverse_1_OBJECTS = \
"CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o"

# External object files for target array_reverse_1
array_reverse_1_EXTERNAL_OBJECTS =

lib/nanogui/ext/eigen/test/array_reverse_1: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o
lib/nanogui/ext/eigen/test/array_reverse_1: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/build.make
lib/nanogui/ext/eigen/test/array_reverse_1: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable array_reverse_1"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/array_reverse_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/build: lib/nanogui/ext/eigen/test/array_reverse_1

.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/build

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/requires: lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/array_reverse.cpp.o.requires

.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/requires

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/clean:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test && $(CMAKE_COMMAND) -P CMakeFiles/array_reverse_1.dir/cmake_clean.cmake
.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/clean

lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/depend:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mattia/CLionProjects/Thesis /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/test /home/mattia/CLionProjects/Thesis/cmake-build-debug /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanogui/ext/eigen/test/CMakeFiles/array_reverse_1.dir/depend

