cmake_minimum_required(VERSION 3.27)
project(mbti_test_program)

set(CMAKE_CXX_STANDARD 14)

include_directories("mbti program")

add_executable(mbti_test_program
        "mbti program/main.c"
        "mbti program/mbtilib.c"
        )
