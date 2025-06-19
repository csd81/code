#ifndef CHARACTER_H
#define CHARACTER_H

#include "dragon.h"
#include <iostream>
using namespace std;

class Character
{
    string id;
    int price;
public:
    Character(const string &id, int price);
    virtual ~Character();
    virtual void print() const;
    string getId() const;
    int getPrice() const;
    virtual int attack(Dragon& d) const = 0;
};

#endif // CHARACTER_H
