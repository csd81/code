#include "mage.h"



Mage::Mage(const string &id, int price, int magic) : Character(id, price),
    magic(magic)
{}

void Mage::print() const
{
    Character::print();
    cout <<  " magic: " << magic << "\n";
}



int Mage::attackPower() const
{
    int attack = 0;


    while (Dice::roll() != 1) {
        attack += magic;
    }

        return attack;
}
