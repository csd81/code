#include <iostream>
#include <type_traits>
#include <fstream>
using namespace std;

// A feladatokhoz #define direktivak kellenek, lasd: megoldott_feladatok.h
// A megoldott_feladatok.h fajlt is be kell adni!

#include "megoldott_feladatok.h"

#ifdef PART1
#include "chessboard.h"
#endif

#ifdef PART2
#include "rectangle.h"
#endif

#ifdef PART3
#include "inverse.h"
#endif

#ifdef PART4
#include "stars.h"
#endif

#include "image.h"
#include "example.h"

struct TesterGuard
{
	string partname;
	TesterGuard (const string& partname);
	~TesterGuard();
};

namespace ToolsForRating {}
using namespace ToolsForRating;

int main()
{
    cout << "main() eleje!" << endl;

    {
        cout << "Example1 teszt:" << endl;
        Example1 example1;
        Image& img = example1;
        img.print();
    }
    {
        cout << "Example2 teszt:" << endl;
        Example2 example2;
        Image& img = example2;
        img.print();
    }

#ifdef PART1
	{
        TesterGuard tguard("PART1");
        if (!is_base_of<Image,Chessboard>::value)
            cout << "Hiba: Chessboard nem az Image-bol szarmazik!" << endl;
        Chessboard chb;
        Image& img = chb;
        img.print();
	}//
#endif

#ifdef PART2
    {
        TesterGuard tguard("PART2");
        if (!is_base_of<Image,Rectangle>::value)
            cout << "Hiba: Rectangle nem az Image-bol szarmazik!" << endl;
        Rectangle r1(10,9,1,2,5,7);
        Rectangle r2(12,5,2,1,10,2);
        Image& img1 = r1;
        Image& img2 = r2;
        img1.print();
        img2.print();
    }//
#endif

#ifdef PART3
    {
        TesterGuard tguard("PART3");
        if (!is_base_of<Image,Inverse>::value)
            cout << "Hiba: Inverse nem az Image-bol szarmazik!" << endl;
        Example1 e1;
        Example2 e2;
        Inverse inv1(&e1);
        Inverse inv2(&e2);
        Inverse inv3(&inv2);
        inv1.print();
        inv2.print();
        inv3.print();
    }//
#endif

#ifdef PART4
    {
        TesterGuard tguard("PART4");
        if (!is_base_of<Image,Stars>::value)
            cout << "Hiba: Stars nem az Image-bol szarmazik!" << endl;
        Stars stars1(10,5);
        stars1.addStar(2,3);
        stars1.addStar(4,2);
        Stars stars2(11,6);
        stars2.addStar(1,1);
        stars2.addStar(3,4);
        stars2.addStar(5,2);
        stars2.addStar(7,4);
        stars2.addStar(9,1);
        stars1.print();
        stars2.print();
    }//
#endif

#ifdef PART5
    {
        TesterGuard tguard("PART5");
        Example1 e1;
        e1.saveToFile("example1.txt");
        Example2 e2;
        e2.saveToFile("example2.txt");
        for (const char* path : {"example1.txt","example2.txt"})
        {
            cout << path << " tartalma:" << endl;
            ifstream in(path);
            if (in.is_open())
                cout << in.rdbuf() << endl;
            else
                cout << "Hiba: nem sikerult megnyitni!" << endl;
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
