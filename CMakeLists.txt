cmake_minimum_required(VERSION 3.10)
project(mini-RPG)

set(CMAKE_CXX_STANDARD 17)

add_executable(mini-RPG
    src/main.cpp
    src/enemies.cpp
    src/heroes.cpp
    src/character.cpp
)

target_include_directories(mini-RPG PRIVATE include/)