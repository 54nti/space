cmake_minimum_required(VERSION 3.25)
project(space)

set(CMAKE_CXX_STANDARD 17)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(space main.cpp Nave.cpp Nave.h Asteroide.cpp Asteroide.h)
target_link_libraries(space ${CURSES_LIBRARIES})
