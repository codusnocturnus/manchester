cmake_minimum_required(VERSION 3.17)

project(manchester_tests
    LANGUAGES CXX
)

set(ENCODER_SOURCES
    encoder/encodertests.cpp
)

set(SOURCES
    testmain.cpp
    ${ENCODER_SOURCES}
)

add_executable(manchester-tests
    ${SOURCES}
)
find_package(Catch2 CONFIG REQUIRED)
target_link_libraries(manchester-tests
    PRIVATE
        Catch2::Catch2
)

include(CTest)
include(Catch)
catch_discover_tests(manchester-tests)
