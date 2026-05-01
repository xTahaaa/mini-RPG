cmake_minimum_required(VERSION 3.10)

project(mini-RPG)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(mini-RPG
    src/main.cpp
    src/Character.cpp
)