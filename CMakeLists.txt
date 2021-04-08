cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(SnakeGame)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDL2_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_TTF_INCLUDE_DIR} src)
#include_directories(${SDL2_INCLUDE_DIRS} src)


add_executable(SnakeGame src/main.cpp src/game.h src/controller.h src/renderer.h src/snake.h src/game.cpp src/controller.cpp src/renderer.cpp src/snake.cpp src/Common.cpp src/Common.h src/Map.cpp src/Map.h)
#string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
#target_link_libraries(SnakeGame ${SDL2_LIBRARIES})
target_link_libraries(SnakeGame ${SDL2_LIBRARIES} ${SDL2_TTF_LIBRARIES})
