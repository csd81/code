#ifndef CASTLE_H
#define CASTLE_H
#include <vector>
#include <sstream>
#include "militaryunit.h"
#include "army.h"
using namespace std;

#include "json.hpp"
using namespace nlohmann;

class Castle
{
    std::vector<MilitaryUnit*> units;
public:
    ~Castle();
    void load(const string &infantryFile, const string &cavalryFile, const string &machineryFile);
    void printAll();
    friend ostream& operator<<(ostream&, Castle&);
    Army readArmy(const string& filename);
};

#endif // CASTLE_H
