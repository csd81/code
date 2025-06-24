#include "army.h"
#include <limits>

int Army::salary=25;

Army::~Army()
{
    for (ArmyUnit& au : armyunits) {
        delete au.unit;
    }
    armyunits.clear();
}

void Army::display()
{
    for (auto au : armyunits)
    if (au.unitcount>0){
        cout << au.unit->getName() <<" "<< au.unitcount << endl;
    }
}

int Army::getSpeed()
{
    int s=numeric_limits<int>::max();
        for (Army::ArmyUnit a : armyunits){
            if(a.unit->getspeed()<s)
                s=a.unit->getspeed();
        }

    return s;
}

int Army::soldierCount()
{
    int sc=0;
        for (Army::ArmyUnit a : armyunits){
            sc+=a.unit->getsoldiers();
        }

    return sc;
}

int Army::horseCount()
{
    int hc=0;
        for (Army::ArmyUnit a : armyunits){
            hc+=a.unit->gethorses();
        }

    return hc;
}

int Army::dailyCost()
{
    int dc=0;
    dc+= soldierCount()*Army::salary;
    dc+= horseCount()*10;
    return dc;

}



#include <cmath> // a ceil-hez

int Army::totalMissionCost(int dist, int day)
{
    int speed = getSpeed(); // leglassabb egység
    int travelDays = 2 * static_cast<int>(ceil(static_cast<double>(dist) / speed));
    int totalDays = travelDays + day;
    int totalDaily = dailyCost() * totalDays;

    int equipCost = 0;
    for (ArmyUnit& au : armyunits) {
        equipCost += au.unitcount * au.unit->getEquipmentCost();
    }

    return totalDaily + equipCost;
}


void Army::setSalary(int newSalary)
{
    salary = newSalary;
}
