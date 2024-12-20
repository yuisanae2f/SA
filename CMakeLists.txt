cmake_minimum_required(VERSION 3.10)
project(SA)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(Core)
link_libraries(Core)


set(_SA_File_SIZE 8000000 CACHE STRING "Max File Length")

ae2f_CoreLibTent(
    libSA
    ${ae2f_LIBPREFIX}
    include SA 
    "src/SA.c"
    "include/SA.h"
)

link_libraries(libSA)
include_directories(include_bin)

add_executable(
    SA
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