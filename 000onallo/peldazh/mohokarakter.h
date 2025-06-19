#ifndef MOHOKARAKTER_H
#define MOHOKARAKTER_H

#include "karakter.h"

class Mohokarakter : public Karakter
{
    int nehezseg;
    static int darab;
public:
    Mohokarakter(const string &nev, int pont, int nehezseg);

    int getNehezseg() const;




    bool vegrehajt(Akcio &) override;
    static int getDarab();
};

#endif // MOHOKARAKTER_H
