TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        actionlist.cpp \
        arena.cpp \
        karakter.cpp \
        katona.cpp \
        magus.cpp \
        main.cpp \
        pap.cpp

HEADERS += \
    actionlist.h \
    arena.h \
    json.hpp \
    karakter.h \
    katona.h \
    magus.h \
    pap.h

DISTFILES += \
    README.md \
    in-actions.txt \
    in-arena.json \
    minta-stdout.txt
