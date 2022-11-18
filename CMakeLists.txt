cmake_minimum_required(VERSION 3.23)
project(engine)

option(ENGINE_TEST "Generate the test target." ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Build the Box2D unit tests")
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "Build the Box2D testbed")

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif ()

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        fmt
        URL https://github.com/fmtlib/fmt/releases/download/9.1.0/fmt-9.1.0.zip
)

FetchContent_Declare(box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(fmt box2d)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)

if (WIN32)
    set(SDL2_IMAGE_LIBRARIES SDL2_image::SDL2_image)
else ()
    set(SDL2_IMAGE_LIBRARIES SDL2_image)
endif ()

add_library(engine STATIC ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(engine PUBLIC include)
target_link_libraries(engine PRIVATE
        ${SDL2_LIBRARIES}
        ${SDL2_IMAGE_LIBRARIES}
        fmt::fmt
        box2d
        )

if (ENGINE_TEST)
    add_subdirectory(test)
    enable_testing()
endif ()
