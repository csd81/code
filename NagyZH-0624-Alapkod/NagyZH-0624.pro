TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    army.cpp \
    castle.cpp \
    cavalry.cpp \
    infantry.cpp \
    machinery.cpp \
    main.cpp \
    militaryunit.cpp

HEADERS += \
    army.h \
    castle.h \
    cavalry.h \
    infantry.h \
    json.hpp \
    machinery.h \
    militaryunit.h

DISTFILES += \
    README.md \
    in-army-1.txt \
    in-army-2.txt \
    in-army-3.txt \
    in-army-4.txt \
    in-castle-cavalry.json \
    in-castle-infantry.json \
    in-castle-machinery.json \
    minta-stdout.txt
