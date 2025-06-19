#include "kepfajl.h"



int KepFajl::getSzelesseg() const
{
    return szelesseg;
}

int KepFajl::getMagassag() const
{
    return magassag;
}

void KepFajl::adatok() const
{
    cout << "Nev: " << nev << ", fontossag: " << fontossag;
    if (meret >= 10000)
        cout << ", meret: " << meret << ", szelesseg: " << szelesseg << ", magassag: " << magassag;
    cout << endl;
}

int KepFajl::operator*() const
{
    return szelesseg * magassag;
}

KepFajl::KepFajl(const std::string &nev, int meret, int fontossag, int szelesseg, int magassag) : Fajl(nev, meret, fontossag),
    szelesseg(szelesseg),
    magassag(magassag)
{}
