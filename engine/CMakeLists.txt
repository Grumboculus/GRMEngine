cmake_minimum_required(VERSION 3.10.0)
project(Engine VERSION 0.1.0 LANGUAGES C CXX)

# Create the Engine library
file(GLOB_RECURSE ENGINE_SOURCES "src/*.cpp")
if(ENGINE_SOURCES)
	add_library(Engine ${ENGINE_SOURCES})
else()
	add_library(Engine INTERFACE)
endif()

target_compile_features(Engine INTERFACE cxx_std_20)

# Any project that links to 'Engine' will automatically get this include directory
if(TARGET Engine)
	if(ENGINE_SOURCES)
		target_include_directories(Engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
	else()
		target_include_directories(Engine INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
	endif()
endif()