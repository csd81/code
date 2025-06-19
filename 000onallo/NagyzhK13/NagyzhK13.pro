TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
		elem.cpp \
		felulet.cpp \
		gomb.cpp \
		main.cpp \
		szambevitel.cpp

HEADERS += \
    elem.h \
    felulet.h \
    gomb.h \
    szambevitel.h

DISTFILES += \
    md.md
