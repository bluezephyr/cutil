cmake_minimum_required(VERSION 3.12)
project(cutil)

# CUTIL is a library containing common c utilities.  CUTIL needs to be set.
set(CUTIL "${CMAKE_CURRENT_SOURCE_DIR}")

add_subdirectory(src/bytebuffer)

option(COMPILE_TESTS "Compile the tests" OFF)
if (COMPILE_TESTS)
    enable_testing()
    add_subdirectory(tests/bytebuffer)
endif(COMPILE_TESTS)

