cmake_minimum_required(VERSION 3.6)
project(Thesis)

set(CMAKE_CXX_STANDARD 11)

include_directories(src resources)
file(GLOB_RECURSE data resources/*)
file(COPY ${data} DESTINATION resources)

add_subdirectory(lib/nanogui)
include_directories(lib/nanogui/include)

set_property(TARGET glfw glfw_objects nanogui PROPERTY FOLDER "dependencies")

add_subdirectory(lib/nanogui/ext/eigen)
include_directories(lib/nanogui/ext/eigen/Eigen)

include_directories(lib/nanogui/ext/nanovg/src)

include_directories(Fabrizio)

set(SOURCE_FILES main.cpp Fabrizio/importFiles.cpp)
add_executable(Thesis ${SOURCE_FILES} ${data})
target_link_libraries(Thesis nanogui)