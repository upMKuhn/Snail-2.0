cmake_minimum_required(VERSION 3.9.0)
project(Snail)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/CMakePCHCompiler)
SET(MSVC TRUE)

add_subdirectory(src)