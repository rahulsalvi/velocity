cmake_minimum_required(VERSION 3.10)

project(velocity VERSION 0.0)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SRCS
    src/color/ResetColor.cpp
    src/color/RGBColor.cpp
    src/color/TermColor.cpp
    src/color/TermColor256.cpp
    src/color/visitor/ANSIColorCodeGenerator.cpp
    src/color/visitor/ZshColorCodeGenerator.cpp
    src/style/BoldStyle.cpp
    src/style/FaintStyle.cpp
    src/style/ItalicStyle.cpp
    src/style/UnderlineStyle.cpp
    src/style/DoubleUnderlineStyle.cpp
    src/style/StrikethroughStyle.cpp
    src/style/ResetStyle.cpp
    src/style/visitor/ANSIStyleCodeGenerator.cpp
    src/style/visitor/ZshStyleCodeGenerator.cpp
    src/Format.cpp
    src/segment/StartSegment.cpp
    src/segment/TextSegment.cpp
    src/segment/EndSegment.cpp
    src/segment/CWDSegment.cpp
    src/segment/EnvironmentConditionalSegment.cpp
    src/segment/GitInfoSegment.cpp
    src/segment/GitRepoConditionalSegment.cpp
    src/segment/visitor/EvalVisitor.cpp
    src/segment/visitor/TextGenerator.cpp
    src/segment/visitor/ForwardGenerator.cpp
    src/segment/visitor/ReverseGenerator.cpp
    src/segment/visitor/ForwardLengthInChars.cpp
    src/utils.cpp
    src/velocity.cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(velocity ${SRCS})
target_compile_options(velocity PRIVATE -Werror -Wall -Wextra)
target_include_directories(velocity PUBLIC src)
