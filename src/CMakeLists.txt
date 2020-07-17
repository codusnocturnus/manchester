cmake_minimum_required(VERSION 3.17)

project(hello
    LANGUAGES CXX
)

find_package(fmt CONFIG REQUIRED)
add_executable(hello
    hellofmt.cpp
)
target_link_libraries(hello
    PRIVATE
        fmt::fmt
)

add_executable(encoder
    encoder.cpp
    encoder/encodercontext.cpp
    encoder/quiescenthistate.cpp
    encoder/quiescentlostate.cpp
)
target_link_libraries(encoder
    PRIVATE
        fmt::fmt
)
set_target_properties(encoder
    PROPERTIES
        CXX_STANDARD 20
        CXX_STANDARD_REQUIRED TRUE
)
