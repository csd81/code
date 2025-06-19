#ifndef MULTICOUPON_H
#define MULTICOUPON_H

#include "coupon.h"

class MultiCoupon : public Coupon
{

    int uses;
public:
    MultiCoupon(int discount, int uses);
    int usethis() override;
    bool isValid() const override;
};

#endif // MULTICOUPON_H
