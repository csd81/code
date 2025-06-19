#include "tranzakcio.h"



string Tranzakcio::getSzamlaszam() const
{
    return szamlaszam;
}

int Tranzakcio::getOsszeg() const
{
    return osszeg;
}

bool Tranzakcio::getJovairas() const
{
    return jovairas;
}

bool Tranzakcio::operator*()
{
    if(osszeg <=0) return false;
    else return CDV();
}

bool Tranzakcio::CDV() {
    const int szorzok[] = {9, 7, 3, 1, 9, 7, 3, 1};
    if (szamlaszam.length() != 16) return false;

    // Első blokk: 0-7 (8 karakter), ellenőrző jegy: szamlaszam[7]
    int sum1 = 0;
    for (int i = 0; i < 7; ++i) {
        if (!isdigit(szamlaszam[i])) return false;
        sum1 += (szamlaszam[i] - '0') * szorzok[i];
    }
    int check1 = (10 - (sum1 % 10)) % 10;
    if (szamlaszam[7] - '0' != check1) return false;

    // Második blokk: 8-15 (újabb 8 karakter), ellenőrző jegy: szamlaszam[15]
    int sum2 = 0;
    for (int i = 8; i < 15; ++i) {
        if (!isdigit(szamlaszam[i])) return false;
        sum2 += (szamlaszam[i] - '0') * szorzok[i - 8];
    }
    int check2 = (10 - (sum2 % 10)) % 10;
    if (szamlaszam[15] - '0' != check2) return false;

    return true;
}

ostream &operator<<(ostream & os, Tranzakcio t)
{
    os << t.szamlaszam << " ";
    os << t.osszeg << " ";
    os <<  (t.jovairas? "jovairas" :"terheles");
    os << "\n";
    return os;
}

Tranzakcio::Tranzakcio(const string &szamlaszam, int osszeg, bool jovairas) : szamlaszam(szamlaszam),
    osszeg(osszeg),
    jovairas(jovairas)
{}
