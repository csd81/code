#ifndef ARENA_H
#define ARENA_H
#include <iostream>
#include <vector>
#include "character.h"
#include "actionlist.h"
#include "mage.h"
#include "soldier.h"
#include "priest.h"
using namespace std;


class Arena
{
    vector<Character*> characters;
public:
    virtual ~Arena();
    void load(const string& file);
    void printOne(const string& id) const;
    void printAll() const;
    void performAction(const string& id1, const string& id2);
    void performList(const ActionList& al);
};

#endif // ARENA_H
