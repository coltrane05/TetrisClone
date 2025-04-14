cmake_minimum_required(VERSION 3.22)
project(TetrisClone)

set(CMAKE_CXX_STANDARD 17)

add_executable(TetrisClone src/main.cpp
        src/LPiece.cpp
        src/LPiece.h
        src/TetrisPiece.cpp
        src/TetrisPiece.h
        src/Grid.cpp
        src/Grid.h
        src/Cell.cpp
        src/Cell.h
        src/EventHandler.cpp
        src/EventHandler.h)

target_include_directories(TetrisClone PRIVATE "${PROJECT_BINARY_DIR}")

find_package(SFML COMPONENTS system window graphics network audio REQUIRED)

target_link_libraries(TetrisClone sfml-graphics sfml-system sfml-window sfml-audio sfml-network)

install(TARGETS TetrisClone DESTINATION bin)

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})