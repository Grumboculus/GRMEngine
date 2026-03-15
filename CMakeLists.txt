cmake_minimum_required(VERSION 3.10.0)
project(GRMEngine VERSION 0.1.0 LANGUAGES C CXX)

file(GLOB_RECURSE SOURCES "*.cpp")

add_executable(GRMEngine ${SOURCES})

