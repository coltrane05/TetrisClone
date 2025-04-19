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

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
        GIT_REPOSITORY https://github.com/SFML/SFML.git
        GIT_TAG 3.0.0
        GIT_SHALLOW ON
        EXCLUDE_FROM_ALL
        SYSTEM)
FetchContent_MakeAvailable(SFML)

target_compile_features(TetrisClone PRIVATE cxx_std_17)
target_link_libraries(TetrisClone PRIVATE SFML::Graphics SFML::System SFML::Window)

file(COPY assets DESTINATION ${PROJECT_BINARY_DIR})