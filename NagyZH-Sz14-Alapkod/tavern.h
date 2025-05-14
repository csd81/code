#ifndef TAVERN_H
#define TAVERN_H
#include "warrior.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "json.hpp"

class Tavern
{
    std::vector<Warrior*> warriors;
public:
    void loadAll(const std::string& knightsFile,
                 const std::string& rangersFile,
                 const std::string& magesFile);
    void printAll() const;
    Warrior* getWarriorById(const std::string& id) const;
};

#endif // TAVERN_H
