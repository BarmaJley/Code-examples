cmake_minimum_required(VERSION 3.23)
project(Fast_computing_algorithms)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fopenmp")
add_executable(Fast_computing_algorithms main.cpp)
