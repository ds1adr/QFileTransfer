cmake_minimum_required(VERSION 4.1)
project(QFileTransfer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH  "~/Qt/6.10.2/macos/lib/cmake")


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QFileTransfer main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwidget.cpp
        mainwidget.h
)
target_link_libraries(QFileTransfer
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

