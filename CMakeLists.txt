cmake_minimum_required(VERSION 3.10)

project(velocity VERSION 0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCS src/velocity.cpp src/ResetColor.cpp src/RGBColor.cpp src/TermColor.cpp)

add_executable(velocity ${SRCS})
