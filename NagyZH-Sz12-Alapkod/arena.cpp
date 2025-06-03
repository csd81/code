#include <iostream>
#include <fstream>
#include "json.hpp"
#include "arena.h"
using namespace std;
using namespace nlohmann;

Arena::~Arena() {
    for (auto c : characters) {
        delete c;
    }
}


void Arena::load(const string& file)
{

    ifstream infile(file);
    if (!infile.is_open()) {
        cerr << "Hiba: nem sikerült megnyitni a fájlt: " << file << endl;
        return;
    }

    json data;
    infile >> data;

    for (size_t i = 0; i<data.size(); i++){
        string id =data[i]["Id"];
        int maxhp =data[i]["MaxHP"];
        if (data[i]["CharacterType"]=="Soldier"){
            int power =data[i]["Power"];
            int armor =data[i]["Armor"];
            characters.push_back(new Soldier(id, maxhp, power, armor));
        }

        if (data[i]["CharacterType"]=="Mage"){
            int magic =data[i]["Magic"];
            characters.push_back(new Mage(id, maxhp, magic));
        }
        if (data[i]["CharacterType"]=="Priest"){
            int magic =data[i]["Magic"];
            characters.push_back(new Priest(id, maxhp,  magic));
        }
    }
}

void Arena::printOne(const string &id) const
{
    for( auto c : characters){
        if (c->getId()==id){
            c->print();
        }
    }
}

void Arena::printAll() const
{
    for( auto c : characters)
        c->print();
}

void Arena::performAction(const string &id1, const string &id2)
{
    Character* attacker = nullptr;
    Character* target = nullptr;

    for (auto c : characters){
        if (c->getId() == id1) attacker = c;
        if (c->getId() == id2) target = c;
    }

    if (attacker && target){
        attacker->action(* target);
    }


}

void Arena::performList(const ActionList& al)
{
    for (const auto& action : al.getPairs()){
        performAction(action.id1, action.id2);

    }
}









