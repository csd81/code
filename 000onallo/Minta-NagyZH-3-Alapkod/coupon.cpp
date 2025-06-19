#include "coupon.h"


int Coupon::getDiscount() const
{
    return discount;
}



Coupon::Coupon(int discount) : discount(discount)
{}

Coupon::~Coupon()
{

}

