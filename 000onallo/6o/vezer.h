#ifndef VEZER_H
#define VEZER_H

#include "figura.h"

class Vezer : public Figura
{
public:
    Vezer(string p): Figura(p) {}
    bool lephet(const string &pos) const override;
    char jeloles() const override;
};

#endif // VEZER_H
