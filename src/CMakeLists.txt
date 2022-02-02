# add src to include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(HEADERS
    Parser/parser.h
    Parser/endian.h
    Template/template.h
    Template/dom.h
    Template/gtml.h
    Data/data.h
    Data/roll.h
)
set(SOURCES
    Main/main.cpp
    Parser/endian.cpp
    Parser/parser.cpp
    Template/element.cpp
    Template/dom.cpp
    Layout/parseGGL.cpp
    Template/composeGTML.cpp
    Template/parseGTML.cpp
    Data/roll.cpp
)
add_executable(gryphon ${HEADERS} ${SOURCES})
install(
    TARGETS gryphon
    RUNTIME DESTINATION bin
)
