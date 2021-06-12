cmake_minimum_required(VERSION 2.4)
project(server)


# Including Box2D
include_directories(./libs/box2d)
file(GLOB_RECURSE BOX2D_SRCS ./box2d/src/*.cpp)

add_executable(server "src/main.cpp")
