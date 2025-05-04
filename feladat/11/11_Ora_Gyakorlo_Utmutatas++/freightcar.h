#ifndef FREIGHTCAR_H
#define FREIGHTCAR_H
#include "vehicle.h"

class FreightCar : public Vehicle
{
    int freightCapacity;
public:
    FreightCar(std::string i, int s, int m, int f);
    std::string getType() const;
    void print() const;
};

#endif // FREIGHTCAR_H
