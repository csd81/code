#include "toy.h"



int Toy::getYear() const
{
    return year;
}

Toy::Toy(const string &id, const string &name, int price, int quantity, int year) : BabyProduct(id, name, price, quantity),
    year(year)
{}
