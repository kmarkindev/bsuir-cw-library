set(APISERVER_BINARY_DIR "${CMAKE_BINARY_DIR}/api-server-bin")

find_path(JWT_CPP_INCLUDE_DIRS "jwt-cpp/base.h")
find_package(Drogon CONFIG REQUIRED)
find_path(PICOJSON_INCLUDE_DIRS "picojson/picojson.h")
find_package(unofficial-libmariadb CONFIG REQUIRED)

add_executable(ApiServer)
target_sources(ApiServer PRIVATE main.cpp)
target_link_libraries(ApiServer PRIVATE Drogon::Drogon unofficial::libmariadb)
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
	target_link_libraries(ApiServer PRIVATE iphlpapi.lib)
endif()
target_include_directories(ApiServer PRIVATE ${JWT_CPP_INCLUDE_DIRS} ${PICOJSON_INCLUDE_DIRS})

set_target_properties(ApiServer PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
	RUNTIME_OUTPUT_DIRECTORY ${APISERVER_BINARY_DIR}
	LIBRARY_OUTPUT_DIRECTORY ${APISERVER_BINARY_DIR}
	ARCHIVE_OUTPUT_DIRECTORY ${APISERVER_BINARY_DIR}
)

aux_source_directory(Controllers CTL_SRC)
aux_source_directory(Filters FILTER_SRC)
aux_source_directory(Plugins PLUGIN_SRC)
aux_source_directory(Models MODEL_SRC)
aux_source_directory(Services SERVICES_SRC)
aux_source_directory(Repositories REPOS_SRC)
aux_source_directory(Helpers HELPERS_SRC)
aux_source_directory(Validators VALIDATORS_SRC)

drogon_create_views(ApiServer
    ${CMAKE_CURRENT_SOURCE_DIR}/Views
    ${APISERVER_BINARY_DIR}
)
target_include_directories(ApiServer PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}
)
target_sources(ApiServer PRIVATE
	${SRC_DIR}
	${CTL_SRC}
	${FILTER_SRC}
	${PLUGIN_SRC}
	${MODEL_SRC}
	${SERVICES_SRC}
	${REPOS_SRC}
	${HELPERS_SRC}
	${VALIDATORS_SRC}
)

# Copy config example to binary folder
add_custom_command(TARGET ApiServer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_CURRENT_SOURCE_DIR}/config.json.example $<TARGET_FILE_DIR:ApiServer>/configs/config.json.example)

# Copy database queries to binary folder
add_custom_command(TARGET ApiServer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/Database $<TARGET_FILE_DIR:ApiServer>/database)

# Copy static files to binary folder
add_custom_command(TARGET ApiServer POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory
	${CMAKE_CURRENT_SOURCE_DIR}/Static $<TARGET_FILE_DIR:ApiServer>/static)

# ##############################################################################
# uncomment the following line for dynamically loading views 
# set_property(TARGET ${PROJECT_NAME} PROPERTY ENABLE_EXPORTS ON)
# ##############################################################################