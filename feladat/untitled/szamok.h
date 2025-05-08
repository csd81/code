#ifndef SZAMOK_H
#define SZAMOK_H

class Szamok
{
    double *tomb;
    unsigned int meret;
    int x;
    int y;

public:
    Szamok(unsigned int darab, double alap = 0);
    ~Szamok();
    unsigned int darabLeker() const;
    void ertekBeallit(unsigned int i, double d);
    double ertekLeker(unsigned int i) const;
    int getX() const;
    void setX(int newX);
    int getY() const;
    void setY(int newY);
};

#endif // SZAMOK_H
