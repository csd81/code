#ifndef TRAINTRIP_H
#define TRAINTRIP_H
#include <iostream>
using namespace std;

#include "trip.h"

class TrainTrip : public Trip
{
    int stopCount;
public:
    TrainTrip(const string &source, const string &dest, int duration, int price, int stopCount);

    void printData() const override;
};

#endif // TRAINTRIP_H
