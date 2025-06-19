TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
		adathalmaz.cpp \
		adatmegjelenito.cpp \
		main.cpp \
		szamlista.cpp \
		szoveg.cpp

HEADERS += \
    adathalmaz.h \
    adatmegjelenito.h \
    szamlista.h \
    szoveg.h

DISTFILES += \
    md.md
