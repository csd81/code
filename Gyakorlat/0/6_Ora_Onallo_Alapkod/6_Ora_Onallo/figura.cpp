#include "figura.h"

Figura::Figura(const string &pos):
	pozicio(pos)
{
}

Figura::~Figura()
{

}

const string &Figura::getPozicio() const
{
	return pozicio;
}

bool Figura::ervenyes(string pozicio)
{
    bool p1 = false;
    bool p2 = false;
    for (char c ='A'; c <='H'; c++){
        if (pozicio[0]==c)
            p1 = true;
    }
    for (char c ='1'; c <='8'; c++){
        if (pozicio[1]==c)
            p2 = true;
    }
    return (p1 && p2);
}

bool Figura::odalep(string pozicio)
{
    if ((this->ervenyes(pozicio)) &&  (this->lephet(pozicio))){
        this->pozicio = pozicio;
        return true;
        }
    return false;
}
