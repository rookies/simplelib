cmake_minimum_required(VERSION 3.10)
project(simplelib)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib/include)

set(
        INCLUDE_FILES
        lib/include/FormattedOutput.hh
        lib/include/FormattedOutputBuffer.hh
)

add_library(
        simplelib
        STATIC
        lib/src/FormattedOutput.cc
        lib/src/FormattedOutputBuffer.cc
        ${INCLUDE_FILES}
)

add_executable(
        tests
        tests/main.cc
        tests/FormattedOutput.cc
        tests/FormattedOutputBuffer.cc
        ${INCLUDE_FILES}
)
target_link_libraries(
        tests
        simplelib
        UnitTest++
)