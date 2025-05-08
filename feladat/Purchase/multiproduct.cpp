#include "multiproduct.h"



int MultiProduct::getPrice() const
{
    return unitPrice * quantity;
}

MultiProduct::MultiProduct(const string &code, int unitPrice, int quantity)
    : code(code),
      unitPrice(unitPrice),
      quantity(quantity)
{}
