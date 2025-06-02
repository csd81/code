TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
		harcos.cpp \
		ijasz.cpp \
		karakter.cpp \
		magus.cpp \
		main.cpp \
		szerver.cpp

HEADERS += \
    harcos.h \
    ijasz.h \
    karakter.h \
    magus.h \
    szerver.h

DISTFILES += \
    karakterek.json \
    merkozesek.json
