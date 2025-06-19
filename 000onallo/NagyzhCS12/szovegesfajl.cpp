#include "szovegesfajl.h"

string SzovegesFajl::utvonal = "";


std::string SzovegesFajl::getTartalom() const
{
    return tartalom;
}

void SzovegesFajl::adatok() const
{
string utvonalnev = utvonal.empty() ? nev : utvonal + "/" + nev;
if (fontossag >= 5)
    std::cout << "Nev: " << utvonalnev << ", meret: " << meret << ", tartalom: " << tartalom << std::endl;
else
    std::cout << "Nev: " << utvonalnev << std::endl;

}

void SzovegesFajl::operator+=(const string& szoveg)
{
    tartalom += szoveg;
}

std::string SzovegesFajl::getUtvonal()
{
    return utvonal;
}

void SzovegesFajl::setUtvonal(const std::string &newUtvonal)
{
    utvonal = newUtvonal;
}

SzovegesFajl::SzovegesFajl(const std::string &nev, int meret, int fontossag, const std::string &tartalom) : Fajl(nev, meret, fontossag),
    tartalom(tartalom)
{}
