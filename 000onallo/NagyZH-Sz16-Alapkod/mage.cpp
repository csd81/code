#include "mage.h"



Mage::Mage(const string &id, int price, double magic) : Character(id, price),
    magic(magic)
{}

void Mage::print() const
{
    Character::print();
    cout << magic;
    cout << endl;
}

int Mage::attack(Dragon &d) const
{
    return d.getHP() * (1-magic);
}
