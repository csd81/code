#include "chair.h"



bool Chair::getAdjustable() const
{
    return adjustable;
}

Chair::Chair(const string &id, const string &name, int price, int quantity, bool adjustable) : BabyProduct(id, name, price, quantity),
    adjustable(adjustable)
{}
