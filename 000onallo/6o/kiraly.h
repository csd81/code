#ifndef KIRALY_H
#define KIRALY_H

#include "figura.h"

class Kiraly : public Figura
{
public:
    Kiraly(string p): Figura(p) {}
    bool lephet(const string &pos) const override;
    char jeloles() const override;
};

#endif // KIRALY_H
