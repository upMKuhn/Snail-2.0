file(GLOB_RECURSE CORE_SRC "*.cpp" "*.hpp" "*.h")

add_executable(core ${CORE_SRC})

target_link_libraries(core
    SDL2::SDL2main
    SDL2::SDL2
)
