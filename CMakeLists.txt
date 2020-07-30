cmake_minimum_required(VERSION 3.11)
project(PracticeGame)

find_package(raylib 3.0 QUIET)

add_executable(${PROJECT_NAME} main.c game.c)
target_link_libraries(${PROJECT_NAME} raylib)
