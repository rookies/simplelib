cmake_minimum_required(VERSION 3.10)
project(simplelib)

set(CMAKE_CXX_STANDARD 11)

find_package(UnitTest++ REQUIRED)

include_directories(
        lib/include
        ${UTPP_INCLUDE_DIRS}
)

set(
        INCLUDE_FILES
        lib/include/FormattedOutput.hh
        lib/include/FormattedOutputBuffer.hh
        lib/include/Random.hh
)

add_library(
        simplelib
        STATIC
        lib/src/FormattedOutput.cc
        lib/src/FormattedOutputBuffer.cc
        lib/src/Random.cc
        ${INCLUDE_FILES}
)

add_executable(
        tests
        tests/main.cc
        tests/FormattedOutput.cc
        tests/FormattedOutputBuffer.cc
        tests/Random.cc
        ${INCLUDE_FILES}
)
target_link_libraries(
        tests
        simplelib
        UnitTest++
)