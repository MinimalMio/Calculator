cmake_minimum_required(VERSION 3.10)
project(calculator VERSION 1.1.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(${PROJECT_NAME} PUBLIC
    src/include
)

add_executable(calculator
    src/main.cc
)

install(TARGETS calculator DESTINATION bin)