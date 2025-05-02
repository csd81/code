#ifndef SZAMOK_H
#define SZAMOK_H

#ifndef SZAMOK_HPP
#define SZAMOK_HPP

namespace Tarolo {

class Szamok {
private:
    double* tomb;
    int meret;

public:
    Szamok(int m, double kezdo = 0);
    ~Szamok();

    int darabLeker() const;
    void ertekBeallit(int index, double ertek);
    double ertekLeker(int index) const;
};

}

#endif


#endif // SZAMOK_H
