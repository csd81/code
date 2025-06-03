#include "ijasz.h"


Ijasz::Ijasz(const std::string& _nev, int _szint, int _pontossag)
        : Karakter(_nev, _szint), pontossag(_pontossag) {}


    int Ijasz::eletero() const   {
        return 10 + szint * 3; // alap + szintenkénti növekedés
    }


    int Ijasz::sebzes() const   {
        int baseDamage = 3 + szint * 2; // alap + szintenkénti növekedés
        return (pontossag >= 90) ? baseDamage * 2 : baseDamage; // duplázás ha pontosság >= 90
    }


    void Ijasz::kiir() const   {
        std::cout << nev << ": " << szint << ". szintu ijasz, pontossag: " << pontossag << std::endl;
    }
