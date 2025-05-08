cmake_minimum_required(VERSION 3.5)

project(Purchase LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Purchase main.cpp
    product.h product.cpp
    singleproduct.h singleproduct.cpp
    multiproduct.h multiproduct.cpp
    packagedproduct.h packagedproduct.cpp)

include(GNUInstallDirs)
install(TARGETS Purchase
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
