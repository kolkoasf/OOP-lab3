cmake_minimum_required(VERSION 3.14)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(figures_lib STATIC
    src/point.cpp
    src/figure.cpp
    src/square.cpp
    src/rectangle.cpp
    src/trapezoid.cpp
    src/figure_array.cpp
)

target_include_directories(figures_lib PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

find_package(GTest QUIET)

if (NOT GTest_FOUND)
    message(STATUS "Downloading GTest...")
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.16.0
    )
    FetchContent_MakeAvailable(googletest)
    message(STATUS "GTest downloaded successfully!")
endif ()

enable_testing()

add_executable(figures_test tests/test_figures.cpp)
target_link_libraries(figures_test PRIVATE 
    figures_lib 
    GTest::gtest_main
)

gtest_discover_tests(figures_test)