#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>

class Vehicle
{
    std::string id;
    int mass;
    int speed;
public:
    Vehicle(const std::string& i, int m, int s);
    virtual ~Vehicle();
    virtual std::string  getType() const = 0;
    std::string getId() const;
    int getMass() const;
    int getSpeed() const;

    virtual void print() const = 0;




};

#endif // VEHICLE_H
