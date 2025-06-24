#include "castle.h"
#include "cavalry.h"
#include "infantry.h"
#include "machinery.h"
#include <fstream>
using namespace std;

#include "json.hpp"
using namespace nlohmann;

Castle::~Castle()
{
    for (MilitaryUnit* m : units){
        delete m;
    }
    units.clear();
}

void Castle::load(const string &infantryFile, const string &cavalryFile, const string &machineryFile)
{
    vector<string> files = {infantryFile, cavalryFile, machineryFile};

    for (const string& filename : files) {

    ifstream ifs(filename);
    json j;
    ifs>>j;
    for (size_t i=0; i< j.size(); i++){
        string n = j[i]["Name"];
       int ec = j[i]["EquipCost"];
       if (j[i].contains("Speed")){
            int s = j[i]["Speed"];
            units.push_back(new Cavalry(n,ec,s));
       } else if (j[i].contains("Weapon")){
            string w = j[i]["Weapon"];
            bool h = j[i]["Heavy"];
            units.push_back(new Infantry(n,ec,w,h));
       } else if (j[i].contains("Crew")){
            int c= j[i]["Crew"];
            units.push_back(new Machinery(n,ec,c));
       }
    }
    }
}

void Castle::printAll()
{
    for (MilitaryUnit* mu : units){
        mu->print(cout);
        cout << endl;
    }
}

Army Castle::readArmy(const string &filename)
{
    Army a;
    ifstream ifs(filename);
    string name;
    int count;
    while (ifs >>name >>count){
    Army::ArmyUnit au{};
        for (MilitaryUnit* m:units){
            if(m->getName()==name){
            au.unit = m->clone();
            break;
            }
        }
        au.unitcount = count;
      if (au.unit != nullptr){
      a.armyunits.push_back(au);
      }
    }
    return a;
}

ostream& operator<<(ostream& o, Castle& c) {
    for (MilitaryUnit* mu : c.units){
        mu->print(o);
        o << endl;
    }
    return o;
}
