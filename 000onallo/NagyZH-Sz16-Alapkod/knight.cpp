#include "knight.h"



Knight::Knight(const string &id, int price, unsigned int strength) : Character(id, price),
    strength(strength)
{}

void Knight::print() const
{
    Character::print();
    cout << strength;
    cout << endl;
}

int Knight::attack(Dragon& d) const
{
     return ((this->strength -d.getArmor()> 1) ? strength-d.getArmor() : 1);
}
