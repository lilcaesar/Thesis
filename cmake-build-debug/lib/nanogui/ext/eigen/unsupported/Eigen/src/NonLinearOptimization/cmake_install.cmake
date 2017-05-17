# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen/src/NonLinearOptimization" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/HybridNonLinearSolver.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/LevenbergMarquardt.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/chkder.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/covar.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/dogleg.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/fdjac1.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/lmpar.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/qrsolv.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/r1mpyq.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/r1updt.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/NonLinearOptimization/rwupdt.h"
    )
endif()

