#include <iostream>
#include "karakter.h"
#include "harcos.h"
#include "ijasz.h"
#include "magus.h"
#include "szerver.h"

using namespace std;

// Ez is kell a teszteléshez
class T1 : public Karakter
{
    int a;
public:
    T1(int _a):Karakter("T1", 2),a(_a){}
    int eletero() const override {return a;};
    int sebzes() const override {return a;};
    void kiir() const override {cout << "T1" << endl;};
};

int main()
{

	cout << endl << endl << "main eleje" << endl;

    cout << endl << endl << "Karakter teszt" << endl;
    {
        cout << "Karakter destruktora virtualis? " << (has_virtual_destructor<Karakter>::value?"IGEN":"NEM") << endl;
        Karakter *k1 = new T1(5);
        cout << k1->getNev() << " " << k1->getSzint() << endl;
        cout << k1->eletero() << " " << k1->sebzes() << endl;
        k1->kiir();
        delete k1;
//		Karakter destruktora virtualis? IGEN
//		T1 2
//		5 5
//		T1
    }

    cout << endl << endl << "Harcos teszt" << endl;
    {
        Karakter *k1 = new Harcos("harcos1", 14, "kard");
        cout << k1->getNev() << " " << k1->getSzint() << endl;
        // eletero: 12 az alap + szintenként 4 (14*6) = 96
        // sebzes: 5 az alap + szintenként 2 (14*2) = 33
        cout << k1->eletero() << " " << k1->sebzes() << endl;
        k1->kiir();
        delete k1;
//		harcos1 14
//		96 33
//		harcos1: 14. szintu harcos, fegyver: kard

        Karakter *k2 = new Harcos("harcos2", 25, "landzsa");
        cout << k2->getNev() << " " << k2->getSzint() << endl;
        // eletero: 12 az alap + szintenként 4 (25*6) = 162
        // sebzes: 5 az alap + szintenként 2 (25*2) = 55
        cout << k2->eletero() << " " << k2->sebzes() << endl;
        k2->kiir();
        delete k2;
//		harcos2 25
//		162 55
//		harcos2: 25. szintu harcos, fegyver: landzsa
    }

    cout << endl << endl << "Ijasz teszt" << endl;
    {
        Karakter *k1 = new Ijasz("ijasz1", 5, 76);
        cout << k1->getNev() << " " << k1->getSzint() << endl;
        // eletero: 10 az alap + szintenként 3 (5*3) = 25
        // sebzes: 3 az alap + szintenként 2 (5*2) = 13, és mivel a pontosság < 90, ezért ez a vége
        cout << k1->eletero() << " " << k1->sebzes() << endl;
        k1->kiir();
        delete k1;
//		ijasz1 5
//		25 13
//		ijasz1: 5. szintu ijasz, pontossag: 76

        Karakter *k2 = new Ijasz("ijasz2", 24, 92);
        cout << k2->getNev() << " " << k2->getSzint() << endl;
        // eletero: 10 az alap + szintenként 3 (24*3) = 82
        // sebzes: 3 az alap + szintenként 2 (24*2) = 51, és mivel a pontosság >= 90, ezért *2 = 102
        cout << k2->eletero() << " " << k2->sebzes() << endl;
        k2->kiir();
        delete k2;
//		ijasz2 24
//		82 102
//		ijasz2: 24. szintu ijasz, pontossag: 92
    }

    cout << endl << endl << "Magus teszt" << endl;
    {
        Karakter *k1 = new Magus("magus1", 31, 56);
        cout << k1->getNev() << " " << k1->getSzint() << endl;
        // eletero: 8 az alap + szintenként 3 (31*3) + minden 5. manáért még 1 (56/5) = 112
        // sebzes: 4 az alap + szintenként 2 (31*2) + minden 10. manáért még 3 (56/10)*3 = 81
        cout << k1->eletero() << " " << k1->sebzes() << endl;
        k1->kiir();
        delete k1;
//		magus1 31
//		112 81
//		magus1: 31. szintu magus, mana: 56

        Karakter *k2 = new Magus("magus2", 41, 97);
        cout << k2->getNev() << " " << k2->getSzint() << endl;
        // eletero: 8 az alap + szintenként 3 (41*3) + minden 5. manáért még 1 (97/5) = 150
        // sebzes: 4 az alap + szintenként 2 (41*2) + minden 10. manáért még 3 (97/10)*3 = 113
        cout << k2->eletero() << " " << k2->sebzes() << endl;
        k2->kiir();
        delete k2;
//		magus2 41
//		150 113
//		magus2: 41. szintu magus, mana: 97
    }

    {
        cout << endl << endl << "Szerver teszt: betolt(), listaz()" << endl;
        Szerver sz;
        sz.betolt();
        sz.listaz();
//		OsMagus12: 8. szintu magus, mana: 45
//		RobinHood42: 8. szintu ijasz, pontossag: 84
//		Szoke_herceg: 2. szintu harcos, fegyver: kard
//		Harry_Potter: 5. szintu magus, mana: 25
//		Lone_Unsullied: 12. szintu harcos, fegyver: landzsa
//		Gandalf25: 19. szintu magus, mana: 59
//		MrLegolas: 15. szintu ijasz, pontossag: 95
//		TracThor: 17. szintu harcos, fegyver: kalapacs
//		This_Is_Sparta: 9. szintu harcos, fegyver: landzsa

        cout << endl << endl << "Szerver::legtobbElet() teszt" << endl;
        Karakter *legtobbEletes = sz.legtobbElet();
        cout << legtobbEletes->getNev() << " : " << legtobbEletes->eletero() << endl;
//		TracThor : 114

        cout << endl << endl << "Szerver::csata() teszt" << endl;
        cout << "RobinHood42  vs  Gandalf25 : " << sz.csata("RobinHood42", "Gandalf25") << endl;
        cout << "This_Is_Sparta  vs  MrLegolas : " << sz.csata("This_Is_Sparta", "MrLegolas") << endl;
        cout << "MrLegolas  vs  Gandalf25 : " << sz.csata("MrLegolas", "Gandalf25") << endl;
        cout << "Lone_Unsullied  vs  TracThor : " << sz.csata("Lone_Unsullied", "TracThor") << endl;
        cout << "TracThor  vs  Gandalf25 : " << sz.csata("TracThor", "Gandalf25") << endl;
        cout << "Szoke_herceg  vs  Harry_Potter : " << sz.csata("Szoke_herceg", "Harry_Potter") << endl;
        cout << "Gandalf25  vs  OsMagus12 : " << sz.csata("Gandalf25", "OsMagus12") << endl;
        cout << "This_Is_Sparta  vs  RobinHood42 : " << sz.csata("This_Is_Sparta", "RobinHood42") << endl;
        cout << "RobinHood42  vs  TracThor : " << sz.csata("RobinHood42", "TracThor") << endl;
        cout << "MrLegolas  vs  TracThor : " << sz.csata("MrLegolas", "TracThor") << endl;
        cout << "Harry_Potter  vs  Lone_Unsullied : " << sz.csata("Harry_Potter", "Lone_Unsullied") << endl;
        cout << "OsMagus12  vs  RobinHood42 : " << sz.csata("OsMagus12", "RobinHood42") << endl;
//		RobinHood42  vs  Gandalf25 : Gandalf25
//		This_Is_Sparta  vs  MrLegolas : MrLegolas
//		MrLegolas  vs  Gandalf25 : Gandalf25
//		Lone_Unsullied  vs  TracThor : TracThor
//		TracThor  vs  Gandalf25 : X
//		Szoke_herceg  vs  Harry_Potter : Harry_Potter
//		Gandalf25  vs  OsMagus12 : Gandalf25
//		This_Is_Sparta  vs  RobinHood42 : This_Is_Sparta
//		RobinHood42  vs  TracThor : TracThor
//		MrLegolas  vs  TracThor : X
//		Harry_Potter  vs  Lone_Unsullied : Lone_Unsullied
//		OsMagus12  vs  RobinHood42 : OsMagus12

        cout << endl << endl << "Szerver::tornaSzimulacio() teszt" << endl;
        sz.tornaSzimulacio();
        // eredmenyek.txt tartalma:
//		This_Is_Sparta TracThor 2
//		Lone_Unsullied RobinHood42 1
//		Gandalf25 Harry_Potter 1
//		Szoke_herceg MrLegolas 2
//		Harry_Potter Lone_Unsullied 2
//		TracThor MrLegolas 0
//		OsMagus12 Gandalf25 2
//		This_Is_Sparta Szoke_herceg 1
//		Gandalf25 TracThor 0
//		RobinHood42 OsMagus12 2

    }


	cout << endl << endl << "main vege" << endl;
	return 0;
}
