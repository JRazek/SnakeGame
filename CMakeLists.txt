cmake_minimum_required(VERSION 3.16)
project(Snake)

set(CMAKE_CXX_STANDARD 20)

add_executable(Snake main.cpp)

add_subdirectory(Game)

target_link_libraries(Snake SnakeGame)
