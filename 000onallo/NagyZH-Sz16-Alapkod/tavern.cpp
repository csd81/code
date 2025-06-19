#include "tavern.h"
#include "knight.h"
#include "mage.h"
#include "ranger.h"

void Tavern::load(const string& filename)
{
    ifstream ifs(filename);
    if(!ifs.is_open()){
        cout << "file error";
        return;
    }
    json data;
    ifs >> data;

        for (size_t i=0; i< data.size(); i++ ){
            Character* c;
            string id=data[i]["Id"];
            int price=data[i]["Price"];
            if (id[0]=='R'){
                int agility= data[i]["Agility"];
                c=new Ranger(id, price, agility);
            } else if (id[0]=='K'){
                int strength= data[i]["Strength"];
                c=new Knight(id, price, strength);
            } else if (id[0]=='M'){
                double magic= data[i]["Magic"];
                c=new Mage(id, price, magic);
            }
            characters.push_back(c);
    }
}

void Tavern::loadAll(const string& f1, const string& f2, const string& f3)
{
    load(f1);
    load(f2);
    load(f3);
}

void Tavern::printAll()
{
    for (auto c : characters){
        c->print();
    }
}

vector<Character *> Tavern::getCharacters() const
{
    return characters;
}

Tavern::Tavern()
{

}

Tavern::~Tavern()
{
    for (auto c : characters){
        delete c;
    }
}

Tavern::Tavern(const vector<Character *> &characters) : characters(characters)
{}
