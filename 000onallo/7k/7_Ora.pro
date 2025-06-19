TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    feketefeher.cpp \
    rgbszin.cpp \
    szin.cpp \
    szovegesszin.cpp \
    szurke.cpp

HEADERS += \
    feketefeher.h \
    rgbszin.h \
    szin.h \
    szovegesszin.h \
    szurke.h

DISTFILES += \
    README.md
