#include "machinery.h"


Machinery::Machinery(const string &name, int equipmentCost, int crew) : MilitaryUnit(name, equipmentCost),
    crew(crew)
{}

void Machinery::print(ostream& o) const
{
    MilitaryUnit::print(o);
    o << "crew: " << crew << endl;
}

int Machinery::getspeed() const
{
    return 35;
}

int Machinery::getsoldiers() const
{
    return crew;
}

int Machinery::gethorses() const
{
    return 2;
}

int Machinery::getdaily() const
{
    return 0;
}
