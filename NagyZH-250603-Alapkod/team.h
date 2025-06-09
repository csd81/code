#ifndef TEAM_H
#define TEAM_H
#include <vector>
#include <iostream>
#include <fstream>
#include "character.h"
#include "json.hpp"
using namespace std;
using namespace nlohmann;

class Team
{
    vector<Character*> members;
public:
    void addMember(Character* c);
    void print();
    void calculateStats(string jsonFile);

};

#endif // TEAM_H
