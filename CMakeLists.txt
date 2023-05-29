cmake_minimum_required(VERSION 3.22)
project(afterlife)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(afterlife
        include/character.h
        include/movable.h
        include/object.h
        include/projectiles.h
        include/raylib.h
        src/character.cpp
        src/main.cpp
        src/movable.cpp
        src/object.cpp
        src/projectiles.cpp src/preload.cpp include/preload.h)
