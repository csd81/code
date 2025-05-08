#include "chair.h"
#include <iostream>
using namespace std;


Chair::Chair(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price, const std::string &style) : Product(id, woodType, weight, width, height, length, price),
    style(style)
{}

void Chair::print() const
{
    cout << "Chair \"" << id << "\": " << woodType << ", " << weight << "kg, "
         << width << "x" << height << "x" << length << ", " << price << "Ft, "
         << "style: " << style << endl;
}
