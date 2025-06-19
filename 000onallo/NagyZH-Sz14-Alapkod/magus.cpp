#include "magus.h"

Magus::Magus(const string &id, string &type, int maxHP, int magic) : Karakter(id, type, maxHP),
    magic(magic)
{}

void Magus::print() const
{
Karakter::print();
cout  << "magic: "  << magic << endl;
}

void Magus::action(Karakter & dest) const{
int set = (dest.getHP()-magic<0 ? 0 : dest.getHP()-magic);
dest.setHP(set);
}

int Magus::getarmor() const
{
    return 0;
}
