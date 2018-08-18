file(GLOB_RECURSE CORE_SRC "*.cpp" "*.hpp" "*.h")

add_executable(core ${CORE_SRC})

add_dependencies(core rendering)

target_link_libraries(core
    rendering
    SDL2::SDL2main
    SDL2::SDL2
)
