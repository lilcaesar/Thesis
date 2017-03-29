# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions

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
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h;/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixFunction.h;/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixFunctionAtomic.h;/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixLogarithm.h;/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixPower.h;/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/MatrixSquareRoot.h;/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions/StemFunction.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include/eigen3/unsupported/Eigen/src/MatrixFunctions" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/MatrixExponential.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/MatrixFunction.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/MatrixFunctionAtomic.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/MatrixLogarithm.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/MatrixPower.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/MatrixSquareRoot.h"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/unsupported/Eigen/src/MatrixFunctions/StemFunction.h"
    )
endif()

