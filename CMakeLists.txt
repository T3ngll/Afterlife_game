cmake_minimum_required(VERSION 3.22)
project(afterlife)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(afterlife
        include/raylib.h
        src/main.cpp src/Character.cpp src/Character.h)
