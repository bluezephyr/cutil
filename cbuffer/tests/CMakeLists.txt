message("CPPUTEST_HOME: '${CPPUTEST_HOME}'")
find_library(CPPUTESTLIB NAMES CppUTest HINTS ${CPPUTEST_HOME}/cpputest_build/lib)
find_library(CPPUTESTEXTLIB NAMES CppUTestExt HINTS ${CPPUTEST_HOME}/cpputest_build/lib)
message("CppUTest lib: ${CPPUTESTLIB}")
message("CppUTestExt lib: ${CPPUTESTEXTLIB}")

add_executable(cbuffer_test
    CBufferTest.cpp)

target_include_directories(cbuffer_test PRIVATE ${CPPUTEST_HOME}/include)
target_include_directories(cbuffer_test PRIVATE ../include)

target_link_libraries(cbuffer_test
    cbuffer
    ${CPPUTESTLIB}
    ${CPPUTESTEXTLIB} )

add_test(cbuffer cbuffer_test)
