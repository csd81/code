#include <iostream>
#include <fstream>
#include "camp.h"
#include "marksman.h"
#include "mage.h"
#include "swordsman.h"
#include "json.hpp"

using namespace std;
using namespace nlohmann;

void Camp::load(const string &filename)
{
    ifstream ifs(filename);
    json data;
    ifs >> data;

    for (size_t i = 0; i < data.size(); i++){
        string id = data[i]["Id"];
        int price = data[i]["Price"];
        if(data[i]["Type"] == "Marksman"){
            int agility = data[i]["Agility"];
            bool elite = data[i]["Elite"];
            characters.push_back(new Marksman(id, price, agility, elite));}
        if(data[i]["Type"] == "Swordsman"){
            int strength = data[i]["Strength"];
            characters.push_back(new Swordsman(id, price, strength));}
        if(data[i]["Type"] == "Mage"){
            int magic = data[i]["Magic"];
            characters.push_back(new Mage(id, price, magic));}
    }
}


void Camp::print() const
{
    for (Character* c : characters){
        c->print();
    }
}

void Camp::print(string id) const
{
    for (Character* c : characters){
        if (c->getId()==id){
            c->print();
        }
    }
}

void Camp::print(vector<string> sv) const
{
    for (string s : sv){
        for (Character* c : characters){
            if (c->getId()==s){
                c->print();
            }
        }
    }
}

int Camp::getAttackPower(string id) const
{
    for (Character* c : characters){
        if (c->getId()==id){
            return c->attackPower();
        }
    }
    return 15;
}

Team Camp::readTeam(string filename)
{
    Team t;
    ifstream ifs(filename);
    if (!ifs){
        throw std::logic_error("error");

    }

        string id;
    while(ifs >> id){
        for(Character* c : characters){
            if (c->getId()==id)
                t.addMember(c);
            }
    }
    return t;
}























