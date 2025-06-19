#include "singlecoupon.h"



SingleCoupon::SingleCoupon(int discount, bool ervenyes) : Coupon(discount),
    ervenyes(ervenyes)
{}

int SingleCoupon::usethis()
{
    if (ervenyes){
        ervenyes=false;
        return this->getDiscount();
        } else return 0;

}

bool SingleCoupon::isValid() const
{
    return ervenyes;
}
