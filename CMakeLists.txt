cmake_minimum_required(VERSION 3.24)
project(engine)

option(ENGINE_TEST "Generate the test target." ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        fmt
        URL https://github.com/fmtlib/fmt/releases/download/9.1.0/fmt-9.1.0.zip
)

FetchContent_MakeAvailable(fmt)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)

include_directories(engine include)
add_library(engine SHARED ${SOURCE_FILES})

if (ENGINE_TEST)
    add_subdirectory(test)
endif ()
