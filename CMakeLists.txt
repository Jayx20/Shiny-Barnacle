cmake_minimum_required(VERSION 3.0.0)
project(Unnamed)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "-g -Werror -std=c++11")

add_compile_definitions(DEBUG)

include_directories(include)

if(WIN32)
    link_directories(libWindows)
endif()
if(APPLE)
    link_directories(libMac)
    set(CMAKE_INSTALL_RPATH "@executable_path")
    set(CMAKE_INSTALL_PREFIX "@executable_path")
endif()
if(UNIX AND NOT APPLE)
    link_directories(libLinux)
endif()

add_executable(
    Build
    src/main.cpp
    src/VectorUtil.cpp
    src/Graphics/Renderer.cpp
    src/Graphics/Mesh.cpp
    src/Graphics/ShaderClass.cpp
    src/Graphics/CubeMesh.cpp
    src/Graphics/Camera.cpp
    src/GameObjects/Object.cpp
    src/Input/Keyboard.cpp
)

if(WIN32)
    find_library(GLFWLIB lib/libglfw3.a)
    target_link_libraries(Build glew32 libglfw3.a opengl32 glu32 gdi32)
endif()

if(APPLE)
    target_link_libraries(Build GLEW glfw3 "-framework Cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")
    file(GLOB LIBRARIES "lib/*.dylib")
endif()

if(UNIX AND NOT APPLE)
    target_link_libraries(Build GL GLU GLEW glfw3 X11 Xxf86vm Xrandr pthread Xi dl Xinerama Xcursor ${LIBRARIES})
endif()