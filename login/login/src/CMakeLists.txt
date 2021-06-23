
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

FILE(GLOB_RECURSE myFiles *.cpp *.h)

message (STATUS "Cargué ${myFiles}")

add_library(login_files
  ${myFiles}
)
target_link_libraries(login_files PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

















#set(CMAKE_INCLUDE_CURRENT_DIR ON)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check http://doc.qt.io/qt-5/deployment-android.html for more information.
# They need to be set before the find_package(Qt5 ...) call.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

#set(CMAKE_INCLUDE_CURRENT_DIR ON)































#if(ANDROID)
#  add_library(login SHARED
#    main.cpp
#    mainwindow.cpp
#    mainwindow.h
#    mainwindow.ui
#  )
#else()
#  add_executable(login
#    main.cpp
#    mainwindow.cpp
#    mainwindow.h
#    mainwindow.ui
#  )
#endif()

