#ifndef WARRIOR_H
#define WARRIOR_H

#include "dragon.h"

#include <string>


class Warrior
{
protected:
    std::string id;
    int price;


public:
    Warrior(const std::string& id, int price);
    virtual ~Warrior() = default;


    std::string getId() const;
    int getPrice() const;

    virtual void print() const = 0;
    virtual void attack(Dragon& dragon) const = 0;
};

#endif // WARRIOR_H
