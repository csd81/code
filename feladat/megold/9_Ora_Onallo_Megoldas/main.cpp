#include <iostream>
#include <string>
#include "kulcsertekpar.h"
#include "asszociativ.h"

using namespace std;

// Segéd függvény a teszteléshez
template <class KulcsTipus, class ErtekTipus>
void AsszocKiir(const Asszociativ<KulcsTipus,ErtekTipus> &asszoc)
{
	for (int i=0; i<asszoc.meret(); i++)
		cout << asszoc.kulcsByIndex(i) << " : " << asszoc.ertekByIndex(i) << endl;
}

int main()
{

	cout << endl << endl << "KulcsErtekPar teszt" << endl;
	KulcsErtekPar<int, double> kp;
	kp.kulcs=1;
	kp.ertek=9.8;
	KulcsErtekPar<int, double> kp2(3,4.6);
	cout << kp.kulcs << " : " << kp.ertek << endl; // 1 : 9.8
	cout << kp2.kulcs << " : " << kp2.ertek << endl; // 3 : 4.6
	KulcsErtekPar<string,char> kp3("alma", 'z');
	cout << kp3.kulcs << " : " << kp3.ertek << endl; // alma : z

	cout << endl << endl << "Asszociativ teszt: konstruktor, meret" << endl;
	Asszociativ<int,double> asszoc1;
	Asszociativ<string, int> asszoc2;
	cout << asszoc1.meret() << endl; // 0
	cout << asszoc2.meret() << endl; // 0

	cout << endl << endl << "Asszociativ teszt: beallit, kulcsByIndex, ertekByIndex" << endl;
	asszoc1.beallit(1, 32.65);
	asszoc1.beallit(7, 2.32);
	asszoc1.beallit(6, -786.6);
	asszoc1.beallit(9, 0);
	asszoc1.beallit(3, 123.565);
	asszoc2.beallit("valami kulcs", 43);
	asszoc2.beallit("ezaz", 12);
	asszoc2.beallit("May the force be with you", 1);
	asszoc2.beallit("The answer", 42);
	cout << "asszoc1:" << endl;
	AsszocKiir(asszoc1);
	cout << "asszoc2:" << endl;
	AsszocKiir(asszoc2);
	//asszoc1:
	//1 : 32.65
	//7 : 2.32
	//6 : -786.6
	//9 : 0
	//3 : 123.565
	//asszoc2:
	//valami kulcs : 43
	//ezaz : 12
	//May the force be with you : 1
	//The answer : 42
	asszoc1.beallit(7, 123.5); // létező kulcs, átállít
	asszoc1.beallit(9, -213.444); // létező kulcs, átállít
	asszoc1.beallit(65, 111.111);
	asszoc2.beallit("ezaz", 987); // létező kulcs, átállít
	asszoc2.beallit("hurra", 11111);
	cout << endl << "Ujra:" << endl;
	cout << "asszoc1:" << endl;
	AsszocKiir(asszoc1);
	cout << "asszoc2:" << endl;
	AsszocKiir(asszoc2);
	//Ujra:
	//asszoc1:
	//1 : 32.65
	//7 : 123.5
	//6 : -786.6
	//9 : -213.444
	//3 : 123.565
	//65 : 111.111
	//asszoc2:
	//valami kulcs : 43
	//ezaz : 987
	//May the force be with you : 1
	//The answer : 42
	//hurra : 11111

	cout << endl << endl << "Asszociativ teszt: vane" << endl;
	cout << "asszoc1:" << endl;
	cout << asszoc1.vane(3) << endl; // 1
	cout << asszoc1.vane(7) << endl; // 1
	cout << asszoc1.vane(8) << endl; // 0
	cout << asszoc1.vane(12) << endl; // 0
	cout << asszoc1.vane(0) << endl; // 0
	cout << "asszoc2:" << endl;
	cout << asszoc2.vane("valami") << endl; // 0
	cout << asszoc2.vane("valami kulcs") << endl; // 1
	cout << asszoc2.vane("hurra") << endl; // 1
	cout << asszoc2.vane("The answer") << endl; // 1
	cout << asszoc2.vane("the answer") << endl; // 0

	cout << endl << endl << "Asszociativ teszt: ertek" << endl;
	cout << "asszoc1:" << endl;
	cout << asszoc1.ertek(3) << endl; // 123.565
	cout << asszoc1.ertek(7) << endl; // 123.5
	cout << asszoc1.ertek(8) << endl; // 0
	cout << asszoc1.ertek(12) << endl; // 0
	cout << asszoc1.ertek(0) << endl; // 0
	cout << "asszoc2:" << endl;
	cout << asszoc2.ertek("valami") << endl; // 0
	cout << asszoc2.ertek("valami kulcs") << endl; // 43
	cout << asszoc2.ertek("hurra") << endl; // 11111
	cout << asszoc2.ertek("The answer") << endl; // 42
	cout << asszoc2.ertek("the answer") << endl; // 0

	cout << endl << endl << "Asszociativ teszt: ertekVagyDefault" << endl;
	cout << "asszoc1:" << endl;
	cout << asszoc1.ertekVagyDefault(3,-12.34) << endl; // 123.565
	cout << asszoc1.ertekVagyDefault(7,-12.34) << endl; // 123.5
	cout << asszoc1.ertekVagyDefault(8,-12.34) << endl; // -12.34
	cout << asszoc1.ertekVagyDefault(12,-12.34) << endl; // -12.34
	cout << asszoc1.ertekVagyDefault(0,-12.34) << endl; // -12.34
	cout << "asszoc2:" << endl;
	cout << asszoc2.ertekVagyDefault("valami",-1) << endl; // -1
	cout << asszoc2.ertekVagyDefault("valami kulcs",-1) << endl; // 43
	cout << asszoc2.ertekVagyDefault("hurra",-1) << endl; // 11111
	cout << asszoc2.ertekVagyDefault("The answer",-1) << endl; // 42
	cout << asszoc2.ertekVagyDefault("the answer",-1) << endl; // -1

	cout << endl << endl << "Asszociativ teszt: torol" << endl;
	asszoc1.torol(3);
	asszoc1.torol(7);
	asszoc1.torol(987); // ilyen nincs
	asszoc2.torol("valami kulcs");
	asszoc2.torol("valami"); // ilyen nincs
	asszoc2.torol("hurra");
	cout << "asszoc1:" << endl;
	AsszocKiir(asszoc1);
	cout << "asszoc2:" << endl;
	AsszocKiir(asszoc2);
	//asszoc1:
	//1 : 32.65
	//6 : -786.6
	//9 : -213.444
	//65 : 111.111
	//asszoc2:
	//ezaz : 987
	//May the force be with you : 1
	//The answer : 42

	cout << endl << endl << "Asszociativ teszt: operator []" << endl;
	cout << "asszoc1:" << endl;
	cout << asszoc1[65] << endl; // 111.111
	asszoc1[65]=22.22;
	cout << asszoc1[65] << endl; // 22.22
	cout << asszoc1[12] << endl; // 0
	asszoc1[13]=89.89;
	cout << asszoc1[13] << endl; // 89.89
	cout << "asszoc2:" << endl;
	cout << asszoc2["ezaz"] << endl; // 987
	asszoc2["ezaz"]=1000;
	cout << asszoc2["ezaz"] << endl; // 1000
	cout << asszoc2["nincs ilyen"] << endl; // 0
	asszoc2["mostmar van"]=-432;
	cout << asszoc2["mostmar van"] << endl; // -432
	cout << "Tartalom:" << endl;
	cout << "asszoc1:" << endl;
	AsszocKiir(asszoc1);
	cout << "asszoc2:" << endl;
	AsszocKiir(asszoc2);
	//Tartalom:
	//asszoc1:
	//1 : 32.65
	//6 : -786.6
	//9 : -213.444
	//65 : 22.22
	//12 : 0
	//13 : 89.89
	//asszoc2:
	//ezaz : 1000
	//May the force be with you : 1
	//The answer : 42
	//nincs ilyen : 0
	//mostmar van : -432


	return 0;
}
