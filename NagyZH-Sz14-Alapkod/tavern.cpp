#include "tavern.h"

#include <fstream>
using namespace std;

#include "json.hpp"
#include "knight.h"
#include "mage.h"
#include "ranger.h"
using namespace nlohmann;

void Tavern::loadAll(const string &knightsFile, const string &rangersFile, const string &magesFile)
{
    std::ifstream kfile(knightsFile);
    json kjson;
    kfile >>  kjson;
    for (const auto& k : kjson) {
        warriors.push_back(new Knight(k["Id"], k["Price"], k["Strength"]));
    }


    std::ifstream rfile(rangersFile);
    json rjson;
    rfile >>  rjson;
    for (const auto& r : rjson) {
        warriors.push_back(new Ranger(r["Id"], r["Price"], r["Agility"]));
    }

    std::ifstream mfile(magesFile);
    json mjson;
    mfile >>  mjson;
    for (const auto& m : mjson) {
        warriors.push_back(new Mage(m["Id"], m["Price"], m["Magic"]));
    }


}

void Tavern::printAll() const
{
    for (const auto& w : warriors) {
        w->print();
    }
}


Warrior *Tavern::getWarriorById(const string &id) const
{
    for (const auto& w : warriors) {
        if (w->getId() == id)
            return w;

    }
    return nullptr;


}
