#ifndef MAXTIMEFROM_H
#define MAXTIMEFROM_H

#include "trip.h"
#include "filterbase.h"

class MaxTimeFrom : public FilterBase<Trip*>
{
    std::string from;
    int maxTime;

public:
    MaxTimeFrom(const std::string& from, int maxTime)
        : from(from), maxTime(maxTime) {}

    bool match(Trip* const& trip) const override{
        return (trip->getSource() == from && trip->getDuration() <= maxTime);

    }
};

#endif // MAXTIMEFROM_H
