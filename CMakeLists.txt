cmake_minimum_required(VERSION 2.8)

project(counter-strike)

if(USR)
 add_definitions(-DUSR_MODE=1)
endif()

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
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_gfx")



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
include_directories(${PROJECT_SOURCE_DIR}/Common/Paths)

add_subdirectory("Common")


# SERVER

include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers/Game)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers/Game/Initial)
include_directories(${PROJECT_SOURCE_DIR}/Server/src/ClientEventHandlers/Game/Playing)
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
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Sdl)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Sound)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Phases)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Map)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Effects)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Containers)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/GameView/Characters)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/Initiator)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/Initiator/ui)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/Initiator/window)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Playing)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Initial)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Final)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ServerEventHandlers/Error)
include_directories(${PROJECT_SOURCE_DIR}/Client/src/ClientConfiguration)
add_subdirectory("Client/src")


add_subdirectory(Editor/map_editor)

add_executable(server "Server/main.cpp")
target_link_libraries(server server_classes common_classes yaml-cpp box2d)

add_executable(client "Client/main.cpp")
target_link_libraries(client client_classes common_classes SDL2 SDL2_image SDL2_ttf SDL2_mixer SDL2_gfx yaml-cpp)



#------------------------------------------------------------------------------

#------------------------------------------------------------------------------
# INSTALACION


file(COPY Client/Assets DESTINATION ./)
file(COPY Server/src/Configuration/Configuration.yaml DESTINATION ./)
file(COPY Client/src/ClientConfiguration/ClientConfiguration.yaml DESTINATION ./)
file(COPY Editor/configs DESTINATION ./)


message("[INFO] Adding Installation directives")
INSTALL(TARGETS server client map_editor DESTINATION /usr/bin)
INSTALL(DIRECTORY Client/Assets DESTINATION /var/Counter)
INSTALL(DIRECTORY Editor/configs DESTINATION /var/Counter)
INSTALL(FILES Server/src/Configuration/Configuration.yaml Client/src/ClientConfiguration/ClientConfiguration.yaml DESTINATION /etc/Counter)
