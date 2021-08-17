add_library(firefly_stdlib
    ./include/stl/cstdlib/cstd.cpp
    ./include/stl/cstdlib/stdio.cpp
    ./include/stl/cstdlib/cmath.cpp
)

target_include_directories(firefly_stdlib
    PUBLIC ./include
    PUBLIC ./include/stl
    PUBLIC ./include/stl/cstdlib
)
