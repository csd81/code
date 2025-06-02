TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    food.cpp \
    foodbar.cpp \
    hamburger.cpp \
    kebab.cpp \
    main.cpp \
    order.cpp \
    pizza.cpp

# Ha van header fájl (pl. order.h), akkor:
HEADERS += \
    food.h \
    foodbar.h \
    hamburger.h \
    json.hpp \
    kebab.h \
    order.h \
    pizza.h

 

DISTFILES += \
    foods.json \
    minta-stdout.txt \
    order1.json \
    order2.json \
    order3.json