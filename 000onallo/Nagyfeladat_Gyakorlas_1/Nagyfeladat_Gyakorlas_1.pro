TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    barlangfeltaro.cpp \
    csoport.cpp \
    szemely.cpp \
    turavezeto.cpp \
    turazo.cpp \
    utvonal.cpp

HEADERS += \
    barlangfeltaro.h \
    csoport.h \
    szemely.h \
    turavezeto.h \
    turazo.h \
    utvonal.h

DISTFILES += \
    README.md
