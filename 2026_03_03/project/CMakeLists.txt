cmake_minimum_required(VERSION 3.10)
project(LongNumberProject)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(source)
add_subdirectory(test)

enable_testing()