#include "character.h"


string Character::getId() const
{
    return id;
}

int Character::getMaxhp() const
{
    return maxhp;
}

int Character::getActualhp() const
{
    return actualhp;
}

void Character::setActualhp(int newActualhp)
{
    actualhp = newActualhp;
}

Character::Character(const string &id, int maxhp) : id(id),
    maxhp(maxhp),
    actualhp(maxhp)
{}

void Character::print() const
{
    cout << "id: " << id << " maxhp: " << maxhp << " actualhp: " << actualhp << endl;
}
