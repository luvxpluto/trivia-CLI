cmake_minimum_required(VERSION 3.23)
project(trivia_CLI C)

set(CMAKE_C_STANDARD 99)

add_executable(trivia_CLI main.c input.h players.c players.h input.c menu.c menu.h)