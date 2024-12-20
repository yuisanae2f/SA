cmake_minimum_required(VERSION 3.10)
add_subdirectory(Core)
link_libraries(Core)

project(SA)

set(_SA_File_SIZE 100 CACHE STRING "Max File Length")
set(_SA_File_SIZE 300000000 CACHE STRING "Max File Length")

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
    "src_bin/NameGen.cpp"
    "src_bin/StrGetPostNum.cpp"

    "include_bin/_SA_File.hpp"
    "include_bin/_SA_NameGen.hpp"
    "include_bin/_SA_StrGetPostNum.h"
)

configure_file(
    ${PROJECT_SOURCE_DIR}/include_bin/_SA_FILE_SIZE.h.in 
    ${PROJECT_SOURCE_DIR}/include_bin/_SA_FILE_SIZE.h
)