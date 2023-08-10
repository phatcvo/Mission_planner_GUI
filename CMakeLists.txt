cmake_minimum_required(VERSION 3.21)
project(rrtstar_cfs_dubins)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(rrt-app main.cpp mainwindow.cpp renderarea.cpp obstacles.cpp rrtstar.cpp rrtstar.h dubins.cpp dubins.h)
target_link_libraries(rrt-app
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        )

