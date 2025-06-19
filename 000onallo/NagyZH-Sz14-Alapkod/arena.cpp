#include "arena.h"
#include "katona.h"
#include "magus.h"
#include "pap.h"

Arena::~Arena()
{
    for (auto k : karakterek){
        delete k;
    }
}

void Arena::load(const string &filename)
{
    ifstream ifs(filename);
    if (!ifs.is_open()) {
        cerr << "error";
        return;
        }

    json data;
    ifs >> data;
    for (size_t i=0; i< data.size(); i++){
        string id = data[i]["Id"];
        int maxhp = data[i]["MaxHP"];
        if (data[i]["CharacterClass"]=="Soldier"){
            string type = data[i]["CharacterClass"];
            int power = data[i]["Power"];
            int armor = data[i]["Armor"];
            karakterek.push_back(new Katona(id, type, maxhp, power, armor));
            }
        else if (data[i]["CharacterClass"]=="Mage"){
            string type = data[i]["CharacterClass"];
            int magic = data[i]["Magic"];
            karakterek.push_back(new Magus(id, type, maxhp, magic));
            }
        else if (data[i]["CharacterClass"]=="Priest"){
            string type = data[i]["CharacterClass"];
            int magic = data[i]["Magic"];
            karakterek.push_back(new Pap(id, type, maxhp, magic));
            }
    }
}

void Arena::print(const string &id) const
{
    for (auto k : karakterek){
        if (k->getId()==id)
            k->print();
    }

}

void Arena::printAll() const
{
    for (auto k : karakterek){

            k->print();
    }
}

void Arena::performAction(Karakter &source, Karakter &dest)
{
    source.action(dest);
}

void Arena::performAction(const string &sourceId, const string &destId)
{
    Karakter *src = nullptr;
    Karakter *dst = nullptr;
    for (auto k : karakterek) {
        if (k->getId() == sourceId) src = k;
        if (k->getId() == destId) dst = k;
    }
    if (src && dst)
        performAction(*src, *dst);
}



void Arena::performList(ActionList &al)
{
    for(size_t i=0; i<al.getId1().size(); i++) {
        Karakter *c1 = nullptr;
        Karakter *c2 = nullptr;
        for (auto k: karakterek){
            if (al.getId1()[i]==k->getId())
                c1 = k;
            if (al.getId2()[i]==k->getId())
                c2 = k;
        }
    if (c1 && c2)
        performAction(*c1, *c2);
    }
}
