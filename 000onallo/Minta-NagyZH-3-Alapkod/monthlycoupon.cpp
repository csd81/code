#include "monthlycoupon.h"

string MonthlyCoupon::aktualisdatum = "2025-06";

string MonthlyCoupon::getAktualisdatum()
{
    return aktualisdatum;
}

void MonthlyCoupon::setAktualisdatum(const string &newAktualisdatum)
{
    aktualisdatum = newAktualisdatum;
}

void MonthlyCoupon::setCurrentDate(int y, int m, int d)
{
    int day = d; // nem kell;
    char buffer[8];
    sprintf(buffer, "%04d-%02d", y, m);
    aktualisdatum = string(buffer);
}

int MonthlyCoupon::usethis()
{
    if (honap>getAktualisdatum() && valid){
        valid = false;
        return this->getDiscount();
        }

    else
        return 0;
}

bool MonthlyCoupon::isValid() const
{
    if (honap>getAktualisdatum() && valid)
        return true;
    else
        return false;
}




MonthlyCoupon::MonthlyCoupon(int discount, const string &honap) : Coupon(discount),
    honap(honap), valid(true)
{}
