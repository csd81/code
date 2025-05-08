TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

HEADERS += megoldott_feladatok.h \
    itemcounter.h \
    extra.h \
    json.hpp

DISTFILES += minta-stdout.txt
