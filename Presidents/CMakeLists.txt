cmake_minimum_required(VERSION 3.9)
project(Presidents)

set(CMAKE_CXX_STANDARD 14)

add_executable(Presidents main.cpp Date.cpp Date.h President.cpp President.h)