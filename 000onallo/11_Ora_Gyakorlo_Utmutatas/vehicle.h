#ifndef VEHICLE_H
#define VEHICLE_H
#include <iostream>

class Vehicle
{
    std::string id;
    int tomeg;
    int sebesseg;

public:
    Vehicle(std::string id, int tomeg, int sebesseg);
    virtual ~Vehicle() = default;

    std::string getId() const;
    int getMass() const;
    int getSpeed() const;

    virtual std::string getType() const =0;
    virtual void print() const =0;


};




#endif // VEHICLE_H
