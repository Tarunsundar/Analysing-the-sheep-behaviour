cmake_minimum_required(VERSION 3.17)
project(cs23820_assignment C)

set(CMAKE_C_STANDARD 11)

add_executable(cs23820_assignment sources/main.c sources/parser.c headers/parser.h headers/config.h sources/movement.c headers/movement.h sources/coordinate.c headers/coordinate.h sources/calculator.c headers/calculator.h)