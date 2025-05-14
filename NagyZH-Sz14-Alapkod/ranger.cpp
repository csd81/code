#include "ranger.h"
#include <iostream>



Ranger::Ranger(const string &id, int price, int agility)
    : Warrior(id, price),     agility(agility)
{}

void Ranger::print() const
{
    std::cout << "Ranger " << id
              << "Price: " << price
              << "agility: " << agility
              << "\n" ;


}

void Ranger::attack(Dragon &dragon) const
{
    dragon.reduceHealth(agility);
}
