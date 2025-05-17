#include "knight.h"
#include <iostream>



Knight::Knight(const string &id, int price, int strength)
    :    Warrior(id, price),    strength(strength)
{}

void Knight::print() const
{
    std::cout << "Knight " << id
        << "Price: " << price
    << "strength: " << strength
    << "\n" ;


}

void Knight::attack(Dragon &dragon) const
{
    int damage = strength - dragon.getArmor();
    if (damage < 1) damage  = 1;
    std::cout << id << " attacks dragon with damage: " << damage << "\n";
    dragon.reduceHealth(damage);
}
