# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Eigen2Support" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Block.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Cwise.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/CwiseOperators.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/LU.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Lazy.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/LeastSquares.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Macros.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/MathFunctions.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Memory.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Meta.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Minor.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/QR.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/SVD.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/TriangularSolver.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/VectorBlock.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/Eigen/src/Eigen2Support/Geometry/cmake_install.cmake")

endif()

