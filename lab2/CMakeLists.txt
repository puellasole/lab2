﻿# CMakeList.txt : CMake project for lab2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (lab2 "lab2.cpp" "lab2.h" )

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET lab2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
