#ifndef INFANTRY_H
#define INFANTRY_H

#include "militaryunit.h"

class Infantry : public MilitaryUnit
{
    string weapon;
    bool heavy;
public:
    Infantry(const string &name, int equipmentCost, const string &weapon, bool heavy);
    void print(ostream& o=cout) const override;
    int getspeed() const override;
    int getsoldiers() const override;
    int gethorses() const override;
    int getdaily() const override;
    MilitaryUnit* clone() const override {
    return new Infantry(*this);
}

};

#endif // INFANTRY_H
