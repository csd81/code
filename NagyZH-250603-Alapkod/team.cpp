#include "team.h"

void Team::addMember(Character *c)
{
    members.push_back(c);
}

void Team::print()
{
    for (Character* c :members){
        c->print();
    }

}

void Team::calculateStats(string jsonFile)
{
    json data = json::array();
    for (Character* c : members){
        int price = c->getPrice();
    int xattack=0;
    int n = 100;
        for (int i=0; i<n; i++){
        xattack+=c->attackPower();
    }
        xattack/=n;
    double ratio = xattack/price;
        cout << "ID: " << c->getId()
             << " expected attack: "  << xattack
             << " attack/price ratio: "  << ratio;
    data.push_back({
        {"ID", c->getId()},
        {"xattack", xattack},
        {"ratio", ratio}
    });
    }
    ofstream ofs(jsonFile);
    ofs << data.dump(4);
}
