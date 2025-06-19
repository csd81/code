TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        adatbekero.cpp \
        bevitelimezo.cpp \
        main.cpp \
        szammezo.cpp \
        szovegmezo.cpp

HEADERS += \
    adatbekero.h \
    bevitelimezo.h \
    szammezo.h \
    szovegmezo.h

DISTFILES += readme.md