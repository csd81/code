#ifndef VEZER_H
#define VEZER_H

#include "figura.h"

class Vezer : public Figura
{
public:
    Vezer(const string &pos);
    bool lephet(string poz) const override;
    char jeloles() const override;
};

#endif // VEZER_H
