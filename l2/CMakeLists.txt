cmake_minimum_required(VERSION 3.14)
project(TwelveSystem)

set(CMAKE_CXX_STANDARD 17)

add_executable(twelve_system main.cpp Array.cpp Twelve.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9fdab597d271efac4ddfcbd.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(twelve_tests tests.cpp Array.cpp Twelve.cpp)
target_link_libraries(twelve_tests gtest_main gmock)

include(GoogleTest)
gtest_discover_tests(twelve_tests)