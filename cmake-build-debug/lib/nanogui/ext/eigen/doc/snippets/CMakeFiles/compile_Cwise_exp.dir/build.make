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
include lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/depend.make

# Include the progress variables for this target.
include lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/flags.make

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/flags.make
lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o: lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp.cpp
lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o: ../lib/nanogui/ext/eigen/doc/snippets/Cwise_exp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o -c /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp.cpp

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.i"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp.cpp > CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.i

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.s"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp.cpp -o CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.s

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.requires:

.PHONY : lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.requires

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.provides: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.requires
	$(MAKE) -f lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/build.make lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.provides.build
.PHONY : lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.provides

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.provides.build: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o


# Object files for target compile_Cwise_exp
compile_Cwise_exp_OBJECTS = \
"CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o"

# External object files for target compile_Cwise_exp
compile_Cwise_exp_EXTERNAL_OBJECTS =

lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o
lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/build.make
lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable compile_Cwise_exp"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/compile_Cwise_exp.dir/link.txt --verbose=$(VERBOSE)
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets && ./compile_Cwise_exp >/home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets/Cwise_exp.out

# Rule to build all files generated by this target.
lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/build: lib/nanogui/ext/eigen/doc/snippets/compile_Cwise_exp

.PHONY : lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/build

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/requires: lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/compile_Cwise_exp.cpp.o.requires

.PHONY : lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/requires

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/clean:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets && $(CMAKE_COMMAND) -P CMakeFiles/compile_Cwise_exp.dir/cmake_clean.cmake
.PHONY : lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/clean

lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/depend:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mattia/CLionProjects/Thesis /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/doc/snippets /home/mattia/CLionProjects/Thesis/cmake-build-debug /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanogui/ext/eigen/doc/snippets/CMakeFiles/compile_Cwise_exp.dir/depend

