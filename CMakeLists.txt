cmake_minimum_required(VERSION 3.19)
project(hw07)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(hw07
        hw07.cpp
        ManageInventory.cpp
        ManageInventory.h)
