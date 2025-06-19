#ifndef PLANETRIP_H
#define PLANETRIP_H
#include <iostream>
using namespace std;

#include "trip.h"

class PlaneTrip : public Trip
{
    string travelClass;

public:
    PlaneTrip(const string &source, const string &dest, int duration, int price, const string &travelClass);

    void printData() const override;
};

#endif // PLANETRIP_H
