TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
		fajl.cpp \
		kepfajl.cpp \
		main.cpp \
		mappa.cpp \
		szovegesfajl.cpp

HEADERS += \
    fajl.h \
    kepfajl.h \
    mappa.h \
    szovegesfajl.h

DISTFILES += \
    README.md
