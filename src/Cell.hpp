cmake_minimum_required(VERSION 3.10)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

include_directories(src)

add_executable(GameOfLife
    src/main.cpp
    src/Cell.hpp
    src/Grid.cpp
    src/Grid.hpp
    src/UI.cpp
    src/UI.hpp
)

target_link_libraries(GameOfLife sfml-graphics sfml-window sfml-system)

