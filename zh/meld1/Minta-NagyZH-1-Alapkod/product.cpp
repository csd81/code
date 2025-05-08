#include "product.h"

std::string Product::getId() const
{
    return id;
}

int Product::getPrice() const
{
    return price;
}


std::string Product::getWoodType() const
{
    return woodType;
}

double Product::getWeight() const
{
    return weight;
}

int Product::getWidth() const
{
    return width;
}

int Product::getHeight() const
{
    return height;
}

int Product::getLength() const
{
    return length;
}

Product::Product(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price) : id(id),
    woodType(woodType),
    weight(weight),
    width(width),
    height(height),
    length(length),
    price(price)
{}
