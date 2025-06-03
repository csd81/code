#include "mage.h"



Mage::Mage(const string &id, int maxhp, int magic) : Character(id, maxhp),
    magic(magic)
{}

void Mage::print() const
{
    Character::print();
    cout << "magic: " << magic;
    cout << endl;
}

int Mage::getarmor() const
{
    return 0;
}

int Mage::action(Character& target) const
{
  //  A mágus is megtámadja a célpontját, akinek az életereje annyival csökken, amennyi a mágus varázsereje. A védekező páncéljának ilyenkor nincs hatása.

    if (this->getActualhp() == 0 || target.getActualhp() == 0)
        return 0;
    int newHP = target.getActualhp() - magic;
    if (newHP < 0) newHP = 0;
    target.setActualhp(newHP);
    return magic;

}

