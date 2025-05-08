TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        coupon.cpp \
        date.cpp \
        main.cpp \
        monthlycoupon.cpp \
        multiusecoupon.cpp \
        purchase.cpp \
        singleusecoupon.cpp \
        wallet.cpp

DISTFILES += \
    coupons-1.json \
    coupons-2.json \
    export-example-A.json \
    export-example-B.json \
    minta-stdout.txt \
    purchases.json

HEADERS += \
    coupon.h \
    date.h \
    monthlycoupon.h \
    multiusecoupon.h \
    purchase.h \
    singleusecoupon.h \
    wallet.h
