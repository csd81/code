#include "singleproduct.h"

SingleProduct::SingleProduct(const string &code, int unitPrice) : code(code),
    unitPrice(unitPrice)
{}

int SingleProduct::getPrice() const
{
    return unitPrice;
}
