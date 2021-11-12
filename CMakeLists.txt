cmake_minimum_required(VERSION 3.16)
project(Snake)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Game)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
add_executable(Snake main.cpp)
target_link_libraries(Snake SnakeGame)
