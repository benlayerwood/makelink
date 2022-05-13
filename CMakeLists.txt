cmake_minimum_required(VERSION 3.17)
project(makelink C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_compile_options(-g -Wall -std=c99 -pedantic -fcommon)
add_executable(makelink
        src/makelink.c
        src/makelink.h)
