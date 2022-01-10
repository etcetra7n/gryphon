cmake_minimum_required(VERSION 3.2)
project(Gryphon VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3 -Wall")

include_directories(
    include
    src
)
set(SOURCES
    src/Main/main.cpp
    src/Graph/raster.cpp
    src/Export/export_bmp.cpp
    src/Parser/parser.cpp
    src/Parser/trim_ends.cpp
    src/Layout/parse_ggl.cpp
    src/Template/element.cpp
    src/Template/template.cpp
    src/Template/compose_gtml.cpp
    src/Template/parse_gtml.cpp
)
set(HEADERS
    src/gryphon.h
    src/Parser/parser.h
    src/Parser/trim_ends.h
    src/Template/gtml.h
    src/Template/element.h
    src/Template/template.h
)

add_executable(grn ${SOURCES} ${HEADERS})
