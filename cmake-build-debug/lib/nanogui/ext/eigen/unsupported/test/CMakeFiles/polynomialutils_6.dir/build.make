# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
include lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/depend.make

# Include the progress variables for this target.
include lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/flags.make

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/flags.make
lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o: ../lib/nanogui/ext/eigen/unsupported/test/polynomialutils.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o -c /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/test/polynomialutils.cpp

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.i"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/test/polynomialutils.cpp > CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.i

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.s"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/test/polynomialutils.cpp -o CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.s

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.requires:

.PHONY : lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.requires

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.provides: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.requires
	$(MAKE) -f lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/build.make lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.provides.build
.PHONY : lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.provides

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.provides.build: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o


# Object files for target polynomialutils_6
polynomialutils_6_OBJECTS = \
"CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o"

# External object files for target polynomialutils_6
polynomialutils_6_EXTERNAL_OBJECTS =

lib/nanogui/ext/eigen/unsupported/test/polynomialutils_6: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o
lib/nanogui/ext/eigen/unsupported/test/polynomialutils_6: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/build.make
lib/nanogui/ext/eigen/unsupported/test/polynomialutils_6: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable polynomialutils_6"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/polynomialutils_6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/build: lib/nanogui/ext/eigen/unsupported/test/polynomialutils_6

.PHONY : lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/build

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/requires: lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/polynomialutils.cpp.o.requires

.PHONY : lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/requires

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/clean:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test && $(CMAKE_COMMAND) -P CMakeFiles/polynomialutils_6.dir/cmake_clean.cmake
.PHONY : lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/clean

lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/depend:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mattia/CLionProjects/Thesis /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/test /home/mattia/CLionProjects/Thesis/cmake-build-debug /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanogui/ext/eigen/unsupported/test/CMakeFiles/polynomialutils_6.dir/depend

