TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        probalkozas.cpp \
        verseny.cpp

HEADERS += \
    probalkozas.h \
    verseny.h

DISTFILES += \
    README.md \
    minta-stdout.txt \
    verseny1.txt
