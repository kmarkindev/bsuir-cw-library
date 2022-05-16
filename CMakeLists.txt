cmake_minimum_required(VERSION 3.16)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Cmake generation in source dir is not allowed. Make an out of source build instead.")
endif()

# Config vcpkg
if(WIN32)
	set(VCPKG_TARGET_TRIPLET "x64-windows-static")
else()
	set(VCPKG_TARGET_TRIPLET "x64-linux")
endif()

project(bsuir-cw-library LANGUAGES CXX)

# Since we are using static linkage for packages, we need to use the same one here
if(MSVC)
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
	else()
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
	endif()
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_definitions(DEBUG_BUILD)
endif()
add_compile_definitions(NOMINMAX)

add_subdirectory(Source)