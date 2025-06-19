#ifndef TRIP_H
#define TRIP_H
#include <iostream>
using namespace std;

class Trip
{
    string source;
    string dest;
    int duration;
    int price;

public:

    Trip(const string &source, const string &dest, int duration, int price);
    virtual ~Trip();
    virtual void printData() const;
    string getSource() const;
    string getDest() const;
    int getDuration() const;
    int getPrice() const;
};

#endif // TRIP_H
