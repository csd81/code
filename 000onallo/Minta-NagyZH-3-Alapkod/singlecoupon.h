#ifndef SINGLECOUPON_H
#define SINGLECOUPON_H

#include "coupon.h"

class SingleCoupon : public Coupon
{
    bool ervenyes;

public:
    SingleCoupon(int discount, bool ervenyes);
    int usethis() override;
    bool isValid() const override;
};

#endif // SINGLECOUPON_H
