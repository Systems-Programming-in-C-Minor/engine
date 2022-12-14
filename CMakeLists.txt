cmake_minimum_required(VERSION 3.23)
project(engine)

option(ENGINE_TEST "Generate the test target." ON)
option(ENGINE_SAMPLE "Generate a sample UnEngine project." ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "Build the Box2D unit tests")
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "Build the Box2D testbed")

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif ()

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        fmt
        URL https://github.com/fmtlib/fmt/releases/download/9.1.0/fmt-9.1.0.zip
)

FetchContent_Declare(
        box2d
        GIT_REPOSITORY https://github.com/erincatto/box2d.git
        GIT_TAG v2.4.1
        GIT_PROGRESS TRUE
)

FetchContent_Declare(
        SDL2pp
        GIT_REPOSITORY https://github.com/libSDL2pp/libSDL2pp.git
        GIT_TAG 0.17.0
        GIT_PROGRESS TRUE
)

FetchContent_Declare(
        tinyxml2
        GIT_REPOSITORY https://github.com/leethomason/tinyxml2.git
        GIT_TAG 9.0.0
        GIT_PROGRESS TRUE
)

FetchContent_Declare(
        json
        URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz
)

# This allows libSDL2pp to find the local SDL2 libraries.
list(APPEND CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH}/SDL2)
list(APPEND CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH}/SDL2_image/x86_64-w64-mingw32/include)
list(APPEND CMAKE_PREFIX_PATH $ENV{CMAKE_PREFIX_PATH}/SDL2_image/x86_64-w64-mingw32/lib)

set(SDL2PP_WITH_IMAGE ON) # if you need SDL_image support
set(SDL2PP_WITH_MIXER OFF) # if you need SDL_mixer support
set(SDL2PP_WITH_TTF OFF) # if you need SDL_ttf support

FetchContent_MakeAvailable(fmt box2d SDL2pp tinyxml2 json)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS ./src/*.cpp)
file(GLOB_RECURSE HEADER_FILES CONFIGURE_DEPENDS ./include/*.hpp)
file(GLOB_RECURSE PRIVATE_HEADER_FILES CONFIGURE_DEPENDS ./src/*.hpp)

if (WIN32)
    set(SDL2_IMAGE_LIBRARIES SDL2_image::SDL2_image)
else ()
    set(SDL2_IMAGE_LIBRARIES SDL2_image)
endif ()

add_library(engine STATIC ${SOURCE_FILES} ${HEADER_FILES} ${PRIVATE_HEADER_FILES})

target_compile_definitions(engine PRIVATE _USE_MATH_DEFINES)

target_include_directories(engine PUBLIC include)

target_link_libraries(engine PRIVATE
        fmt::fmt
        box2d
        SDL2pp::SDL2pp
        tinyxml2::tinyxml2
        nlohmann_json::nlohmann_json
        )

if (ENGINE_TEST)
    add_subdirectory(test)
    enable_testing()
endif ()

if (ENGINE_SAMPLE)
    add_subdirectory(sample)
endif ()
