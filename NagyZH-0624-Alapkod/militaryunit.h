#ifndef MILITARYUNIT_H
#define MILITARYUNIT_H
#include <iostream>
using namespace std;

class MilitaryUnit
{
    string name;
    int equipmentCost;
public:    
    MilitaryUnit(const string &name, int equipmentCost);
    virtual ~MilitaryUnit();
    virtual void print(ostream& o = cout) const;
    virtual int getspeed() const =0;
    virtual int getsoldiers() const =0;
    virtual int gethorses() const =0;
    virtual int getdaily() const =0;
    string getName() const;
    int getEquipmentCost() const;
    virtual MilitaryUnit* clone() const = 0;
};

#endif // MILITARYUNIT_H
