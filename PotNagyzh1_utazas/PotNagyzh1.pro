TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    bustrip.cpp \
    filterbase.cpp \
    main.cpp \
    maxtimefrom.cpp \
    planetrip.cpp \
    traintrip.cpp \
    travelagency.cpp \
    trip.cpp


HEADERS += \
    bustrip.h \
    filterbase.h \
    json.hpp \
    maxtimefrom.h \
    planetrip.h \
    traintrip.h \
    travelagency.h \
    trip.h

DISTFILES +=  \
    README.md \
    trips.json
    minta-stdout.txt   