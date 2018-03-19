cmake_minimum_required(VERSION 3.0)
MESSAGE(${CMAKE_SOURCE_DIR})
include(${CMAKE_SOURCE_DIR}/CMake/HunterGate.cmake)
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.20.24.tar.gz"
    SHA1 "3e2037a462bcf2ec3440f60298d933e74ffd4df3"
)
set(HUNTER_STATUS_DEBUG ON)
set(HUNTER_TLS_VERIFY OFF)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

project(Snail)


#Dependencies


hunter_add_package(SDL2)
find_package(SDL2 CONFIG REQUIRED)

hunter_add_package(SDL_image)
find_package(SDL_image CONFIG REQUIRED)

add_subdirectory(src) 