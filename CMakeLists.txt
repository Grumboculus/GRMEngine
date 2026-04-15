cmake_minimum_required(VERSION 3.10.0)
project(GRMEngine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_subdirectory(engine)

add_executable(GRMEngine main.cpp)
target_link_libraries(GRMEngine PRIVATE Engine)