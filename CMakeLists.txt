cmake_minimum_required(VERSION 3.0.0)
project(Unnamed)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-g -Werror")

add_executable(
    Build
    src/main.cpp
    src/Graphics/Renderer.cpp
)