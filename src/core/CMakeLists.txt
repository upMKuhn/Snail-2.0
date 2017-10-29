file(GLOB_RECURSE CORE_SRC "*.cpp" "*.hpp" "*.h")

add_executable(core ${CORE_SRC})

target_link_libraries(core
    SDL2::SDL2main
    SDL2::SDL2
)

target_link_libraries(core
  Boost::math_c99
  Boost::math_c99f
  Boost::math_c99l
  Boost::math_tr1
  Boost::math_tr1f
  Boost::math_tr1l
)