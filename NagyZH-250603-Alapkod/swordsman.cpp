#include "swordsman.h"




Swordsman::Swordsman(const string &id, int price, int strength) : Character(id, price),
    strength(strength)
{}

void Swordsman::print() const
{
    Character::print();
    cout <<  " strength: " << strength << "\n";
}

int Swordsman::attackPower() const
{
    int attack=0;

    for (int i =0; i<strength; i++){
        int roll = Dice::roll();
        attack +=roll;
    }

    return attack;
}
