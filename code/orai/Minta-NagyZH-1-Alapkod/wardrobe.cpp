#include "wardrobe.h"
#include <iostream>

int Wardrobe::getDoorCount() const
{
    return doorCount;
}

bool Wardrobe::getHasMirror() const
{
    return hasMirror;
}

void Wardrobe::printData() const
{
    cout << "Wardrobe ";
    Product::printData();
    cout << ", doors: " << doorCount << ", mirror: " << (hasMirror?"Yes":"No");
}

Wardrobe::Wardrobe(const string &id, const string &woodType,
                   double weight, const Dimensions &dimensions, int price,
                   int doorCount, bool hasMirror) :
    Product(id, woodType, weight, dimensions, price),
    doorCount(doorCount),
    hasMirror(hasMirror)
{}
