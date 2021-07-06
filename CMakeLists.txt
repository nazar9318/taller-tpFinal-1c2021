cmake_minimum_required(VERSION 2.8)

project(counter-strike)

# std c++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

add_subdirectory("./libs/box2d")
include_directories(${PROJECT_SOURCE_DIR}/libs/box2d)

# Flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -Werror -pedantic -Wno-reorder")
# debugging flags
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -DDEBUG -fno-inline ")
# threads
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# SDL
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lSDL2_image -lSDL2_ttf")



# QT
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)

#find_package(Qt5 REQUIRED COMPONENTS Widgets)




# COMMON

include_directories(${PROJECT_SOURCE_DIR}/Common)

include_directories(${PROJECT_SOURCE_DIR}/Common/Communication)
include_directories(${PROJECT_SOURCE_DIR}/Common/Event)
include_directories(${PROJECT_SOURCE_DIR}/Common/DataStructures)
include_directories(${PROJECT_SOURCE_DIR}/Common/Exception)
include_directories(${PROJECT_SOURCE_DIR}/Common/Thread)

add_subdirectory("Common")


# SERVER

include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers/Game)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers/Lobby)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/CommunicationThreads)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/Configuration)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/Exceptions)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/WorldObjects)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/WorldObjects/Block)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/WorldObjects/Character)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/WorldObjects/GroundMap)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/WorldObjects/Weapon)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/GameWorld/StepInformation)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/InitialProcess)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/MatchThread)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ServerEvents)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ServerEvents/Game)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ServerEvents/Game/FinalFase)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ServerEvents/Game/InitialFase)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ServerEvents/Game/PlayingFase)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ServerEvents/Lobby)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/YamlParser)

add_subdirectory("Server/src")

# CLIENT

include_directories(${PROJECT_SOURCE_DIR}/Client/src)

include_directories(${PROJECT_SOURCE_DIR}/Client/src/ClientEvents)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ClientEvents/Lobby)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ClientEvents/Game)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ClientEvents/Game/Move)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/CommunicationThreads)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/sdl)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/Initiator)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/Initiator/ui)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/Initiator/window)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Playing)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Initial)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Final)
add_subdirectory("Client/src")


add_subdirectory(Editor/map_editor)

add_executable(server "Server/main.cpp")
target_link_libraries(server server_classes common_classes yaml-cpp box2d)

add_executable(client "Client/main.cpp")
target_link_libraries(client client_classes common_classes SDL2 SDL2_image SDL2_ttf yaml-cpp)





#include_directories(${PROJECT_SOURCE_DIR}/login/login/src)
#add_subdirectory(login/login/src)

#add_executable(login_exe "login/login/main.cpp")
#target_link_libraries(login_exe login_files)
