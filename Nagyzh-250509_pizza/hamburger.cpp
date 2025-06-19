#include "hamburger.h"

Hamburger::Hamburger(const string &name, const string &meat, int size, bool hasBacon, bool hasCheese) : Food(name, "burger"),
    meat(meat),
    size(size),
    hasBacon(hasBacon),
    hasCheese(hasCheese)
{

}

void Hamburger::print() const
{
    cout << this->getName() << " ";
    cout << meat << " ";
    cout << size << " ";
    cout << (hasBacon ? "baconnel " : " ");
    cout << (hasCheese ? "sajttal " : " ");
    cout << " ; ";
    cout << price() << " Ft" << endl;
}

int Hamburger::price() const
{
int ar=500;
    if (meat=="marhahús") ar+=10*size;
    if (meat=="csirkehús") ar+=6*size;
    if (meat=="vegetáriánus") ar+=7*size;

    if (hasBacon) ar+=100;
    if (hasCheese) ar+=100;
    return ar;
}


