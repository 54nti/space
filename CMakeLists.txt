cmake_minimum_required(VERSION 3.25)
project(space)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "-lncurses")

add_executable(space main.cpp nave.cpp nave.h)
