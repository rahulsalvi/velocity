cmake_minimum_required(VERSION 3.10)

project(velocity VERSION 0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCS
    src/segment/Segment.h
    src/segment/visitor/SegmentVisitor.h
    src/color/ResetColor.cpp
    src/color/RGBColor.cpp
    src/color/TermColor.cpp
    src/color/Format.cpp
    src/segment/StartSegment.cpp
    src/segment/TextSegment.cpp
    src/segment/EndSegment.cpp
    src/segment/CWDSegment.cpp
    src/color/visitor/ANSICodeGenerator.cpp
    src/zsh/ForwardGenerator.cpp
    src/zsh/ReverseGenerator.cpp
    src/zsh/ColorCodeGenerator.cpp
    src/velocity.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(velocity ${SRCS})
target_compile_options(velocity PRIVATE -Werror -Wall -Wextra)
target_include_directories(velocity PUBLIC src)
set(CMAKE_BUILD_TYPE Debug)
