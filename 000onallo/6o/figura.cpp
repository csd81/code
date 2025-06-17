#include "figura.h"

Figura::Figura(const string &pos):
	pozicio(pos)
{
}

Figura::Figura(const Figura &masik): pozicio(masik.pozicio)
{

}

Figura& Figura::operator=(const Figura &masik)
{
    if (&masik != this){
        pozicio=masik.pozicio;
    }
    return *this;
}



const string &Figura::getPozicio() const
{
	return pozicio;
}

bool Figura::ervenyes(const string &pos)
{
    return(
    pos.size()==2
    && pos[0]>='A'     && pos[0]<='H'
    && pos[1]>='0'     && pos[1]<='8'
    );
}

bool Figura::odalep(const string &pos)
{
    if (ervenyes(pos) &&     this->lephet(pos) ){
        this->pozicio =pos;
        return true;
        }
    else return false;
}

