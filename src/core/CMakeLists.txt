file(GLOB_RECURSE CORE_SRC "*.cpp" "*.hpp" "*.h")
add_library(coreDemo SHARED ${CORE_SRC})