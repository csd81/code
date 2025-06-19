#include "multicoupon.h"



MultiCoupon::MultiCoupon(int discount, int uses) : Coupon(discount),
    uses(uses)
{}

int MultiCoupon::usethis()
{
    if (uses>0){
        uses--;
        return this->getDiscount();
        }
    else return 0;
}

bool MultiCoupon::isValid() const
{
    if (uses>0)
        return true;
    else return false;

}
