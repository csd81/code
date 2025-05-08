#include "multiusecoupon.h"

#include<iostream>
using namespace std;

MultiUseCoupon::MultiUseCoupon(int usesRemaining, int value) : Coupon(value),
    usesRemaining(usesRemaining)
{}

bool MultiUseCoupon::isValid(const Date& date) const
{
    if (usesRemaining>0)
        return true;
    return false;
}

int MultiUseCoupon::apply(int amount, const Date& date)
{
    if (usesRemaining>0 && amount > value)
    {
        amount -= value;
        return amount;}
    else if (usesRemaining>0)
        return 0;
    else
        return amount;
}

void MultiUseCoupon::use()
{
    if (usesRemaining>0)
        usesRemaining--;
}

void MultiUseCoupon::print() const
{
cout << "Multi Use Coupon: value = " << value
     << ", remaining uses = " << usesRemaining << endl;
}
