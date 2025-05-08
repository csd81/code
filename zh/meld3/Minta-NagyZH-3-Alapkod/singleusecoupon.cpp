#include "singleusecoupon.h"

#include<iostream>
using namespace std;


SingleUseCoupon::SingleUseCoupon(int value) :
    Coupon(value), used(false)
{}

bool SingleUseCoupon::isValid(const Date& date) const
{
    return  !used;
}

int SingleUseCoupon::apply(int amount, const Date& date)
{
    if (!used)
        return std::max(0, amount - value);
    return amount;
}

void SingleUseCoupon::use()
{
    used = true;
}

void SingleUseCoupon::print() const
{
    cout << " SingleUseCoupon: " << value <<   (used? ", used" : ", notused");
}
