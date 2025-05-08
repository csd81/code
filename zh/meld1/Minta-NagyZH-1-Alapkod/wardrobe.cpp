#include "wardrobe.h"
#include <iostream>
using namespace std;

Wardrobe::Wardrobe(const std::string &id, const std::string &woodType, double weight, int width, int height, int length, int price, int doorCount, bool hasMirror) : Product(id, woodType, weight, width, height, length, price),
    doorCount(doorCount),
    hasMirror(hasMirror)
{}

void Wardrobe::print() const
{
    cout << "Wardrobe \"" << id << "\": " << woodType << ", " << weight << "kg, "
         << width << "x" << height << "x" << length << ", " << price << "Ft, "
         << "doors: " << doorCount << ", mirror: " << (hasMirror ? "Yes" : "No") << endl;

}
