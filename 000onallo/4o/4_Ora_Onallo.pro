TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    datum.cpp \
    datumlista.cpp

HEADERS += \
    datum.h \
    datumlista.h

DISTFILES += \
    README.md
