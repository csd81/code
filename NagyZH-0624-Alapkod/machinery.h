#ifndef MACHINERY_H
#define MACHINERY_H

#include "militaryunit.h"

class Machinery : public MilitaryUnit
{
    int crew;
public:
    Machinery(const string &name, int equipmentCost, int crew);
    void print(ostream& o=cout) const override;
    int getspeed() const override;
    int getsoldiers() const override;
    int gethorses() const override;
    int getdaily() const override;
    MilitaryUnit* clone() const override {
    return new Machinery(*this);
}
};

#endif // MACHINERY_H
