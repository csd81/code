#include "trip.h"



Trip::~Trip()
{

}

void Trip::printData() const
{
cout << "Honnan: " <<source<< " Hova: " <<dest<< " Időtatam: "<< duration<< " Ár: "<< price<< endl;
}

string Trip::getSource() const
{
    return source;
}

string Trip::getDest() const
{
    return dest;
}

int Trip::getDuration() const
{
    return duration;
}

int Trip::getPrice() const
{
    return price;
}

Trip::Trip(const string &source, const string &dest, int duration, int price) : source(source),
    dest(dest),
    duration(duration),
    price(price)
{}
