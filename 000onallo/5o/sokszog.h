#ifndef SOKSZOG_H
#define SOKSZOG_H

#include "halmaz.h"
#include "teglalap.h"

class Sokszog : public Halmaz
{
public:
    Sokszog(string megn);
    double kerulet() const;
    Teglalap bennfoglalo() const;
};

#endif // SOKSZOG_H
