cmake_minimum_required(VERSION 3.11)
project("socketdemo")
add_definitions(-DUNICODE -D_UNICODE)
set(CMAKE_CONFIGURATION_TYPES "Debug;Release")
include_directories("XSocket/include")
include_directories("TestLib/include")
add_subdirectory(XSocket)
add_subdirectory(TestLib)

add_subdirectory(TestSocket)



#aux_source_directory(. SRC_LIST)
#include_directories(include)
#file(GLOB_RECURSE PROJECT_HEADERS include/*.h)
#add_executable(Templates ${SRC_LIST} ${PROJECT_HEADERS})
