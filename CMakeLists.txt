cmake_minimum_required(VERSION 3.2)
project(Gryphon VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

if(CMAKE_BUILD_TYPE STREQUAL "")
    set(CMAKE_BUILD_TYPE "Release")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Og -g")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -g")
endif()
if(CMAKE_BUILD_TYPE STREQUAL "MinSizeRel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os")
endif()

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
    src/Parser/endian.cpp
    src/Layout/parse_ggl.cpp
    src/Template/element.cpp
    src/Template/gtemplate.cpp
    src/Template/compose_gtml.cpp
    src/Template/parse_gtml.cpp
)
set(HEADERS
    src/gryphon.h
    src/Parser/parser.h
    src/Parser/trim_ends.h
    src/Parser/endian.h
    src/Template/gtml.h
    src/Template/element.h
    src/Template/gtemplate.h
    src/Data/gdata.h
)

add_executable(gryphon ${SOURCES} ${HEADERS})
install(
    TARGETS gryphon
    RUNTIME DESTINATION bin
)
