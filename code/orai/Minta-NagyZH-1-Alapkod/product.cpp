#include "product.h"
#include <iostream>

string Product::getId() const
{
    return id;
}

string Product::getWoodType() const
{
    return woodType;
}

double Product::getWeight() const
{
    return weight;
}

Dimensions Product::getDimensions() const
{
    return dimensions;
}

int Product::getPrice() const
{
    return price;
}

int Product::getStockAmount() const
{
    return stockAmount;
}

void Product::setStockAmount(int newStockAmount)
{
    stockAmount = newStockAmount;
}

Product::Product(const string &id, const string &woodType,
                 double weight, const Dimensions &dimensions, int price) :
    id(id),
    woodType(woodType),
    weight(weight),
    dimensions(dimensions),
    price(price)
{
}

void Product::printData() const
{
    //"CH-oak-x321": Oak, 0.86kg, 50x120x40, 25000Ft
    cout << "\"" << id << "\": " << woodType << ", " << weight << "kg, "
         << dimensions.width << "x" << dimensions.height << "x" << dimensions.length
         << ", " << price << "Ft";
}
