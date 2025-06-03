#include "soldier.h"

Soldier::Soldier(const string &id, int maxhp, int power, int armor) : Character(id, maxhp),
    power(power),
    armor(armor)
{}

void Soldier::print() const
{
    Character::print();
    cout << "power: " << power;
    cout << "armor: " << armor;
    cout << endl;
}

int Soldier::getarmor() const
{
    return armor;
}

int Soldier::action(Character& target) const
{

    if (this->getActualhp() == 0 || target.getActualhp() == 0)
        return 0;

    int damage = power - target.getarmor();
    if (damage<1) damage = 1;

    int newHP = target.getActualhp() - damage;
    if (newHP < 0) newHP = 0;

    target.setActualhp(newHP);

    return damage;
}





