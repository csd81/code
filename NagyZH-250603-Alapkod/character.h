#ifndef CHARACTER_H
#define CHARACTER_H
#include <fstream>
#include <iostream>
#include "dice.h"
using namespace std;

class Character
{
    string id;
    int price;
public:
    Character(const string &id, int price);
    virtual ~Character() = default;

    virtual void print() const;
    virtual int attackPower() const = 0;
    string getId() const;
    int getPrice() const;
};

#endif // CHARACTER_H
