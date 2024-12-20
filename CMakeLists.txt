cmake_minimum_required(VERSION 3.10)
add_subdirectory(Core)
link_libraries(Core)

ae2f_CoreLibTent(
    SA
    ${ae2f_LIBPREFIX}
    include SA 
    "src/SA.c"
    "include/SA.h"
)

link_libraries(SA)
include_directories(include_bin)

add_executable(
    SepAdd
    "src_bin/main.cpp"
)