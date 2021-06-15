cmake_minimum_required(VERSION 2.8)

project(counter-strike)


# std c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


# Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
# debugging flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")
# threads
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")


add_subdirectory("Common")
include_directories(${PROJECT_SOURCE_DIR}/Common)


add_subdirectory("Server/src")
include_directories(${PROJECT_SOURCE_DIR}/Server/src)


add_subdirectory("Client/src")
include_directories(${PROJECT_SOURCE_DIR}/Client/src)


add_executable(server "Server/main.cpp")
target_link_libraries(server server_classes common_classes)


add_executable(client "Client/main.cpp")
target_link_libraries(client client_classes common_classes)



