TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    akcio.cpp \
    jatekosok.cpp \
    karakter.cpp \
    mohokarakter.cpp \
    valogatos.cpp

HEADERS += \
    akcio.h \
    jatekosok.h \
    karakter.h \
    mohokarakter.h \
    valogatos.h

DISTFILES += \
    READ.me.md
