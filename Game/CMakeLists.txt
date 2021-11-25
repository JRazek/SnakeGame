cmake_minimum_required(VERSION 3.16)
project(SnakeGame)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS_RELEASE "-O3")

option(SFML "SFML MODE" ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread -Wall -Wextra -Werror=vla")

set(SNAKE_FILES Utils.cpp SnakeGame.cpp)
set(VISUALISER_FILES SnakeGameVisualiser.cpp)

add_library(SnakeGame SHARED ${SNAKE_FILES})

if(SFML)
    target_sources(SnakeGame PUBLIC ${VISUALISER_FILES})
    find_package(SFML 2.5.1 COMPONENTS system graphics audio network REQUIRED)
    target_link_libraries(SnakeGame sfml-system sfml-graphics sfml-window)
endif()
