include_directories(
    ../
    ../engine3d-physics
)

set(
    all_headers
    ../engine3d-physics/Core/core.h
)

set(
    all_src
    engine3d-physics/Core/core.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src})