#ifndef CAMP_H
#define CAMP_H
#include <fstream>
#include <iostream>
#include <vector>
#include "json.hpp"
#include "team.h"
#include "character.h"
using namespace std;
using namespace nlohmann;

class Camp
{
    vector<Character*> characters;
public:
    ~Camp();
    void load(const string& filename);


    void print() const;
    void print(string id) const;
    void print(vector<string>) const;

    int getAttackPower(string id) const;
    Team readTeam(string filename);

};

#endif // CAMP_H
