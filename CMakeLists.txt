cmake_minimum_required(VERSION 3.2.0)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/CMakePCHCompiler)
include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.19.139.tar.gz"
    SHA1 "31a0f9f2fb1b7dc44c7c19656e2a8acabe284959"
)
project(Snail CXX CXXPCH)
hunter_add_package(Boost COMPONENTS math)
find_package(Boost CONFIG REQUIRED math_c99 math_c99f math_c99l math_tr1 math_tr1f math_tr1l)
add_subdirectory(src) 