#include "priest.h"

Priest::Priest(const string &id, int maxhp, int magic) : Character(id, maxhp),
    magic(magic)
{}

void Priest::print() const
{
    Character::print();
    cout << "magic: " << magic;
    cout << endl;
}

int Priest::getarmor() const
{
    return 0;
}

int Priest::action(Character& target) const
{

    if (this->getActualhp() == 0 || target.getActualhp() == 0)
        return 0;

//    A pap gyógyítja a célpontját, akinek az életereje annyival nő, amennyi a pap varázsereje.
    int newHP = target.getActualhp() + magic;
    if (newHP > target.getMaxhp()) newHP = target.getMaxhp();
    target.setActualhp(newHP);
    return magic;
}
