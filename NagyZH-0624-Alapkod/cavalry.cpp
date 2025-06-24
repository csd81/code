#include "cavalry.h"


Cavalry::Cavalry(const string &name, int equipmentCost, int speed) : MilitaryUnit(name, equipmentCost),
    speed(speed)
{}

void Cavalry::print(ostream& o) const
{
    MilitaryUnit::print(o);
    o << "speed: " << speed << endl;
}

int Cavalry::getspeed() const
{
    return speed;
}

int Cavalry::getsoldiers() const
{
    return 1;
}

int Cavalry::gethorses() const
{
    return 1;
}

int Cavalry::getdaily() const
{
    return 10;
}
