cmake_minimum_required(VERSION 3.22)
project(Calculator VERSION 1.0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
add_definitions("-Wall -g")

add_executable(calculator src/main.cpp)
