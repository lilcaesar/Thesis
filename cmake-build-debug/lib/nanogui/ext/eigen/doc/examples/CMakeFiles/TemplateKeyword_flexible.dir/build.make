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
include lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/depend.make

# Include the progress variables for this target.
include lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/progress.make

# Include the compile flags for this target's objects.
include lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/flags.make

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/flags.make
lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o: ../lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o -c /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible.cpp

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.i"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible.cpp > CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.i

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.s"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible.cpp -o CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.s

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.requires:

.PHONY : lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.requires

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.provides: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.requires
	$(MAKE) -f lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/build.make lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.provides.build
.PHONY : lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.provides

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.provides.build: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o


# Object files for target TemplateKeyword_flexible
TemplateKeyword_flexible_OBJECTS = \
"CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o"

# External object files for target TemplateKeyword_flexible
TemplateKeyword_flexible_EXTERNAL_OBJECTS =

lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o
lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/build.make
lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mattia/CLionProjects/Thesis/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable TemplateKeyword_flexible"
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TemplateKeyword_flexible.dir/link.txt --verbose=$(VERBOSE)
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples && ./TemplateKeyword_flexible >/home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible.out

# Rule to build all files generated by this target.
lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/build: lib/nanogui/ext/eigen/doc/examples/TemplateKeyword_flexible

.PHONY : lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/build

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/requires: lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/TemplateKeyword_flexible.cpp.o.requires

.PHONY : lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/requires

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/clean:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples && $(CMAKE_COMMAND) -P CMakeFiles/TemplateKeyword_flexible.dir/cmake_clean.cmake
.PHONY : lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/clean

lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/depend:
	cd /home/mattia/CLionProjects/Thesis/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mattia/CLionProjects/Thesis /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/doc/examples /home/mattia/CLionProjects/Thesis/cmake-build-debug /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples /home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/nanogui/ext/eigen/doc/examples/CMakeFiles/TemplateKeyword_flexible.dir/depend

