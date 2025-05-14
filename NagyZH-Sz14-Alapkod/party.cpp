#include "party.h"
#include <fstream>
#include <string>
// #include "knight.h"
// #include "mage.h"
// #include "ranger.h"

using namespace std;

Party::Party(const std::string& partyFile, const Tavern& tavern) {
    std::ifstream file(partyFile);
    std::string line;
    while (std::getline(file, line)){
        std::shared_ptr<Warrior> w =  tavern.getWarriorById(line);
        if (w) {
            members.push_back(w);
        }
    }


}

void Party::printAll() const
{
    for (const auto& m : members){
        m->print();
    }

}

int Party::getTotalCost() const
{
    int total = 0;
    for (const auto& m : members) {
        total += m->getPrice();
    }
    return total;
}

void Party::raid(Dragon &dragon)
{
    size_t startIndex = 0;
    while (!members.empty()){
        std::cout << "\nParty attacks\n";
        for (size_t i = startIndex; i < members.size(); ++i){
            members[i]->attack(dragon);
            std::cout << "dragon's health:" << dragon.getHealth() << "\n";
            if (dragon.getHealth() <= 0){
                std::cout << "\nThe dragon has been defeated! Party wins!\n";
                return;
            }

        }
        if (!members.empty()){
            std::cout << "\nThe dragon retaliates and devours " << members.front()->getId() << "\n";
            members.erase(members.begin());

        }

    }
    std::cout << "\nThe dragon has devoured the entire party. Dragon wins.\n";


}
