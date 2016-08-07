cmake_minimum_required(VERSION 3.5)
project(numphp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    tests/001.phpt
    .gitignore
    config.m4
    config.w32
    CREDITS
    EXPERIMENTAL
    numphp.c
    numphp.php
    php_numphp.h)

add_executable(numphp ${SOURCE_FILES})