TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        chair.cpp \
        main.cpp \
        product.cpp \
        store.cpp \
        table.cpp \
        wardrobe.cpp

DISTFILES += \
    minta-stdout.txt \
    order1.json \
    order2.json \
    order3.json \
    stock-exported.json \
    stock.json

HEADERS += \
    chair.h \
    json.hpp \
    product.h \
    store.h \
    table.h \
    wardrobe.h
