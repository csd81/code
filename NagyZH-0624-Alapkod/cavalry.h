#ifndef CAVALRY_H
#define CAVALRY_H

#include "militaryunit.h"

class Cavalry : public MilitaryUnit
{
    int speed;
public:
    Cavalry(const string &name, int equipmentCost, int speed);
    void print(ostream& o=cout) const override;
    int getspeed() const override;
    int getsoldiers() const override;
    int gethorses() const override;
    int getdaily() const override;
    MilitaryUnit* clone() const override {
    return new Cavalry(*this);
}
};

#endif // CAVALRY_H
