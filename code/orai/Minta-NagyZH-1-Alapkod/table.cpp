#include "table.h"
#include <iostream>

int Table::getLegCount() const
{
    return legCount;
}

bool Table::getLegsAdjustable() const
{
    return legsAdjustable;
}

void Table::printData() const
{
    cout << "Table ";
    Product::printData();
    cout << ", legs: " << legCount;
    if (legsAdjustable) cout << " adjustable";
    else cout << " non-adjustable";
}

Table::Table(const string &id, const string &woodType,
             double weight, const Dimensions &dimensions, int price,
             int legCount, bool legsAdjustable) :
    Product(id, woodType, weight, dimensions, price),
    legCount(legCount),
    legsAdjustable(legsAdjustable)
{}
