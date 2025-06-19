#ifndef ACTIONLIST_H
#define ACTIONLIST_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class ActionList
{
    vector<string> id1;
    vector<string> id2;
public:
    ActionList(const string&);

    void printSome();
    vector<string> getId1() const;
    vector<string> getId2() const;
};

#endif // ACTIONLIST_H
