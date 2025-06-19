#include "pap.h"



Pap::Pap(const string &id, string &type, int maxHP, int magic) : Karakter(id, type, maxHP),
    magic(magic)
{}

void Pap::print() const
{
    Karakter::print();
    cout  << "magic: "  << magic << endl;
}

void Pap::action(Karakter &dest) const
{
    if(dest.getHP()>0){
    int set = (dest.getHP()+magic>dest.getMaxHP() ? getMaxHP() : dest.getHP()+magic);
    dest.setHP(set);
    }
}

int Pap::getarmor() const
{
return 0;
}
