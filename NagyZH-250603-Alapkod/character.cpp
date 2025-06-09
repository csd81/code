#include "character.h"



string Character::getId() const
{
    return id;
}

int Character::getPrice() const
{
    return price;
}

Character::Character(const string &id, int price) : id(id),
    price(price)
{}

void Character::print() const
{
    cout << "id: " << id << " price: " << price << " ";
}
