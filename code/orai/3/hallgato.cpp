#include "hallgato.h"
#include <iostream>

Hallgato::Hallgato(const string &vnev, const string &knev, unsigned int kor,
                   const string &neptun, unsigned int felevek) :
    Szemely(vnev, knev, kor),
    neptunKod(neptun),
    felevekSzama(felevek)
{
}

void Hallgato::kiir() const
{
    // cout << teljesNev() << " " << getEletkor()
    //      << " " << neptunKod << " " << felevekSzama << endl;
    Szemely::kiir();
    cout << neptunKod << " " << felevekSzama << endl;
}

bool Hallgato::furcsa() const
{
    return getEletkor() < 18 + 2 * felevekSzama;
}
