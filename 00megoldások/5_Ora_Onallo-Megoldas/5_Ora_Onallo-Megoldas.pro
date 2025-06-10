TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        halmaz.cpp \
        haromszog.cpp \
        main.cpp \
        pont.cpp \
        sokszog.cpp \
        teglalap.cpp \
        utvonal.cpp

HEADERS += \
    halmaz.h \
    haromszog.h \
    pont.h \
    sokszog.h \
    teglalap.h \
    utvonal.h

DISTFILES += \
    halmaz3.txt \
    minta-stdout.txt
