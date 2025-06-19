#include "babyproduct.h"



BabyProduct::~BabyProduct()
{

}

ostream &operator<<(ostream & os, const BabyProduct & bp)
{

    bp.print(os);
    return os;
}

int BabyProduct::getPrice() const
{
    return price;
}

string BabyProduct::getId() const
{
    return id;
}

int BabyProduct::getQuantity() const
{
    return quantity;
}

void BabyProduct::setQuantity(int newQuantity)
{
    quantity = newQuantity;
}

string BabyProduct::getName() const
{
    return name;
}

BabyProduct::BabyProduct(const string &id, const string &name, int price, int quantity) : id(id),
    name(name),
    price(price),
    quantity(quantity)
{}
