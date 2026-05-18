cmake_minimum_required(VERSION 3.14.0)
project(GRMEngine VERSION 0.1.0 LANGUAGES C CXX)

include(FetchContent)

# GLFW
FetchContent_Declare(
  glfw
  GIT_REPOSITORY https://github.com/glfw/glfw.git
  GIT_TAG        3.4
)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(glfw)

# GLAD
FetchContent_Declare(
  glad
  GIT_REPOSITORY https://github.com/Dav1dde/glad.git
  GIT_TAG        v2.0.6
)
FetchContent_MakeAvailable(glad)
include("${glad_SOURCE_DIR}/cmake/GladConfig.cmake")
glad_add_library(glad REPRODUCIBLE API "gl:core=3.3")

# Sol2
FetchContent_Declare(
    sol2
    GIT_REPOSITORY https://github.com/ThePhD/sol2.git
    GIT_TAG v3.3.1
)
FetchContent_MakeAvailable(sol2)

file(GLOB_RECURSE SOURCES "*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "^(.*/)?build/.*")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(engine)
add_executable(GRMEngine ${SOURCES}
  engine/src/gal/opengl/GraphicsContextGL.cpp)

# Target linking
target_link_libraries(GRMEngine PUBLIC 
  glfw
  glad
  sol2
  Engine
)