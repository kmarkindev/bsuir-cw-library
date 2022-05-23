cmake_minimum_required(VERSION 3.16)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Cmake generation in source dir is not allowed. Make an out of source build instead.")
endif()

# Config vcpkg
set(VCPKG_CRT_LINKAGE "static")

message(STATUS "Setting ${VCPKG_TARGET_TRIPLET} triplet")

project(bsuir-cw-library LANGUAGES CXX)

if(NOT CMAKE_SYSTEM_NAME STREQUAL "Windows" AND NOT CMAKE_SYSTEM_NAME STREQUAL "Linux")
	message(FATAL_ERROR "Trying to compile for unsupported OS '${CMAKE_SYSTEM_NAME}'")
endif()

# Since we are using static linkage for packages, we need to use the same one here
if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND MSVC)
	if(CMAKE_BUILD_TYPE STREQUAL "Debug")
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebug")
	else()
		set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded")
	endif()
endif()

message(STATUS "Importing in-source packages")
add_subdirectory(Packages)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	# Add definition for our internal use
	add_compile_definitions(DEBUG_BUILD)
endif()
add_compile_definitions(NOMINMAX)

add_subdirectory(Source)