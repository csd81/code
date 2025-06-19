#include "party.h"

vector<Character *> Party::getInparty() const
{
    return inparty;
}

Party::Party(const string &filename, Tavern &t)
{
    ifstream ifs(filename);
    if (!ifs.is_open()){
        cerr <<"error";
    }

    string adat;
    while (ifs >> adat){
        adatok.push_back(adat);
    }
    for (auto c : t.getCharacters()){
        for (string s: adatok){
            if (c->getId()==s)
                inparty.push_back(c);
        }
    }



}

Party::~Party()
{

}

void Party::printAll()
{
    for (auto c : inparty){
        c->print();
    }
}

int Party::getTotalCost()
{
    int total = 0;
    for (auto c : inparty){
        total+=c->getPrice();
    }
    return total;
}

void Party::raid(Dragon & d)
{

    while(d.getHP() > 0 && !inparty.empty()){
    for (auto c : inparty){
        d.setHP( d.getHP() - c->attack(d));
        }
         inparty.pop_back();
    }
        if (d.getHP()<=0) {
            cout << "party wins!\n";
        } else if (inparty.empty()){
            cout << "dragony wins!\n";
            return;}
}
