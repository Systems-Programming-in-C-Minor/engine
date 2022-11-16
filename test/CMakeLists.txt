cmake_minimum_required(VERSION 3.23)
project(engine-tests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main
)

FetchContent_MakeAvailable(googletest)

file(GLOB_RECURSE TEST_SOURCE_FILES CONFIGURE_DEPENDS ./*.cpp)
file(GLOB_RECURSE TEST_HEADER_FILES CONFIGURE_DEPENDS ./*.hpp)
add_executable(${PROJECT_NAME} ${TEST_SOURCE_FILES} ${TEST_HEADER_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE
        GTest::gmock
        GTest::gtest_main
        box2d
        engine
        )

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})
