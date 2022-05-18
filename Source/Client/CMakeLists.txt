set(CLIENT_BINARY_DIR "${CMAKE_BINARY_DIR}/client-bin")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	# wxWidgets wants to use WinMain if built for Windows
	add_executable(Client WIN32)
else()
	add_executable(Client)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
	target_link_options(Client PRIVATE -static-libgcc -static-libstdc++ -pthread)
endif()

target_sources(Client PRIVATE main.cpp)
target_link_libraries(Client PRIVATE wx::core wx::base)

set_target_properties(Client PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
	RUNTIME_OUTPUT_DIRECTORY ${CLIENT_BINARY_DIR}
	LIBRARY_OUTPUT_DIRECTORY ${CLIENT_BINARY_DIR}
	ARCHIVE_OUTPUT_DIRECTORY ${CLIENT_BINARY_DIR}
)

target_include_directories(Client PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(Client PRIVATE
	main.cpp
	App.cpp
	App.h
)