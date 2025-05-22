#ifndef TAVERN_H
#define TAVERN_H
#include "warrior.h"
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "json.hpp"
using json = nlohmann::json;

class Tavern
{
    vector<std::shared_ptr<Warrior>> warriors;
public:
    void loadAll(const std::string& knightsFile,
                 const std::string& rangersFile,
                 const std::string& magesFile);
    void printAll() const;
    std::shared_ptr<Warrior> getWarriorById(const std::string& id) const;
};

#endif // TAVERN_H
