cmake_minimum_required(VERSION 3.2...3.27.5)

project(2025_12_23)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(sort_lib "")

enable_testing()

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(lib/googletest)  

add_subdirectory(bubble_sort)