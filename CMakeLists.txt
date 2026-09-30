cmake_minimum_required(VERSION 3.15)
project(ui LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(raylib CONFIG REQUIRED)

file(GLOB_RECURSE UI_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

add_library(ui STATIC ${UI_SOURCES})

target_include_directories(ui
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/external/layout
        ${CMAKE_CURRENT_SOURCE_DIR}/external/raygui/src

    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ui
)
target_compile_definitions(ui PUBLIC
    LAY_FLOAT=1
)

target_link_libraries(ui PUBLIC
    raylib
)
