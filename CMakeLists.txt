cmake_minimum_required(VERSION 3.6)
project(Thesis)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/nanogui)
include_directories(lib/nanogui/include)

add_subdirectory(lib/nanogui/ext/eigen)
include_directories(lib/nanogui/ext/eigen/Eigen)

include_directories(lib/nanogui/ext/nanovg/src)

include_directories(Fabrizio)

set(SOURCE_FILES main.cpp Fabrizio/importFiles.cpp)
add_executable(Thesis ${SOURCE_FILES})
target_link_libraries(Thesis nanogui)