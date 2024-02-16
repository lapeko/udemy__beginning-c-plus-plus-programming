cmake_minimum_required(VERSION 3.26)
project(chapter16_polymorphism)

set(CMAKE_CXX_STANDARD 17)

add_executable(chapter15_polymorphism
        main.cpp
        account.cpp
        account_util.cpp
        checking_account.cpp
        saving_account.cpp
        trust_account.cpp
        i_printable.cpp
)
