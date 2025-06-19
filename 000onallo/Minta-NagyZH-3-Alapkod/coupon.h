#ifndef COUPON_H
#define COUPON_H

class Coupon
{
    int discount;

public:

    Coupon(int discount);
    virtual ~Coupon();
    virtual int usethis() =0;
    int getDiscount() const;
    virtual bool isValid() const = 0;
};

#endif // COUPON_H
