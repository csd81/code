#include <iostream>
#include "bevitelimezo.h"
#include "szovegmezo.h"
#include "szammezo.h"
#include "adatbekero.h"

using namespace std;

int main()
{

	// SzovegMezo teszt: konstruktor, getterek, setterek
	cout << endl << endl << "SzovegMezo teszt: konstruktor, getterek, setterek" << endl;
    SzovegMezo szoveg1("nev", true, 15);
    cout << szoveg1.getMegnevezes() << " " << szoveg1.getSzerkesztheto() << endl; // nev 1
    cout << szoveg1.getMaxhossz() << " \"" << szoveg1.getSzoveg() << "\"" << endl; // 15 ""
    szoveg1.setSzoveg("alma");
    szoveg1.setSzerkesztheto(false);
    cout << szoveg1.getMegnevezes() << " " << szoveg1.getSzerkesztheto() << endl; // nev 0
    cout << szoveg1.getMaxhossz() << " \"" << szoveg1.getSzoveg() << "\"" << endl; // 15 "alma"

	// SzovegMezo teszt: setSzoveg szerkesztheto
	cout << endl << endl << "SzovegMezo teszt: setSzoveg szerkesztheto" << endl;
    szoveg1.setSzerkesztheto(false);
    szoveg1.setSzoveg("korte");
    cout << szoveg1.getMaxhossz() << " \"" << szoveg1.getSzoveg() << "\"" << endl; // 15 "alma"
    szoveg1.setSzerkesztheto(true);
    szoveg1.setSzoveg("korte");
    cout << szoveg1.getMaxhossz() << " \"" << szoveg1.getSzoveg() << "\"" << endl; // 15 "korte"

	// SzovegMezo teszt: megfelelo
	cout << endl << endl << "SzovegMezo teszt: megfelelo" << endl;
    szoveg1.setSzerkesztheto(true);
    cout << szoveg1.megfelelo() << endl; // 1
    szoveg1.setSzoveg("jooooooo hosszu szoveg");
    cout << szoveg1.megfelelo() << endl; // 0

	// SzovegMezo teszt: operator ~
	cout << endl << endl << "SzovegMezo teszt: operator ~" << endl;
    szoveg1.setSzoveg("ez a szoveg");
    cout << (~szoveg1) << endl; // "ez a szoveg"

	// SzamMezo teszt: konstruktor, getterek, setterek
	cout << endl << endl << "SzamMezo teszt: konstruktor, getterek, setterek" << endl;
    SzamMezo szam1("szam", true);
    cout << szam1.getMegnevezes() << " " << szam1.getSzerkesztheto() << " " << szam1.getErtek() << endl; // szam 1 0
    szam1.setErtek(60);
    szam1.setSzerkesztheto(false);
    cout << szam1.getMegnevezes() << " " << szam1.getSzerkesztheto() << " " << szam1.getErtek() << endl; // szam 0 60

	// SzamMezo teszt: setErtek szerkesztheto
	cout << endl << endl << "SzamMezo teszt: setErtek szerkesztheto" << endl;
    szam1.setSzerkesztheto(false);
    szam1.setErtek(80);
    cout << szam1.getMegnevezes() << " " << szam1.getSzerkesztheto() << " " << szam1.getErtek() << endl; // szam 0 60
    szam1.setSzerkesztheto(true);
    szam1.setErtek(15);
    cout << szam1.getMegnevezes() << " " << szam1.getSzerkesztheto() << " " << szam1.getErtek() << endl; // szam 1 15

	// SzamMezo teszt: megfelelo
	cout << endl << endl << "SzamMezo teszt: megfelelo" << endl;
    szam1.setSzerkesztheto(true);
    cout << szam1.megfelelo() << endl; // 1
    szam1.setErtek(160);
    cout << szam1.megfelelo() << endl; // 0

	// SzamMezo teszt: operator =
	cout << endl << endl << "SzamMezo teszt: operator =" << endl;
    szam1=45;
    cout << szam1.getMegnevezes() << " " << szam1.getSzerkesztheto() << " " << szam1.getErtek() << endl; // szam 1 45
    szam1.setSzerkesztheto(false);
    szam1=78;
    cout << szam1.getMegnevezes() << " " << szam1.getSzerkesztheto() << " " << szam1.getErtek() << endl; // szam 0 78

	// SzamMezo teszt: maxertek, megfelelo
	cout << endl << endl << "SzamMezo teszt: maxertek, megfelelo" << endl;
    cout << SzamMezo::getMaxertek() << endl; // 100
    cout << szam1.megfelelo() << endl; // 1
    SzamMezo::setMaxertek(50);
    cout << SzamMezo::getMaxertek() << endl; // 50
    cout << szam1.megfelelo() << endl; // 0

	// AdatBekero teszt: konstruktor, getDarab
	cout << endl << endl << "AdatBekero teszt: konstruktor, getDarab" << endl;
    AdatBekero adatb;
    cout << adatb.getDarab() << endl; // 0

	// AdatBekero teszt: operator +=
	cout << endl << endl << "AdatBekero teszt: operator +=" << endl;
    {
        SzovegMezo *szoveg=new SzovegMezo("szoveg1", true, 20);
        szoveg->setSzoveg("valami");
        adatb += szoveg;
    }
    {
        SzamMezo *szam=new SzamMezo("szam1", true);
        szam->setErtek(230);
        adatb += szam;
    }
    adatb += new SzovegMezo("szoveg2", false, 3);
    adatb += new SzamMezo("szam2", false);
    {
        SzovegMezo *szoveg=new SzovegMezo("szoveg3", true, 6);
        szoveg->setSzoveg("soooooooooooooook");
        adatb += szoveg;
    }
    {
        SzamMezo *szam=new SzamMezo("szam3", true);
        szam->setErtek(34);
        adatb += szam;
    }
    cout << adatb.getDarab() << endl; // 6

	// AdatBekero teszt: operator <<
    cout << endl << endl << "AdatBekero teszt: operator <<" << endl;
    cout << adatb << endl;
	// Megnevezes: szoveg1, megfelelo-e: 1, az ertek: valami
	// Megnevezes: szam1, megfelelo-e: 0, az ertek: 230
	// Megnevezes: szoveg2, megfelelo-e: 1, az ertek:
	// Megnevezes: szam2, megfelelo-e: 1, az ertek: 0
	// Megnevezes: szoveg3, megfelelo-e: 0, az ertek: soooooooooooooook
	// Megnevezes: szam3, megfelelo-e: 1, az ertek: 34

	// AdatBekero teszt: operator []
	cout << endl << endl << "AdatBekero teszt: operator []" << endl;
    cout << adatb[0] << endl; // 1
    cout << adatb[1] << endl; // 0
    cout << adatb[4] << endl; // 0
    cout << adatb[5] << endl; // 1
    cout << adatb[19] << endl; // 0
    cout << adatb[1231] << endl; // 0





	cout << endl << endl << endl << "VEGE" << endl << endl;

	return 0;
}
