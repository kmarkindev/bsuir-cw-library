set(CLIENT_BINARY_DIR "${CMAKE_BINARY_DIR}/client-bin")

find_package(wxWidgets REQUIRED)

if(WIN32)
	add_executable(Client WIN32)
else()
	add_executable(Client)
endif()

target_sources(Client PRIVATE main.cpp)
target_compile_definitions(Client PRIVATE ${wxWidgets_DEFINITIONS} "$<$<CONFIG:DEBUG>:${wxWidgets_DEFINITIONS_DEBUG}>")
target_include_directories(Client PRIVATE ${wxWidgets_INCLUDE_DIRS})
target_link_libraries(Client PRIVATE ${wxWidgets_LIBRARIES})

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