set(GCC_WARNINGS
    -Wall              # standard and reasonable baseline warnings
    -Wextra            # standard and reasonable baseline warnings
    -Wpedantic         # warn on anything not adhering to strict ISO C++ standards
    -Wcast-align       # warn on cast of pointers to types of larger alignment (eg. char* to int*)
    -Wunused           # warn on anything being unused
    -Wconversion       # warn on type conversion that may result in loss of data
    -Wnull-dereference # warn if a null dereference is detected
    -Wformat=2         # warn on security issues of functions that format output (like printf)
)
set(CLANG_WARNINGS
    -Wall              # standard and reasonable baseline warnings
    -Wextra            # standard and reasonable baseline warnings
    -Wpedantic         # warn on anything not adhering to strict ISO C++ standards
    -Wcast-align       # warn on cast of pointers to types of larger alignment (eg. char* to int*)
    -Wunused           # warn on anything being unused
    -Wconversion       # warn on type conversion that may result in loss of data
    -Wnull-dereference # warn if a null dereference is detected
    -Wformat=2         # warn on security issues of functions that format output (like printf)
    -Wshorten-64-to-32 # warn on illegal conversion from 64 bit data types to 32 bit data types
)
set(MSVC_WARNINGS
    /W4     # standard and reasonable baseline warnings
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
