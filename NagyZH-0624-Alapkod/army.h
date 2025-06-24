#ifndef ARMY_H
#define ARMY_H
#include <vector>
#include <fstream>
#include "militaryunit.h"
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Army
{
public:
    struct ArmyUnit{
        MilitaryUnit* unit;
        int unitcount;
    };
    ~Army();
    std::vector<Army::ArmyUnit> armyunits;
    void display();
    int getSpeed();
    int soldierCount();
    int horseCount();
    int dailyCost();
    int totalMissionCost(int dist, int day);
    static int salary;

    static void setSalary(int newSalary);
};

#endif // ARMY_H
