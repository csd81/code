TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    product.cpp \
    ratedproduct.cpp \
    review.cpp

HEADERS += megoldott_feladatok.h \
    product.h \
    ratedproduct.h \
    review.h

DISTFILES += minta-stdout.txt
