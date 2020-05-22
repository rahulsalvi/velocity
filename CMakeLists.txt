cmake_minimum_required(VERSION 3.10)

project(velocity VERSION 0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCS
    src/Segment.h
    src/SegmentVisitor.h
    src/ResetColor.cpp
    src/RGBColor.cpp
    src/TermColor.cpp
    src/Format.cpp
    src/StartSegment.cpp
    src/TextSegment.cpp
    src/EndSegment.cpp
    src/ANSICodeGenerator.cpp
    src/zsh/ForwardGenerator.cpp
    src/zsh/ReverseGenerator.cpp
    src/velocity.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(velocity ${SRCS})
target_compile_options(velocity PRIVATE -Werror -Wall -Wextra)
target_include_directories(velocity PUBLIC src)
set(CMAKE_BUILD_TYPE Debug)
