#ifndef HAMBURGER_H
#define HAMBURGER_H

#include "food.h"

class Hamburger : public Food
{

    string meat; // marha, csirke, vegetáriánus
    int size; //g
    bool hasBacon;
    bool hasCheese;
public:    
    Hamburger(const string &name, const string &meat, int size, bool hasBacon, bool hasCheese);
    void print() const;
    int price() const;
};

#endif // HAMBURGER_H
