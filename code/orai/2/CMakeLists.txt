cmake_minimum_required(VERSION 3.16)

project(Ora2Kozos LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Ora2Kozos main.cpp
    szamok.h szamok.cpp)

include(GNUInstallDirs)
install(TARGETS Ora2Kozos
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
