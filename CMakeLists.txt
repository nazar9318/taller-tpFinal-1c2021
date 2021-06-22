cmake_minimum_required(VERSION 2.8)

project(counter-strike)

# std c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory("./libs/box2d")
include_directories(${PROJECT_SOURCE_DIR}/libs/box2d)

# Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic")
# debugging flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")
# threads
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lBox2D")




add_subdirectory("Common")
include_directories(${PROJECT_SOURCE_DIR}/Common)

add_subdirectory("Server/src")
include_directories(${PROJECT_SOURCE_DIR}/Server/src)

add_subdirectory("Client/src")
include_directories(${PROJECT_SOURCE_DIR}/Client/src)




# set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lBox2D")
# add_subdirectory(./libs/box2d)
# include_directories(./libs/box2d)
# file(GLOB_RECURSE BOX2D_SRCS ./libs/box2d/src *.cpp)

# add_library(box2D STATIC ${BOX2D_SRCS})














# COMENTO TESTS PORQUE NO EXISTE LA CARPETA.
find_package(Qt5Widgets)


# add_subdirectory("Tests/src")
# include_directories(${PROJECT_SOURCE_DIR}/Tests/src)

add_executable(server "Server/main.cpp")
target_link_libraries(server server_classes common_classes yaml-cpp box2d)

add_executable(client "Client/main.cpp")
target_link_libraries(client client_classes common_classes SDL2 SDL2_image yaml-cpp Qt5::Widgets)
