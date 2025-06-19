#include "adatmegjelenito.h"
#include <iostream>
using namespace std;

string AdatMegjelenito::getSzin() const
{
    return szin;
}

bool AdatMegjelenito::getLathato() const
{
    return lathato;
}

void AdatMegjelenito::setLathato(bool newLathato)
{
    lathato = newLathato;
}


int AdatMegjelenito::getLathatocount() const
{
    return lathatocount;
}

void AdatMegjelenito::setLathatocount(int newLathatocount)
{
    lathatocount = newLathatocount;
}

AdatMegjelenito::AdatMegjelenito(const string &szin, bool lathato) : szin(szin),
    lathato(lathato)
{}

AdatMegjelenito::~AdatMegjelenito()
{

}
