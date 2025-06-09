#include <iostream>
#include <string>
#include <vector>
using namespace std;


#include "character.h"
#include "mage.h"
#include "swordsman.h"
#include "marksman.h"
#include "dice.h"
#include "camp.h"
#include "team.h"

#define PART1 // Camp, beolvas JSON-bol
#define PART2A // Camp, print(), parameter nelkuli
#define PART2B // Camp, print(), 1 db azonosito
#define PART2C // Camp, print(), tobb azonosito
#define PART3 // Camp, getAttackPower()
#define PART4 // readTeam(), Team osztaly, abban print()
#define PART5 // Team, calculateStats()

int main()
{
    cout << "main() eleje!" << endl << endl;

    {
        cout << "--- Dice, kockadobas pelda:" << endl;
        Dice::seed(12345678); // nincs vele teendo
        for (int i=0;i<10;i++)
            cout << Dice::roll() << " ";
        cout << endl << endl;
    }

#ifdef PART1
    cout << "--- Camp, beolvas JSON-bol" << endl;
    Camp camp;
    camp.load("in-camp.json");
    cout << "Megtortent." << endl << endl;
#endif

#ifdef PART2A
    cout << "--- Camp, print(), parameter nelkuli" << endl;
    camp.print();
    cout << "Megtortent." << endl << endl;
#endif

#ifdef PART2B
    cout << "--- Camp, print(), 1 db azonosito" << endl;
    cout << "Kiiras-1:" << endl;
    camp.print("Kyrhell");
    cout << "Kiiras-2:" << endl;
    camp.print("Pietro");
    cout << "Kiiras-3:" << endl;
    camp.print("Quincy");
    cout << endl;
#endif

#ifdef PART2C
    cout << "--- Camp, print(), tobb azonosito" << endl;
    const vector<string> idlistA {
        "John", "Richard", "Kyrhell", "Pietro", "Oggie",
    };
    const vector<string> idlistB {
        "Norrey", "Maritimer",
    };
    cout << "Kiiras-Lista-A:" << endl;
    camp.print(idlistA);
    cout << endl;
    cout << "Kiiras-Lista-B:" << endl;
    camp.print(idlistB);
    cout << endl;
#endif

#ifdef PART3
    cout << "--- Camp, getAttackPower()" << endl;
    vector<string> idlistC{
        "John", "Quincy", "Legolas", "Pietro", "Kyrhell", "Oggie",
    };
    for (size_t k=0;k<idlistC.size();k++)
    {
        Dice::seed(k); // nincs vele teendo
        string id = idlistC[k];
        vector<int> attackPowers;
        for (int i=0;i<20;i++)
        {
            int ap = camp.getAttackPower(id);
            attackPowers.push_back(ap);
        }
        cout << id << " ->";
        for (int i=0;i<20;i++)
            cout << " " << attackPowers[i];
        cout << endl;
    }
    cout << endl;
#endif

#ifdef PART4
    cout << "--- readTeam(), Team osztaly, abban print()" << endl;
    Team t1 = camp.readTeam("in-team-1.txt");
    Team t2 = camp.readTeam("in-team-2.txt");
    cout << "*** 1. csapat:" << endl;
    t1.print();
    cout << endl;
    cout << "*** 2. csapat:" << endl;
    t2.print();
    cout << endl;
#endif

#ifdef PART5
    cout << "--- Team, calculateStats()" << endl;
    cout << "*** 1. csapat statisztikai:" << endl;
    Dice::seed(7777777);
    t1.calculateStats("out-team-1-stats.json");
    cout << endl;
    cout << "*** 2. csapat statisztikai:" << endl;
    Dice::seed(5555555);
    t2.calculateStats("out-team-2-stats.json");
    cout << endl;
#endif

    cout << "main() vege!" << endl;
    return 0;
}
