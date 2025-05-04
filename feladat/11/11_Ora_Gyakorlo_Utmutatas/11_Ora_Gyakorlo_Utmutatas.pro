TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        engine.cpp \
        freightcar.cpp \
        main.cpp \
        passengercar.cpp \
        trainmanager.cpp \
        trainset.cpp \
        vehicle.cpp

HEADERS += \
    engine.h \
    freightcar.h \
    passengercar.h \
    trainmanager.h \
    trainset.h \
    vehicle.h
