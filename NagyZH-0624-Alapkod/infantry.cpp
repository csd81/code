#include "infantry.h"



Infantry::Infantry(const string &name, int equipmentCost, const string &weapon, bool heavy) : MilitaryUnit(name, equipmentCost),
    weapon(weapon),
    heavy(heavy)
{}

void Infantry::print(ostream& o) const
{
    MilitaryUnit::print(o);
    o << "weapon: " << weapon  << "heavy: " << (heavy ? "yes":"no") << endl;
}

int Infantry::getspeed() const
{
    if (heavy)
        return 25;
    else
        return 30;
}

int Infantry::getsoldiers() const
{
    return 1;
}

int Infantry::gethorses() const
{
    return 0;
}

int Infantry::getdaily() const
{
    return 25;
}
