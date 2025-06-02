#include "bastya.h"



bool Bastya::lephet(string poz) const
{
    bool legal = false;
    if (poz[0]==this->getPozicio()[0]){
        for (int i=1; i<8; i++){
            if ((poz[1]==this->getPozicio()[1]-i)||(poz[1]==this->getPozicio()[1]+i))
            legal = true;
        }
    } else if (poz[1]==this->getPozicio()[1]){
        for (int i=1; i<8; i++){
            if ((poz[0]==this->getPozicio()[0]-i)||(poz[0]==this->getPozicio()[0]+i))
                legal = true;
        }
    }
    return legal;
}

char Bastya::jeloles() const
{
    return 'B';
}

Bastya::Bastya(const string &pos) : Figura(pos)
{}
