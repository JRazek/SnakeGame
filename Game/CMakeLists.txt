cmake_minimum_required(VERSION 3.16)
project(SnakeGame)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
find_package(SFML 2.5.1 COMPONENTS system graphics audio network REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wextra -Werror=vla")

add_library(SnakeGame Utils.h Utils.cpp SnakeGame.h SnakeGame.cpp SnakeGameVisualiser.h SnakeGameVisualiser.cpp SnakeDirection.h)

target_link_libraries(SnakeGame sfml-system sfml-graphics sfml-window)