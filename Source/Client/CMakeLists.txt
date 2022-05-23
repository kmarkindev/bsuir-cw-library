set(CLIENT_BINARY_DIR "${CMAKE_BINARY_DIR}/client-bin")

find_path(CPP_HTTPLIB_INCLUDE_DIRS "httplib.h")

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	# wxWidgets wants to use WinMain if built for Windows
	add_executable(Client WIN32)
else()
	add_executable(Client)
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows" AND CMAKE_HOST_SYSTEM_NAME STREQUAL "Linux")
	target_link_options(Client PRIVATE -static -s)
	target_compile_options(Client PRIVATE -Os)
endif()

target_sources(Client PRIVATE main.cpp)
target_link_libraries(Client PRIVATE wx::core wx::base wx::aui)
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
aux_source_directory(Helpers HELPERS_SRC)
aux_source_directory(Services/Api APTSERVICES_SRC)
aux_source_directory(Services/HttpClient HTTPCLIENT_SRC)
aux_source_directory(Exceptions EXCEPTIONS_SRC)
aux_source_directory(Windows WINDOWS_SRC)
aux_source_directory(Windows/Authors WINDOWS_AUTHORS_SRC)
aux_source_directory(Windows/Publishers WINDOWS_PUBLISHERS_SRC)
aux_source_directory(Windows/Readers WINDOWS_READERS_SRC)
aux_source_directory(Windows/Books WINDOWS_BOOKS_SRC)
aux_source_directory(Utils UTILS_SRC)

target_sources(Client PRIVATE
	main.cpp
	App.cpp
	App.h
	AppState.cpp
	AppState.h
	Windows/WxBuilder/ClientWindows.cpp
	Windows/WxBuilder/ClientWindows.h
	${REPOS_SRC}
	${EXCEPTIONS_SRC}
	${MODELS_SRC}
	${APTSERVICES_SRC}
	${WINDOWS_AUTHORS_SRC}
	${WINDOWS_PUBLISHERS_SRC}
	${WINDOWS_BOOKS_SRC}
	${WINDOWS_READERS_SRC}
	${HELPERS_SRC}
	${HTTPCLIENT_SRC}
	${DTO_SRC}
	${WINDOWS_SRC}
	${UTILS_SRC}
)