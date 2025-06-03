#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
using namespace std;

class Character
{
    string id;
    int maxhp;
    int actualhp;
public:
    Character(const string &id, int maxhp);
    virtual void print() const = 0;
    virtual int getarmor() const = 0;
    virtual int action(Character& target) const = 0;
    string getId() const;
    int getMaxhp() const;
    int getActualhp() const;
    void setActualhp(int newActualhp);
};

#endif // CHARACTER_H
