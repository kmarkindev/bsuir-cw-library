cmake_minimum_required(VERSION 3.16)

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	message(FATAL_ERROR "Cmake generation in source dir is not allowed. Make an out of source build instead.")
endif()

project(bsuir-cw-library LANGUAGES CXX)

# Setup conan
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(NO_OUTPUT_DIRS)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
	add_compile_definitions(DEBUG_BUILD NOMINMAX)
endif()

# Create target with common packages
add_library(CommonPackages INTERFACE)
target_include_directories(CommonPackages INTERFACE
	${CONAN_INCLUDE_DIRS_OPENSSL}
	${CONAN_INCLUDE_DIRS_ZLIB}
	${CONAN_INCLUDE_DIRS_LIBCURL}
)
target_link_libraries(CommonPackages INTERFACE
	${CONAN_LIBS_OPENSSL}
	${CONAN_LIBS_ZLIB}
	${CONAN_LIBS_LIBCURL}
)

# Create target with Client packages
add_library(ClientPackages INTERFACE)
target_include_directories(ClientPackages INTERFACE
	${CONAN_INCLUDE_DIRS_CPP-HTTPLIB}
	${CONAN_INCLUDE_DIRS_CRYPTOPP}
	${CONAN_INCLUDE_DIRS_WXWIDGETS}
)
target_link_libraries(ClientPackages INTERFACE
	${CONAN_LIBS_CPP-HTTPLIB}
	${CONAN_LIBS_CRYPTOPP}
	${CONAN_LIBS_WXWIDGETS}
)

# Create target with Server packages
add_library(ServerPackages INTERFACE)
target_include_directories(ServerPackages INTERFACE
	${CONAN_INCLUDE_DIRS_JSONCPP}
	${CONAN_INCLUDE_DIRS_PICOJSON}
	${CONAN_INCLUDE_DIRS_MARIADB-CONNECTOR-C}
	${CONAN_INCLUDE_DIRS_JWT-CPP}
	${CONAN_INCLUDE_DIRS_LIBUUID}
)
target_link_libraries(ServerPackages INTERFACE
	${CONAN_LIBS_JSONCPP}
	${CONAN_LIBS_PICOJSON}
	${CONAN_LIBS_MARIADB-CONNECTOR-C}
	${CONAN_LIBS_JWT-CPP}
	${CONAN_LIBS_LIBUUID}
)

add_subdirectory(Packages)
add_subdirectory(Source)