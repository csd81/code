#include "chair.h"
#include <iostream>

string Chair::getStyle() const
{
    return style;
}

void Chair::printData() const
{
    cout << "Chair ";
    Product::printData();
    cout << ", style: " << style;
}

Chair::Chair(const string &id, const string &woodType,
             double weight, const Dimensions &dimensions, int price,
             const string &style) :
    Product(id, woodType, weight, dimensions, price),
    style(style)
{}
