cmake_minimum_required(VERSION 3.10.0)
project(Engine VERSION 0.1.0 LANGUAGES C CXX)

# Create the Engine library
file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")
add_library(Engine ${ENGINE_SOURCES})

# Any project that links to 'Engine' will automatically get this include directory
target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)