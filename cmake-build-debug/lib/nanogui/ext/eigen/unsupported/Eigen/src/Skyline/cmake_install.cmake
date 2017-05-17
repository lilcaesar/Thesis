# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen/src/Skyline" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline/SkylineInplaceLU.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline/SkylineMatrix.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline/SkylineMatrixBase.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline/SkylineProduct.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline/SkylineStorage.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/Skyline/SkylineUtil.h"
    )
endif()

