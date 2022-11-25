project(engine_sample)

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Links libstd statically, but still doesn't work. Must supply libstdc++-6.dll
# target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

target_link_libraries(${PROJECT_NAME} PRIVATE
        fmt::fmt
        box2d
        SDL2pp::SDL2pp
        engine
        )

install(TARGETS engine_sample RUNTIME DESTINATION bin)

# TODO Unsure whether this needs to be done on POSIX
install(FILES ${FETCHCONTENT_BASE_DIR}/sdl2pp-build/libSDL2pp.dll DESTINATION bin)