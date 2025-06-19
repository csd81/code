#include <iostream>
using namespace std;

// sajat include-ok (osztalyok szabadon atnevezhetok)
#include "arena.h"
#include "actionlist.h"

#define PART1 // Arena beolvasasa JSON-bol
#define PART2 // Arena: print() teszt
#define PART3 // Arena: printAll() teszt
#define PART4 // Arena: performAction() tesztek
#define PART5 // ActionList beolvasas, printSome()
#define PART6 // Arena, ActionList vegrehajtas

int main()
{
    cout << "main() eleje!" << endl << endl;

#ifdef PART1
    cout << "--- Arena beolvasasa JSON-bol" << endl;
    Arena arena1;
    arena1.load("in-arena.json");
    cout << "Megtortent." << endl << endl;
#endif

#ifdef PART2
    cout << "--- Arena: print() teszt" << endl;
    arena1.print("Red_M");
    arena1.print("Red_P");
    arena1.print("Blue_S");
    cout << endl;
#endif

#ifdef PART3
    cout << "--- Arena: printAll() teszt" << endl;
    arena1.printAll();
    cout << endl;
#endif

#ifdef PART4
    cout << "--- Arena: performAction() tesztek" << endl;
    cout << "#00: " << flush;
    arena1.print("Blue_S");
    arena1.performAction("Red_S1","Blue_S");
    cout << "#01: " << flush;
    arena1.print("Blue_S");
    arena1.performAction("Red_M","Blue_S");
    cout << "#02: " << flush;
    arena1.print("Blue_S");
    arena1.performAction("Blue_P","Blue_S");
    cout << "#03: " << flush;
    arena1.print("Blue_S");
    arena1.performAction("Blue_S","Red_S1");
    cout << "#04: " << flush;
    arena1.print("Red_S1");
    arena1.performAction("Blue_S","Red_S2");
    cout << "#05: " << flush;
    arena1.print("Red_S2");
    arena1.performAction("Blue_M","Red_S2");
    cout << "#06: " << flush;
    arena1.print("Red_S2");
    arena1.performAction("Blue_M","Red_S2");
    cout << "#07: " << flush;
    arena1.print("Red_S2");
    arena1.performAction("Blue_M","Red_S2");
    cout << "#08: " << flush;
    arena1.print("Red_S2");
    arena1.performAction("Red_S2","Blue_M");
    cout << "#09: " << flush;
    arena1.print("Blue_M");
    arena1.performAction("Red_S1","Blue_M");
    cout << "#10: " << flush;
    arena1.print("Blue_M");
    arena1.performAction("Red_M","Blue_M");
    cout << "#11: " << flush;
    arena1.print("Blue_M");
    arena1.performAction("Blue_M","Red_M");
    cout << "#12: " << flush;
    arena1.print("Red_M");
    arena1.performAction("Blue_P","Blue_S");
    cout << "#13: " << flush;
    arena1.print("Blue_S");
    arena1.performAction("Red_S1","Blue_P");
    cout << "#14: " << flush;
    arena1.print("Blue_P");
    arena1.performAction("Blue_P","Blue_S");
    cout << "#15: " << flush;
    arena1.print("Blue_S");
    arena1.performAction("Red_P","Red_S1");
    cout << "#16: " << flush;
    arena1.print("Red_S1");
    arena1.performAction("Red_P","Red_S1");
    cout << "#17: " << flush;
    arena1.print("Red_S1");
    arena1.performAction("Red_P","Red_S2");
    cout << "#18: " << flush;
    arena1.print("Red_S2");
    arena1.performAction("Red_P","Red_M");
    cout << "#19: " << flush;
    arena1.print("Red_M");
    arena1.performAction("Blue_S","Red_P");
    cout << "#20: " << flush;
    arena1.print("Red_P");
    arena1.performAction("Blue_S","Red_M");
    cout << "#21: " << flush;
    arena1.print("Red_M");
    arena1.performAction("Red_P","Red_M");
    cout << "#22: " << flush;
    arena1.print("Red_M");
    cout << "*** Vegallapot:" << endl;
    arena1.printAll();
    cout << endl;
#endif

#ifdef PART5
    cout << "--- ActionList beolvasas, printSome()" << endl;
    ActionList actionList("in-actions.txt");
    actionList.printSome();
    cout << endl;
#endif

#ifdef PART6
    cout << "--- Arena, ActionList vegrehajtas" << endl;
    Arena arena2;
    arena2.load("in-arena.json");
    arena2.performList(actionList);
    cout << "*** Vegallapot (megegyezik az elozovel):" << endl;
    arena2.printAll();
    cout << endl;
#endif

    cout << "main() vege!" << endl;
    return 0;
}
