#ifndef PARTY_H
#define PARTY_H

#include "warrior.h"
#include "dragon.h"

#include <tavern.h>
#include <vector>
class Party
{
    vector<std::shared_ptr<Warrior>> members;
public:
    Party(const std::string& partyFile, const Tavern& tavern);
    void printAll() const;
    int getTotalCost() const;
    void raid(Dragon& dragon);
};

#endif // PARTY_H
