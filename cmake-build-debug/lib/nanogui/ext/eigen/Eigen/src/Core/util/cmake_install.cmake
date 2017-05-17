# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Core/util" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/BlasUtil.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/Constants.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/DisableStupidWarnings.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/ForwardDeclarations.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/MKL_support.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/Macros.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/Memory.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/Meta.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/NonMPL2.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/ReenableStupidWarnings.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/StaticAssert.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Core/util/XprHelper.h"
    )
endif()

