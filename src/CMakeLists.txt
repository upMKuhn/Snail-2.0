file(GLOB CORE_SRC
    "*.h"
    "*.cpp"
)
add_subdirectory (core)
target_precompiled_header(core core/prefix.h)
