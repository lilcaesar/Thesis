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

# Utility rule file for Nightly.

# Include the progress variables for this target.
include lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/progress.make

lib/nanogui/ext/eigen/CMakeFiles/Nightly:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen && /home/mattia/Programmi/Clion/clion-2016.3.3/bin/cmake/bin/ctest -D Nightly

Nightly: lib/nanogui/ext/eigen/CMakeFiles/Nightly
Nightly: lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/build.make

.PHONY : Nightly

# Rule to build all files generated by this target.
lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/build: Nightly

.PHONY : lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/build

lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/clean:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen && $(CMAKE_COMMAND) -P CMakeFiles/Nightly.dir/cmake_clean.cmake
.PHONY : lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/clean

lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/depend:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mattia/CLionProjects/Thesis /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen /home/mattia/CLionProjects/Thesis/cmake-build-debug /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanogui/ext/eigen/CMakeFiles/Nightly.dir/depend

