cmake_minimum_required(VERSION 3.5)

project(EEE482 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(EEE482 main.cpp
    node.h
queue.h
gridgenerator.h gridgenerator.cpp
pathfinder.h pathfinder.cpp )

include(GNUInstallDirs)
install(TARGETS EEE482
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
