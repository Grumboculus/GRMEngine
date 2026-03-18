cmake_minimum_required(VERSION 3.14.0)
project(GRMEngine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(FetchContent)

# Fetch raylib directly from GitHub
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)

# Don't build examples or shared libraries for raylib by default
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(raylib)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(GRMEngine ${SOURCES})

# Link raylib to your engine
target_link_libraries(GRMEngine PRIVATE raylib)
target_include_directories(GRMEngine PRIVATE 
    ${raylib_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

