#include <iostream>
#include <fstream>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "itemcounter.h"
#endif

#ifdef PART2
#include "itemcounter.h"
#endif

#ifdef PART3
#include "itemcounter.h"
#endif

#ifdef PART4
#include "itemcounter.h"
#include "extra.h"
#endif

struct TesterGuard
{
	string partname;
	TesterGuard (const string& partname);
	~TesterGuard();
};

int main()
{
    cout << "main() eleje!" << endl;

#ifdef PART1
	{
        TesterGuard tguard("PART1");
        ItemCounter<int> ic1;
        ItemCounter<string> ic2;
        ic1.addItem(4);
        ic1.addItem(4);
        ic1.addItem(4);
        ic1.addItem(6);
        ic1.addItem(6);
        ic2.addItem("four");
        ic2.addItem("four");
        ic2.addItem("four");
        ic2.addItem("six");
        ic2.addItem("six");
        cout << "ic1 teszt:" << endl;
        cout << ic1.getIndexOfItem(4) << " "; // 0
        cout << ic1.getIndexOfItem(5) << " "; // -1
        cout << ic1.getIndexOfItem(6) << endl; // 1
        cout << ic1.getCounter(4) << " "; // 3
        cout << ic1.getCounter(5) << " "; // 0
        cout << ic1.getCounter(6) << endl; // 2
        cout << "ic2 teszt:" << endl;
        cout << ic2.getIndexOfItem("four") << " "; // 0
        cout << ic2.getIndexOfItem("five") << " "; // -1
        cout << ic2.getIndexOfItem("six") << endl; // 1
        cout << ic1.getCounter(4) << " "; // 3
        cout << ic1.getCounter(5) << " "; // 0
        cout << ic1.getCounter(6) << endl; // 2
	}//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        ItemCounter<double> ic3;
        ic3[3.14] = 100;
        ic3.addItem(3.14);
        ic3[2.71] = 2000;
        cout << "Kiiras:" << endl;
        cout << ic3[3.14] << endl; // 1001
        cout << ic3[2.71] << endl; // 2000
        cout << ic3[0.6666] << endl; // 0
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        ItemCounter<double> ic1;
        ItemCounter<string> ic2;
        ic1.addItem(7.1);
        ic1.addItem(7.1);
        ic1.addItem(7.1);
        ic1.addItem(9.29);
        ic1.addItem(9.29);
        for (int i=0;i<42;i++)
            ic2.addItem("Alpha");
        for (int i=0;i<13;i++)
            ic2.addItem("Beta");
        for (int i=0;i<65;i++)
            ic2.addItem("Gamma");
        cout << "ic1 kiirasa:" << endl << ic1 << endl;
        cout << "ic2 kiirasa:" << endl << ic2 << endl;
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        {
            ofstream out("pelda1.txt");
            out << "egy meggymag" << endl;
            out << "meg meg egy meggymag" << endl;
        }
        {
            ofstream out("pelda2.txt");
            out << "lenin mauzoleumanak lelinoleumozasa" << endl;
        }
        {
            ItemCounter<char> ic = getCharFrequency("pelda1.txt");
            cout << "pelda1.txt teszt:" << endl;
            cout << 'm' << " -> " << ic.getCounter('m') << endl; // 6
            cout << 'g' << " -> " << ic.getCounter('g') << endl; // 10
            cout << 'e' << " -> " << ic.getCounter('e') << endl; // 6
        }
        {
            ItemCounter<char> ic = getCharFrequency("pelda2.txt");
            cout << "pelda2.txt teszt:" << endl;
            cout << 'l' << " -> " << ic.getCounter('l') << endl; // 5
            cout << 'e' << " -> " << ic.getCounter('e') << endl; // 4
            cout << 'h' << " -> " << ic.getCounter('h') << endl; // 0
        }
    }//
#endif

	cout << "main() vege!" << endl;
	return 0;
}

TesterGuard::TesterGuard(const string &p):
	partname(p)
{
	cout << endl << "----START OF " << partname << "----" << endl << endl;
}

TesterGuard::~TesterGuard()
{
	cout << endl << "----END OF " << partname << "----" << endl << endl;
}
