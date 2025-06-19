
#include "adathalmaz.h"

AdatHalmaz::AdatHalmaz() : darab(0),
    megjelenitok(nullptr)
{}

AdatHalmaz::~AdatHalmaz()
{
    for (int i = 0; i < darab; i++){
        delete megjelenitok[i];
        megjelenitok[i] = nullptr;
    }
    delete [] megjelenitok;
    megjelenitok = nullptr;
}

int AdatHalmaz::getMeret()
{
    return darab;
}

AdatHalmaz &AdatHalmaz::operator<<(AdatMegjelenito *am)
{
    AdatMegjelenito **  ujmegjelenitok = new AdatMegjelenito*[darab+1] ;
    for (int i = 0; i < darab; i++){
        ujmegjelenitok[i] = megjelenitok[i];
    }
    ujmegjelenitok[darab] = am;
    delete [] megjelenitok;
    megjelenitok=ujmegjelenitok;
    darab++;
    return *this;
}

void AdatHalmaz::kiir()
{
    for (int i = 0; i < darab; i++){
        megjelenitok[i]->megjelenit();
    }
}

AdatHalmaz &AdatHalmaz::operator~()
{
    for (int i=0; i<darab; i++){
        megjelenitok[i]->setLathato(!megjelenitok[i]->getLathato());
    }
    return *this;
}

bool operator< (AdatHalmaz& a1, AdatHalmaz& a2){
    int bal=0;
    int jobb=0;
    for (int i=0; i<a1.darab; i++){
        bal+= a1.megjelenitok[i]->getLathatocount();
        }
    for (int i=0; i<a2.darab; i++){
        jobb+= a2.megjelenitok[i]->getLathatocount();
    }
    if (bal<jobb) return true;
    else return false;
}
