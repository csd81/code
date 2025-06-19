#ifndef TAVERN_H
#define TAVERN_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "character.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

class Tavern
{
    vector<Character*>  characters;
public:
    Tavern();
    ~Tavern();
    Tavern(const vector<Character *> &characters);
    void loadAll(const string& f1, const string& f2, const string& f3);
    void load(const string& f);
    void printAll();
    vector<Character *> getCharacters() const;
};

#endif // TAVERN_H
