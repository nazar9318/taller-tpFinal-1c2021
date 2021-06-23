project(counter-strike) 

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


FILE(GLOB_RECURSE myFiles *.cpp *.h)

message (STATUS "Cargué ${myFiles}")

add_library(client_classes
  ${myFiles}
)


target_link_libraries(client_classes PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
