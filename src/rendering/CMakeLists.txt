file(GLOB_RECURSE RENDERING_SRC "*.cpp" "*.hpp" "*.h")

add_library(rendering ${RENDERING_SRC})

target_link_libraries(rendering
    SDL2::SDL2main
    SDL2::SDL2
)
