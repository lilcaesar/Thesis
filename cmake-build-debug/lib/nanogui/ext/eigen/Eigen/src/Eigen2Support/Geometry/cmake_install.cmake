# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry

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

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Eigen2Support/Geometry" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/AlignedBox.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/All.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/AngleAxis.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/Hyperplane.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/ParametrizedLine.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/Quaternion.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/Rotation2D.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/RotationBase.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/Scaling.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/Transform.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/Translation.h"
    )
endif()

