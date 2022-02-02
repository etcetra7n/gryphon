cmake_minimum_required(VERSION 3.1.0)
project(Gryphon
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 14)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(
    src
)
set(HEADERS
    src/Parser/parser.h
    src/Parser/endian.h
    src/Template/template.h
    src/Template/dom.h
    src/Template/gtml.h
    src/Data/data.h
    src/Data/roll.h
)
set(SOURCES
    src/Main/main.cpp
    src/Parser/endian.cpp
    src/Parser/parser.cpp
    src/Template/element.cpp
    src/Template/dom.cpp
    src/Layout/parseGgl.cpp
    src/Template/composeGtml.cpp
    src/Template/parseGtml.cpp
    src/Data/roll.cpp
)

add_executable(gryphon ${HEADERS} ${SOURCES})
install(
    TARGETS gryphon
    RUNTIME DESTINATION bin
)
