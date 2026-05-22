cmake_minimum_required(VERSION 3.10)
project(mini-RPG)

set(CMAKE_CXX_STANDARD 17)

add_executable(mini-RPG
    main.cpp
    enemies.cpp
    heroes.cpp
    src/character.cpp
)

target_include_directories(mini-RPG PRIVATE . include/)