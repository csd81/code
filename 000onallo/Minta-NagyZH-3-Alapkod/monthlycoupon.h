#ifndef MONTHLYCOUPON_H
#define MONTHLYCOUPON_H
#include <iostream>
using namespace std;

#include "coupon.h"

class MonthlyCoupon : public Coupon
{
    string honap;
    bool valid;
public:
    MonthlyCoupon(int discount, const string &honap);


    static string aktualisdatum;
    static string getAktualisdatum();
    static void setAktualisdatum(const string &newAktualisdatum);
    static void setCurrentDate(int y, int m, int d);
    int usethis() override;
    bool isValid() const override;
};

#endif // MONTHLYCOUPON_H
