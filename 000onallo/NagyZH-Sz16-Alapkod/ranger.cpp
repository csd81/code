#include "ranger.h"


Ranger::Ranger(const string &id, int price, int agility) : Character(id, price),
    agility(agility)
{}

void Ranger::print() const
{
    Character::print();
    cout << agility;
    cout << endl;
}

int Ranger::attack(Dragon &d) const
{
    return agility;
}
