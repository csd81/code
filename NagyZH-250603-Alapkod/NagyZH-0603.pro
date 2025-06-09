TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    camp.cpp \
    character.cpp \
    dice.cpp \
    mage.cpp \
    main.cpp \
    marksman.cpp \
    swordsman.cpp \
    team.cpp

HEADERS += \
    camp.h \
    character.h \
    dice.h \
    json.hpp \
    mage.h \
    marksman.h \
    swordsman.h \
    team.h

DISTFILES += \
    in-camp.json \
    in-team-1.txt \
    in-team-2.txt \
    minta-stdout.txt \
    out-team-1-stats.json \
    out-team-2-stats.json
