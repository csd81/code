#ifndef ACTIONLIST_H
#define ACTIONLIST_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ActionList
{
    struct Action{
        string id1;
        string id2;
    };
    vector<Action> actions;
public:
    ActionList(const string& file);
    void printPairs() const;
    const vector<Action>& getPairs() const;

};

#endif // ACTIONLIST_H
