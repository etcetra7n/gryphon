cmake_minimum_required(VERSION 3.2)
project(Gryphon VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -Wextra -Wpedantic")

if(TARGET_PLATFORM STREQUAL "win32")
    set(CMAKE_CXX_COMPILER "x86_64-w64-mingw32-g++")
    set(CMAKE_C_COMPILER "x86_64-w64-mingw32-gcc")
endif()

include_directories(
    include
    src
)
set(HEADERS
    src/gryphon.h
    src/Parser/endian.h
    src/Parser/trim_ends.h
    src/Parser/parser.h
    src/Template/gtml.h
    src/Template/dom.h
    src/Data/roll.h
)
set(SOURCES
    src/Main/main.cpp
    src/Graph/raster.cpp
    src/Export/export_bmp.cpp
    src/Parser/endian.cpp
    src/Parser/trim_ends.cpp
    src/Parser/parser.cpp
    src/Template/element.cpp
    src/Template/dom.cpp
    src/Layout/parse_ggl.cpp
    src/Template/compose_gtml.cpp
    src/Template/parse_gtml.cpp
)

add_executable(gryphon ${HEADERS} ${SOURCES})
install(
    TARGETS gryphon
    RUNTIME DESTINATION bin
)
