#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// sajat include-ok (az osztalyok szabadon atnevezhetok)
#include "castle.h"
#include "army.h"

#define PART1 // Castle, beolvas JSON-bol
#define PART2A // Castle, printAll()
#define PART2B // Castle, kiiro << operator
#define PART3 // Castle, readArmy(), Army osztaly
#define PART4 // Army, display()
#define PART5A // Army, getSpeed()
#define PART5B // Army, soldierCount()
#define PART5C // Army, horseCount()
#define PART6A // Army, dailyCost() alap
#define PART6B // Army, dailyCost(), valtoztathato napi ellatmany
#define PART7 // Army, totalMissionCost()

int main()
{
    cout << "main() eleje!" << endl << endl;

#ifdef PART1
    cout << "--- Castle, beolvas JSON-bol" << endl;
    Castle castle;
    castle.load("in-castle-infantry.json",
                "in-castle-cavalry.json",
                "in-castle-machinery.json");
    cout << "Megtortent." << endl << endl;
#endif

#ifdef PART2A
    cout << "--- Castle, printAll()" << endl;
    castle.printAll();
    cout << endl;
#endif

#ifdef PART2B
    cout << "--- Castle, kiiro << operator" << endl;
    stringstream sstream;
    cout << "*** 1. Kiiras string-be (nincs output)" << endl;
    sstream << "~~~" << endl << castle << "~~~" << endl << endl;
    cout << "*** 2. A string tartalma:" << endl;
    cout << sstream.str();
#endif

#ifdef PART3
    cout << "--- Castle, readArmy(), Army osztaly" << endl;
    Army army1 = castle.readArmy("in-army-1.txt");
    Army army2 = castle.readArmy("in-army-2.txt");
    Army army3 = castle.readArmy("in-army-3.txt");
    Army army4 = castle.readArmy("in-army-4.txt");
    vector<Army*> armies{&army1,&army2,&army3,&army4};
    cout << "Beolvasas megtortent." << endl << endl;
#endif

#ifdef PART4
    cout << "--- Army, display()" << endl;
    for (size_t i=0;i<armies.size();i++)
    {
        cout << "Army-" << (i+1) << ":" << endl;
        armies[i]->display();
        cout << endl;
    }
#endif

#ifdef PART5A
    cout << "--- Army, getSpeed()" << endl;
    for (size_t i=0;i<armies.size();i++)
    {
        int speed = armies[i]->getSpeed();
        cout << "Army-" << (i+1) << " menetsebessege: " << speed << endl;
    }
    cout << endl;
#endif

#ifdef PART5B
    cout << "--- Army, soldierCount()" << endl;
    for (size_t i=0;i<armies.size();i++)
    {
        int soldiers = armies[i]->soldierCount();
        cout << "Army-" << (i+1) << " katonak szama: " << soldiers << endl;
    }
    cout << endl;
#endif

#ifdef PART5C
    cout << "--- Army, horseCount()" << endl;
    for (size_t i=0;i<armies.size();i++)
    {
        int horses = armies[i]->horseCount();
        cout << "Army-" << (i+1) << " lovak szama: " << horses << endl;
    }
    cout << endl;
#endif

#ifdef PART6A
    cout << "--- Army, dailyCost() alap" << endl;
    for (size_t i=0;i<armies.size();i++)
    {
        int daily_cost = armies[i]->dailyCost();
        cout << "Army-" << (i+1) << " napi ellatmany: " << daily_cost << endl;
    }
    cout << endl;
#endif

#ifdef PART6B
    cout << "--- Army, dailyCost(), valtoztathato napi ellatmany" << endl;
    Army::setSalary(28);
    cout << "Napi koltsegek megemelt ellatmany mellett:" << endl;
    for (size_t i=0;i<armies.size();i++)
    {
        int daily_cost = armies[i]->dailyCost();
        cout << "Army-" << (i+1) << " napi ellatmany (+3/katona): " << daily_cost << endl;
    }
    cout << endl;
    Army::setSalary(25);
#endif

#ifdef PART7
    cout << "--- Army, totalMissionCost()" << endl;
    vector<int> km_list {77, 263};
    vector<int> days_served_list {14, 60};
    for (size_t m=0;m<2;m++)
    {
        int km = km_list[m];
        int days_served = days_served_list[m];
        cout << "Kuldetes: " << km << " km";
        cout << ", " << days_served << " nap a masik varban" << endl;
        for (size_t i=0;i<armies.size();i++)
        {
            int total = armies[i]->totalMissionCost(km,days_served);
            cout << "Army-" << (i+1) << " teljes koltsege: " << total << endl;
        }
        cout << endl;
    }
#endif

    cout << "main() vege!" << endl;
    return 0;
}
