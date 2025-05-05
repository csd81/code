cmake_minimum_required(VERSION 3.5)

project(libraryCLI LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(libraryCLI main.cpp
    library.h library.cpp
    date.h date.cpp
    book.h book.cpp
    patron.h patron.cpp
    student.h student.cpp
    loan.h loan.cpp
    notifier.h notifier.cpp
    smsnotifier.h smsnotifier.cpp
    logger.h logger.cpp
    cli.h cli.cpp
    emailnotifier.h emailnotifier.cpp)

include(GNUInstallDirs)
install(TARGETS libraryCLI
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
