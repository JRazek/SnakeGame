cmake_minimum_required(VERSION 3.16)
project(Snake)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Game)
add_executable(Snake main.cpp)

include_directories(Game)
target_link_libraries(Snake SnakeGame)