cmake_minimum_required(VERSION 3.1.0)

project(Gryphon
    VERSION 0.1.0
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 14)

set(GCC_WARNINGS
    -Wall
    -Wextra
    -Wpedantic
    -Wcast-align       # warn for potential performance problem casts
    -Wunused           # warn on anything being unused
    -Wconversion       # warn on type conversion that may lose data
    -Wnull-dereference # warn if a null dereference is detected
    -Wformat=2         # warn on security issues of functions that format output (like printf)
    -Wnarrowing        # warn on illegal conversions like 64 bit data type to 32 bit data types or similar
)
set(CLANG_WARNINGS
    -Wall
    -Wextra
    -Wpedantic
    -Wcast-align       # warn for potential performance problem casts
    -Wunused           # warn on anything being unused
    -Wconversion       # warn on type conversion that may lose data
    -Wnull-dereference # warn if a null dereference is detected
    -Wformat=2         # warn on security issues of functions that format output(ie printf)
    -Wshorten-64-to-32 # warn on illegal conversion from 64 bit data type to 32 bit data types
)
set(MSVC_WARNINGS
    /W4     # Baseline reasonable warnings
    /w14242 # 'identifier': conversion from 'type1' to 'type2', possible loss of data
    /w14311 # 'variable' pointer truncation from 'type1' to 'type2'
    /w14826 # Conversion from 'type1' to 'type2' is sign-extented. This may cause
            # unexpected runtime behavior
)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(${GCC_WARNINGS})
elseif(CMAKE_CXX_COMPILER_ID STREQUAL ".*Clang") # eg Clang or AppleClang
    add_compile_options(${CLANG_WARNINGS})
elseif(MSVC)
    add_compile_options(${MSVC_WARNINGS})
endif()

#Set output directories of all build types to one place
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY                "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG          "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE        "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_MINSIZEREL     "${CMAKE_BINARY_DIR}")

add_subdirectory(src)
