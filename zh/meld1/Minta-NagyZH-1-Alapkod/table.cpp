#include "table.h"
#include <iostream>
using namespace std;


Table::Table(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price, int legCount, bool legsAdjustable) : Product(id, woodType, weight, width, height, length, price),
    legCount(legCount),
    legsAdjustable(legsAdjustable)
{}

void Table::print() const
{
    cout << "Table \"" << id << "\": " << woodType << ", " << weight << "kg, "
         << width << "x" << height << "x" << length << ", " << price << "Ft, "
         << "legs: " << legCount << " " << (legsAdjustable ? "adjustable" : "non-adjustable") << endl;
}
