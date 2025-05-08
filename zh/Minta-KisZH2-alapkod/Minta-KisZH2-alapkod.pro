TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    chessboard.cpp \
    image.cpp \
    example.cpp \
    inverse.cpp \
    rectangle.cpp \
    stars.cpp

HEADERS += megoldott_feladatok.h \
    chessboard.h \
    image.h \
    example.h \
    inverse.h \
    rectangle.h \
    stars.h

DISTFILES += minta-stdout.txt
