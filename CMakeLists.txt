cmake_minimum_required(VERSION 3.23)
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
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./src/*.hpp)

add_library(engine STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(engine PUBLIC include)
target_link_libraries(engine PRIVATE
        ${SDL2_LIBRARIES}
        SDL2_image::SDL2_image
        fmt::fmt
        )

if (ENGINE_TEST)
    add_subdirectory(test)
endif ()
