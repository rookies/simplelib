cmake_minimum_required(VERSION 3.10)
project(simplelib)

set(CMAKE_CXX_STANDARD 11)

include_directories(lib/include)

add_library(
        simplelib
        STATIC
        lib/src/FormattedOutput.cc
        lib/include/FormattedOutput.hh
        lib/src/FormattedOutputBuffer.cc
        lib/include/FormattedOutputBuffer.hh
)

add_executable(
        FormattedOutput
        test/FormattedOutput.cc
        lib/include/FormattedOutput.hh
)
target_link_libraries(
        FormattedOutput
        simplelib
)