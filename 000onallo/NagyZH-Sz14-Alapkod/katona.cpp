#include "katona.h"



int Katona::getPower() const
{
    return power;
}



int Katona::getarmor() const
{
    return armor;
}

Katona::Katona(const string &id, string &type, int maxHP, int power, int armor) : Karakter(id, type, maxHP),
    power(power),
    armor(armor)
{}

void Katona::print() const
{
    Karakter::print();
    cout  << "power: "  << power << endl;
    cout  << "armor: "  << armor << endl;
}



void Katona::action(Karakter &dest) const
{
    int minus=0;
    if(dest.getType()=="Soldier"){
        minus=power-dest.getarmor();
    }
    minus =(minus<1? 1: minus);
    int set = (dest.getHP()-minus<0? 0 :dest.getHP()-minus);
    dest.setHP(set);
}
