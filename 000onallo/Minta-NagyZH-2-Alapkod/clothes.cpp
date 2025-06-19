#include "clothes.h"



string Clothes::getSize() const
{
    return size;
}

Clothes::Clothes(const string &id, const string &name, int price, int quantity, const string &size) : BabyProduct(id, name, price, quantity),
    size(size)
{}
