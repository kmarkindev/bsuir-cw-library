set(CLIENT_BINARY_DIR "${CMAKE_BINARY_DIR}/client-bin")

find_path(CPP_HTTPLIB_INCLUDE_DIRS "httplib.h")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	# wxWidgets wants to use WinMain if built for Windows
	add_executable(Client WIN32)
else()
	add_executable(Client)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
	target_link_options(Client PRIVATE -static)
	target_compile_options(Client PRIVATE -Os)
endif()

target_sources(Client PRIVATE main.cpp)
target_link_libraries(Client PRIVATE wx::core wx::base)
target_include_directories(Client PRIVATE ${CPP_HTTPLIB_INCLUDE_DIRS})

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

aux_source_directory(Repository REPOS_SRC)
aux_source_directory(Models MODELS_SRC)
aux_source_directory(Dto DTO_SRC)
aux_source_directory(Services/Api APTSERVICES_SRC)
aux_source_directory(Services/HttpClient HTTPCLIENT_SRC)
aux_source_directory(Exceptions EXCEPTIONS_SRC)

target_sources(Client PRIVATE
	main.cpp
	App.cpp
	App.h
	${REPOS_SRC}
	${EXCEPTIONS_SRC}
	${MODELS_SRC}
	${APTSERVICES_SRC}
	${HTTPCLIENT_SRC}
	${DTO_SRC}
)