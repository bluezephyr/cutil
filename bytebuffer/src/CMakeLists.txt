enable_language(C)
set(CMAKE_C_STANDARD 99)

add_library(bytebuffer
    bytebuffer.c)

target_include_directories(bytebuffer PUBLIC ../include)

