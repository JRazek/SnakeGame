cmake_minimum_required(VERSION 3.16)
project(SnakeGame)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

option(SFML "SFML MODE" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wextra -Werror=vla")
set(SFML_STATIC_LIBRARIES TRUE)

if(SFML)
    add_library(SnakeGame Utils.h Utils.cpp SnakeGame.h SnakeGame.cpp SnakeGameVisualiser.h SnakeGameVisualiser.cpp SnakeDirection.h GameStatus.h)
    find_package(SFML 2.5.1 COMPONENTS system graphics audio network REQUIRED)
    target_link_libraries(SnakeGame sfml-system sfml-graphics sfml-window)
else()
    add_library(SnakeGame Utils.h Utils.cpp SnakeGame.h SnakeGame.cpp SnakeDirection.h GameStatus.h)
endif()
