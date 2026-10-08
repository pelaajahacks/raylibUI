cmake_minimum_required(VERSION 3.15)
project(ui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

# layout.h and raygui.h are single-header libraries: exactly one translation
# unit per library defines the implementation macro before including the
# header (src/ui/Layout.cpp -> LAY_IMPLEMENTATION, src/ui/Panel.cpp ->
# RAYGUI_IMPLEMENTATION). Everything else includes them for declarations
# only, which is why the implementation lives here instead of in each
# consumer -- linking ui is enough to resolve lay_* and Gui*.
add_library(ui STATIC
    src/ui/Button.cpp
    src/ui/Label.cpp
    src/ui/Layout.cpp
)

target_include_directories(ui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/layout
        ${CMAKE_CURRENT_SOURCE_DIR}/external/raygui/src
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ui
)

# PUBLIC so every consumer compiles layout.h with the same lay_scalar width;
# a mismatch would change the lay_context layout between translation units.
target_compile_definitions(ui PUBLIC
    LAY_FLOAT=1
)

target_link_libraries(ui PUBLIC
    raylib
)
