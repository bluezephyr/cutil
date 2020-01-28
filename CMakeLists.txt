cmake_minimum_required(VERSION 3.12)
project(cutil)

add_subdirectory(bytebuffer/src)

option(COMPILE_TESTS "Compile the tests" OFF)
if (COMPILE_TESTS)
    enable_testing()
    add_subdirectory(bytebuffer/tests)
endif(COMPILE_TESTS)

