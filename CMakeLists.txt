# Cmake
cmake_minimum_required (VERSION 2.6)
project(jetson_i2c)

#include
include_directories(include)

# Add executable
add_executable(jetson_i2c src/main.cpp include/kamod_mems2.h src/kamod_mems2.cpp)
