cmake_minimum_required(VERSION 3.12)
project(cutil)

add_subdirectory(cbuffer/src)

option(COMPILE_TESTS "Compile the tests" OFF)
if (COMPILE_TESTS)
    enable_testing()
    add_subdirectory(cbuffer/tests)
endif(COMPILE_TESTS)

