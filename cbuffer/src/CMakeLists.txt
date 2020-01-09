enable_language(C)
set(CMAKE_C_STANDARD 99)

add_library(cbuffer
    cbuffer.c)

target_include_directories(cbuffer PUBLIC ../include)

