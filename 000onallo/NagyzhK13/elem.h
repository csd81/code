#ifndef ELEM_H
#define ELEM_H
#include <iostream>
using namespace std;

class Elem
{
    int x, y;
    int szelesseg, magassag;
public:
    Elem(int x, int y, int szelesseg, int magassag);
    virtual ~Elem();
    int getX() const;
    int getY() const;
    int getSzelesseg() const;
    int getMagassag() const;
    virtual void kirajzol();
    virtual void aktival(int egesz = 5)  = 0;
    virtual Elem* clone() const = 0;
};

#endif // ELEM_H




