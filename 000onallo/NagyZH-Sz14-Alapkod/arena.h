#ifndef ARENA_H
#define ARENA_H
#include <iostream>
#include <vector>
#include <fstream>
#include "actionlist.h"
#include "json.hpp"
#include "karakter.h"
using namespace std;
using namespace nlohmann;

class Arena
{
    vector<Karakter*> karakterek;

public:
    ~Arena();
    void load(const string& filename);
    void print(const string& id) const;
    void printAll() const;
    void performAction(Karakter &source, Karakter &dest);
    void performAction(const string &sourceId, const string &destId);

    void performList(ActionList&);
};

#endif // ARENA_H
