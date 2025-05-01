cmake_minimum_required(VERSION 3.16)

project(Vector_Fajl LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Vector_Fajl main.cpp)

include(GNUInstallDirs)
install(TARGETS Vector_Fajl
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
