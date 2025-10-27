cmake_minimum_required(VERSION 3.10)
project(TwelveProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(twelve_program
    main.cpp
    Array.cpp
    Twelve.cpp
)

add_executable(twelve_tests
    tests.cpp
    Array.cpp
    Twelve.cpp
)

target_include_directories(twelve_program PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(twelve_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
