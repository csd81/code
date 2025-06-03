TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        actionlist.cpp \
        arena.cpp \
        character.cpp \
        mage.cpp \
        main.cpp \
        priest.cpp \
        soldier.cpp

HEADERS += \
    actionlist.h \
    arena.h \
    character.h \
    json.hpp \
    mage.h \
    priest.h \
    soldier.h

DISTFILES += \
    in-actions.txt \
    in-arena.json \
    minta-stdout.txt
