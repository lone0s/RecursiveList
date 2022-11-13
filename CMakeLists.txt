cmake_minimum_required(VERSION 3.23)
project(RecList)

set(CMAKE_CXX_STANDARD 14)

add_executable(RecList main.cpp List.cpp List.h Cell.cpp Cell.h)
