TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    alkatresz.cpp \
    csomag.cpp \
    egyebalkatresz.cpp \
    kupon.cpp \
    memoria.cpp \
    processzor.cpp

HEADERS += megoldott_feladatok.h \
    alkatresz.h \
    csomag.h \
    egyebalkatresz.h \
    kupon.h \
    memoria.h \
    processzor.h

DISTFILES += minta-stdout.txt \
    README.md
