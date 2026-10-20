cmake_minimum_required(VERSION 3.20)

project(dnc C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES "src/*.c")

add_executable(dnc ${SOURCES})

target_include_directories(dnc PRIVATE include)
