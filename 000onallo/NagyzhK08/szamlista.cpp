#include "szamlista.h"


int SzamLista::lepeskoz=1;

int SzamLista::getAlso() const
{
    return also;
}

int SzamLista::getFelso() const
{
    return felso;
}

void SzamLista::megjelenit() const
{
    if (getLathato()==false)
        cout  << also<< " " << felso <<"\n";
    else
    for (int i=also; i<=felso; i += SzamLista::getLepeskoz()){
        cout << i << " ";
    }
    cout << "\n";
}

int SzamLista::operator*()
{
    return felso-also;
}



int SzamLista::getLepeskoz()
{
    return lepeskoz;
}

void SzamLista::setLepeskoz(int newLepeskoz)
{
    lepeskoz = newLepeskoz;
}

SzamLista::SzamLista(const string &szin, bool lathato, int also, int felso) : AdatMegjelenito(szin, lathato),
    also(also),
    felso(felso)
{
    int lathatocount;
if (getLathato()==false)
    lathatocount =2;
else    {
    lathatocount =0;
    for (int i = also; i<felso; i += SzamLista::getLepeskoz() ){
        lathatocount++;
    }
    }
    setLathatocount(lathatocount);
}
