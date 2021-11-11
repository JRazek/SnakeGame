cmake_minimum_required(VERSION 3.16)
project(SnakeGame)

set(CMAKE_CXX_STANDARD 20)

add_library(SnakeGame Utils.h Utils.cpp SnakeGame.h SnakeGame.cpp)

find_package (SFML REQUIRED system window graphics network audio)
include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(SnakeGame ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})