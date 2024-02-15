cmake_minimum_required(VERSION 3.27)
project(chapter15_inheritance)

set(CMAKE_CXX_STANDARD 17)

add_executable(chapter15_inheritance main.cpp
        account.cpp
        saving_account.cpp
        account_util.cpp
)
