#ifndef DRAGON_H
#define DRAGON_H

//
// A "sarkany" osztaly forraskodja nem modosithato.
//

#include <string>
using namespace std;

class Dragon
{
    const string name;
    const int maxHealth;
    int health;
    int armor;
public:
    Dragon(const string& name,
           int maxHealth,
           int armor);

    const string& getName() const;
    int getHealth() const;
    void setHealth(int newHealth); // itt lehet modositani a sarkany eleterejet
    int getArmor() const;
    void reduceHealth(int amount);
    void reduceHealthByMagic(double magic);
};

#endif // DRAGON_H
