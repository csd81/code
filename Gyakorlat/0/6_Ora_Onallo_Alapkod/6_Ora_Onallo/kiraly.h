#ifndef KIRALY_H
#define KIRALY_H

#include "figura.h"

class Kiraly : public Figura
{
public:
    Kiraly(const string &pos);

    bool lephet(string poz) const;
    char jeloles() const;
};

#endif // KIRALY_H
