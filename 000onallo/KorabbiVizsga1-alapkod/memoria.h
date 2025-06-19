#ifndef MEMORIA_H
#define MEMORIA_H

#include "alkatresz.h"

class Memoria : public Alkatresz
{   int kapacitas, sebesseg;
public:
    Memoria(const string &gyarto, const string &tipus, int kapacitas=16, int sebesseg=3200);

    int getKapacitas() const;
    int getSebesseg() const;


    int ar() const override;
};

#endif // MEMORIA_H





