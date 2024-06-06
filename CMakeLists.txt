cmake_minimum_required(VERSION 3.0)
project(my_game)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Raylib
set(RAYLIB_PATH /home/chrissolanilla/raylib)
include_directories(${RAYLIB_PATH}/src ${RAYLIB_PATH}/src/external)

# Add the executable
add_executable(my_game main.cpp)

# Link Raylib
target_link_libraries(my_game
    ${RAYLIB_PATH}/src/libraylib.a
    GL
    m
    pthread
    dl
    rt
    X11
)

# Export compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

