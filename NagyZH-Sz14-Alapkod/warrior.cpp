#include "warrior.h"


std::string Warrior::getId() const
{
    return id;
}

int Warrior::getPrice() const
{
    return price;
}

Warrior::Warrior(const std::string &id, int price)
    : id(id), price(price)
{}
