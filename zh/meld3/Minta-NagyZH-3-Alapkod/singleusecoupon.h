#ifndef SINGLEUSECOUPON_H
#define SINGLEUSECOUPON_H

#include "coupon.h"

class SingleUseCoupon : public Coupon
{
    bool used;
public:
    SingleUseCoupon(int value);

    bool isValid(const Date& date) const override;
    int apply(int amount, const Date& date) override;
    void use() override;
    void print() const override;
};

#endif // SINGLEUSECOUPON_H
