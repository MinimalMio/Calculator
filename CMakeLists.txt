cmake_minimum_required(VERSION 3.10)
project(Calculator VERSION 1.1.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions("-g -Wall -Werror -lcurses")

find_package(CURSES REQUIRED)

add_executable(calculator src/main.cpp)

install(TARGETS calculator DESTINATION bin)
message(STATUS "Calculator Version: ${PROJECT_VERSION}")