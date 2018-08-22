
aux_source_directory(. SRC_LIST)
include_directories(include)
file(GLOB_RECURSE PROJECT_HEADERS include/*.h)
add_executable(TestServer  ${SRC_LIST} ${PROJECT_HEADERS})
target_link_libraries(TestServer XSocket)