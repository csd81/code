#ifndef FREIGHTCAR_H
#define FREIGHTCAR_H

#include "vehicle.h"

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
