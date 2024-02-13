cmake_minimum_required(VERSION 3.26)
project(my_string_example)

set(CMAKE_CXX_STANDARD 17)

add_executable(my_string_example main.cpp my-string.cpp)
