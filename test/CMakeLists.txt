cmake_minimum_required(VERSION 3.24)
project(engine-tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_Declare(
        fmt
        URL https://github.com/fmtlib/fmt/releases/download/9.1.0/fmt-9.1.0.zip
)

FetchContent_MakeAvailable(googletest fmt)

file(GLOB_RECURSE TEST_SOURCE_FILES CONFIGURE_DEPENDS ./*.cpp)
add_executable(${PROJECT_NAME} ${TEST_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
        GTest::gmock
        GTest::gtest_main
        engine
        fmt
        SDL2
        SDL2_image
        )

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
