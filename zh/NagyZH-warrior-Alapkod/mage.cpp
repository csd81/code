#include "mage.h"
#include <iostream>


Mage::Mage(const string &id, int price, double magic) : Warrior(id, price),
    magic(magic)
{}

void Mage::print() const
{
    std::cout << "Mage " << id
              << "Price: " << price
              << "magic: " << magic
              << "\n" ;


}

void Mage::attack(Dragon &dragon) const
{
    std::cout << id << " casts magic: " << magic << "\n";
    dragon.reduceHealthByMagic(magic);
}
