#ifndef SOKSZOG_H
#define SOKSZOG_H

#include "halmaz.h"
#include "teglalap.h"

// --- SPECIFIKÁCIÓ: SOKSZÖG ---
// 23. konstruktor: megnevezést vár, tetszőleges számú pont
// 24. kerulet() — pontok közti távolságok összege + első-utolsó között is
// 25. bennfoglalo() — minimális Teglalap, ami tartalmazza a Sokszöget

class Sokszog : public Halmaz
{
public:
    Sokszog(const string& megnevezes);

    double kerulet () const;
    Teglalap bennfoglalo () const;
};

#endif // SOKSZOG_H
