# Install script for directory: /home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen

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
   "/usr/local/include/eigen3/Eigen/Array;/usr/local/include/eigen3/Eigen/Cholesky;/usr/local/include/eigen3/Eigen/CholmodSupport;/usr/local/include/eigen3/Eigen/Core;/usr/local/include/eigen3/Eigen/Dense;/usr/local/include/eigen3/Eigen/Eigen;/usr/local/include/eigen3/Eigen/Eigen2Support;/usr/local/include/eigen3/Eigen/Eigenvalues;/usr/local/include/eigen3/Eigen/Geometry;/usr/local/include/eigen3/Eigen/Householder;/usr/local/include/eigen3/Eigen/IterativeLinearSolvers;/usr/local/include/eigen3/Eigen/Jacobi;/usr/local/include/eigen3/Eigen/LU;/usr/local/include/eigen3/Eigen/LeastSquares;/usr/local/include/eigen3/Eigen/MetisSupport;/usr/local/include/eigen3/Eigen/OrderingMethods;/usr/local/include/eigen3/Eigen/PaStiXSupport;/usr/local/include/eigen3/Eigen/PardisoSupport;/usr/local/include/eigen3/Eigen/QR;/usr/local/include/eigen3/Eigen/QtAlignedMalloc;/usr/local/include/eigen3/Eigen/SPQRSupport;/usr/local/include/eigen3/Eigen/SVD;/usr/local/include/eigen3/Eigen/Sparse;/usr/local/include/eigen3/Eigen/SparseCholesky;/usr/local/include/eigen3/Eigen/SparseCore;/usr/local/include/eigen3/Eigen/SparseLU;/usr/local/include/eigen3/Eigen/SparseQR;/usr/local/include/eigen3/Eigen/StdDeque;/usr/local/include/eigen3/Eigen/StdList;/usr/local/include/eigen3/Eigen/StdVector;/usr/local/include/eigen3/Eigen/SuperLUSupport;/usr/local/include/eigen3/Eigen/UmfPackSupport")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/usr/local/include/eigen3/Eigen" TYPE FILE FILES
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Array"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Cholesky"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/CholmodSupport"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Core"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Dense"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Eigen"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Eigen2Support"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Eigenvalues"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Geometry"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Householder"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/IterativeLinearSolvers"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Jacobi"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/LU"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/LeastSquares"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/MetisSupport"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/OrderingMethods"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/PaStiXSupport"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/PardisoSupport"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/QR"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/QtAlignedMalloc"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SPQRSupport"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SVD"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/Sparse"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SparseCholesky"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SparseCore"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SparseLU"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SparseQR"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/StdDeque"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/StdList"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/StdVector"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/SuperLUSupport"
    "/home/mattia/CLionProjects/Thesis/lib/nanogui/ext/eigen/Eigen/UmfPackSupport"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/mattia/CLionProjects/Thesis/cmake-build-debug/lib/nanogui/ext/eigen/Eigen/src/cmake_install.cmake")

endif()

