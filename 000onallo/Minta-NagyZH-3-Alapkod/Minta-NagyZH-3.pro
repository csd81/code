TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        coupon.cpp \
        main.cpp \
        monthlycoupon.cpp \
        multicoupon.cpp \
        purchase.cpp \
        singlecoupon.cpp \
        wallet.cpp

DISTFILES += \
    MARKDOWN.md \
    coupons-1.json \
    coupons-2.json \
    export-example-A.json \
    export-example-B.json \
    minta-stdout.txt \
    purchases.json

HEADERS += \
    coupon.h \
    json.hpp \
    monthlycoupon.h \
    multicoupon.h \
    purchase.h \
    singlecoupon.h \
    wallet.h
