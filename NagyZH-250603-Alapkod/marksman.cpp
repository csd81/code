#include "marksman.h"



Marksman::Marksman(const string &id, int price, int agility, bool elite) : Character(id, price),
    agility(agility),
    elite(elite)
{}

void Marksman::print() const
{
    Character::print();
    cout <<  " agility: " << agility
     <<  " elite: " << elite << "\n";
}

int Marksman::attackPower() const
{
    bool hit=false;
    if (elite){
        int roll1 = Dice::roll();
        int roll2 = Dice::roll();
    if (roll1>=5 || roll2>=5)
            hit=true;
    } else {
        int roll = Dice::roll();
        if (roll>=5)
            hit=true;
    }
    if (hit){
        return agility;
    }
    return 0;
}
