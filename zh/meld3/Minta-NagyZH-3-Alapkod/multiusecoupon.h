#ifndef MULTIUSECOUPON_H
#define MULTIUSECOUPON_H

#include "coupon.h"

class MultiUseCoupon : public Coupon
{
    int usesRemaining;
public:
    MultiUseCoupon(int value, int usesRemaining);

    bool isValid(const Date& date) const override;
    int apply(int amount, const Date& date) override;
    void use() override;
    void print() const override;
};

#endif // MULTIUSECOUPON_H
