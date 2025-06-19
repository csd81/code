#ifndef KARAKTER_H
#define KARAKTER_H
#include <iostream>
using namespace std;

class Karakter
{
    string id;
    string type;
    int HP;
    int maxHP;
public:
    Karakter(const string &id, const string& type,  int maxHP);
    virtual ~Karakter();
    virtual void print() const;
    string getId() const;
    int getHP() const;
    int getMaxHP() const;
    virtual void action(Karakter & dest) const =0;
    void setHP(int newHP);
    string getType() const;
    virtual int getarmor() const;
};

#endif // KARAKTER_H
