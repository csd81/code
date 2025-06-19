#include "traintrip.h"



void TrainTrip::printData() const
{
    Trip::printData();
    cout << " Megállók száma: " << stopCount;
}

TrainTrip::TrainTrip(const string &source, const string &dest, int duration, int price, int stopCount) : Trip(source, dest, duration, price),
    stopCount(stopCount)
{}
