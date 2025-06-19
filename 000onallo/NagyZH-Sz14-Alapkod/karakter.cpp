#include "karakter.h"


string Karakter::getId() const
{
    return id;
}

int Karakter::getHP() const
{
    return HP;
}

int Karakter::getMaxHP() const
{
    return maxHP;
}

void Karakter::setHP(int newHP)
{
    HP = newHP;
}

string Karakter::getType() const
{
    return type;
}

int Karakter::getarmor() const { return 0; }

Karakter::Karakter(const string &id, const string& type, int maxHP) : id(id), type(type),
    HP(maxHP),
    maxHP(maxHP)
{}

Karakter::~Karakter()
{

}

void Karakter::print() const
{
cout << "id: " <<  id << " HP: " << HP << " maxHP: " << maxHP << endl;
}
