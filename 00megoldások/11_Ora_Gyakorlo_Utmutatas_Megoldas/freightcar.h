#ifndef FREIGHTCAR_H
#define FREIGHTCAR_H

#include "vehicle.h"

// FreightCar: a tehervagonokat írja le, legyen egy plusz tulajdonsága, 
// amely a tehervagonban szállítható termékek mennyiségét adja meg (int). 
// A típus szövege "FreightCar".

class FreightCar : public Vehicle
{
    int capacity;
public:
    FreightCar(const string& id,
               int mass,
               int speed,
               int capacity);

    void print() const;

    string getType() const;
};

#endif // FREIGHTCAR_H
