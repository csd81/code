#ifndef FREIGHTCAR_H
#define FREIGHTCAR_H
#include "vehicle.h"

class FreightCar : public Vehicle {
    int quantity;
    std::string type;
public:
    FreightCar(const std::string &id, int tomeg, int sebesseg, int quantity);
    std::string getType() const;
    void print() const;
};



#endif //FREIGHTCAR_H
