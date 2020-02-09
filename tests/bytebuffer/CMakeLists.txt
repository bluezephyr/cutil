message("CPPUTEST_HOME: '${CPPUTEST_HOME}'")
find_library(CPPUTESTLIB NAMES CppUTest HINTS ${CPPUTEST_HOME}/cpputest_build/lib)
find_library(CPPUTESTEXTLIB NAMES CppUTestExt HINTS ${CPPUTEST_HOME}/cpputest_build/lib)
message("CppUTest lib: ${CPPUTESTLIB}")
message("CppUTestExt lib: ${CPPUTESTEXTLIB}")

add_executable(bytebuffer_test
    ByteBufferTest.cpp)

target_include_directories(bytebuffer_test PRIVATE ${CPPUTEST_HOME}/include)
target_include_directories(bytebuffer_test PRIVATE ../include)

target_link_libraries(bytebuffer_test
    bytebuffer
    ${CPPUTESTLIB}
    ${CPPUTESTEXTLIB} )

add_test(bytebuffer bytebuffer_test)
