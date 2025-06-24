#include "militaryunit.h"


string MilitaryUnit::getName() const
{
    return name;
}

int MilitaryUnit::getEquipmentCost() const
{
    return equipmentCost;
}

MilitaryUnit::MilitaryUnit(const string &name, int equipmentCost) : name(name),
    equipmentCost(equipmentCost)
{}

MilitaryUnit::~MilitaryUnit()
{

}


void MilitaryUnit::print(ostream& o) const {
    o << "name: " << name << " equipmentCost: " << equipmentCost << " ";
}

