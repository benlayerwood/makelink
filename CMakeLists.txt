cmake_minimum_required(VERSION 3.17)
project(makelink C)

set(CMAKE_C_STANDARD 99)

include_directories(src)

add_compile_options(-g -Wall -std=c99 -pedantic -fcommon -D_DEFAULT_SOURCE)
add_executable(makelink
        src/files.c
        src/main.c
        src/util.c
        src/args.c)
