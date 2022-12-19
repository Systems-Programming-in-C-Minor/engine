project(engine_sample)

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)

# Links libstd statically, but still doesn't work. Must supply libstdc++-6.dll
# target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)
target_compile_definitions(engine_sample PRIVATE _USE_MATH_DEFINES)

target_link_libraries(${PROJECT_NAME} PRIVATE
        engine
        )

if(WIN32)
    install(TARGETS engine_sample RUNTIME DESTINATION bin)
    install(FILES ${FETCHCONTENT_BASE_DIR}/sdl2pp-build/libSDL2pp.dll DESTINATION bin)
endif()


add_custom_command(
        TARGET engine_sample PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_CURRENT_SOURCE_DIR}/assets
        ${CMAKE_CURRENT_BINARY_DIR}/assets
)