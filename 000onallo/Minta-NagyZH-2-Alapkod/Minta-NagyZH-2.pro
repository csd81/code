TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        babyproduct.cpp \
        chair.cpp \
        clothes.cpp \
        main.cpp \
        shipment.cpp \
        toy.cpp \
        warehouse.cpp

DISTFILES += \
    README.md \
    minta-stdout.txt \
    output-chairs.json \
    output-clothes.json \
    output-toys.json \
    stock-toys.json \
    stock-clothes.json \
    stock-chairs.json \
    shipment-1.json \
    shipment-2.json

HEADERS += \
    babyproduct.h \
    chair.h \
    clothes.h \
    json.hpp \
    shipment.h \
    toy.h \
    warehouse.h
