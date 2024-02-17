cmake_minimum_required(VERSION 3.26)
project(chapter18_exceptions)

set(CMAKE_CXX_STANDARD 17)

add_executable(chapter18_exceptions
        main.cpp
        account.cpp
        account_util.cpp
        checking_account.cpp
        i_printable.cpp
        saving_account.cpp
        trust_account.cpp
)
