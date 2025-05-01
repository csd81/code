#ifndef SZAMOK_H
#define SZAMOK_H

namespace Tarolo
{

class Szamok
{
    double *tomb;
    unsigned meret;
public:
    Szamok(unsigned meret, double ertek = 0.0);
    ~Szamok();

    unsigned darabLeker() const;
    void ertekBeallit(unsigned index, double ertek);
    double ertekLeker(unsigned index) const;
};

}

#endif // SZAMOK_H
