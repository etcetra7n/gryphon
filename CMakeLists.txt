cmake_minimum_required(VERSION 3.2)
project(Gryphon VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -Wall")

set(SOURCES
    src/Main/main.cpp
    src/Graph/raster.cpp
    src/Export/export_bmp.cpp
    src/Template/element.cpp
    src/Template/tree.cpp
    src/Template/parser.cpp
    src/Template/parse_ggl.cpp
    src/Template/trim_ends.cpp
    src/Template/compose_gtml.cpp
)
set(HEADERS
    src/gryphon.h
    src/Template/gtml.h
    src/Template/element.h
    src/Template/tree.h
    src/Template/parser.h
)
include_directories(
    include
    src
)
add_executable(gryphon ${SOURCES} ${HEADERS})
