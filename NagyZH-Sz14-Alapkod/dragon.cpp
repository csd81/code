#include "dragon.h"

//
// A "sarkany" osztaly forraskodja nem modosithato.
//

Dragon::Dragon(const string &name,
               int maxHealth,
               int armor):
    name(name),
    maxHealth(maxHealth),
    health(maxHealth),
    armor(armor)
{
}

const string &Dragon::getName() const
{
    return name;
}

int Dragon::getHealth() const
{
    return health;
}

void Dragon::setHealth(int newHealth)
{
    health = newHealth;
}

int Dragon::getArmor() const
{
    return armor;
}

void Dragon::reduceHealth(int amount)
{
    health -= amount;
    if (health < 0) health = 0;
}

void Dragon::reduceHealthByMagic(double magic)
{
    health = static_cast<int>(health * (1.0 - magic));
}
