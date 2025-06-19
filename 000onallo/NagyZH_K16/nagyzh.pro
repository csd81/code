TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    folyoszamla.cpp \
    hitelszamla.cpp \
        main.cpp \
    szamla.cpp \
		szamlaseged.cpp \
    tranzakcio.cpp \
    ugyfel.cpp
		
HEADERS += \
    folyoszamla.h \
    hitelszamla.h \
    szamla.h \
    szamlaseged.h \
    tranzakcio.h \
    ugyfel.h

DISTFILES += \
    md.md
