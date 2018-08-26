file(GLOB_RECURSE RENDERING_SRC "*.cpp" "*.hpp" "*.h")

add_library(rendering ${RENDERING_SRC})

target_link_libraries(rendering
    glm
    SDL2::SDL2
    SDL_image::SDL_image
    glew::glew
)
