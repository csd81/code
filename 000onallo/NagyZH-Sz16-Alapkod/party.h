#ifndef PARTY_H
#define PARTY_H

#include "dragon.h"
#include "tavern.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Party
{
    vector<string> adatok;
    vector<Character*> inparty;
public:
    Party(const string& filename, Tavern& t);
    ~Party();
    void printAll();
    int getTotalCost();
    void raid(Dragon&);
    vector<Character *> getInparty() const;
};

#endif // PARTY_H
