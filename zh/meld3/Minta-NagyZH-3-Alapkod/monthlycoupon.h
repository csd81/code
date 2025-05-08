#ifndef MONTHLYCOUPON_H
#define MONTHLYCOUPON_H

#include "coupon.h"
#include "date.h"

class MonthlyCoupon : public Coupon
{

    int validYear;
    int validMonth;
    bool used;
public:
    MonthlyCoupon(int validYear, int validMonth, int value);

    bool isValid(const Date& date) const override;
    int apply(int amount, const Date& date) override;
    void use() override;
    void print() const override;
static void setCurrentDate(int y, int m, int d);

};

#endif // MONTHLYCOUPON_H
