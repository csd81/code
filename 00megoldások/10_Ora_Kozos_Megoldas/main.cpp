#include <iostream>
#include "helyszin.h"

using namespace std;

int main()
{

	cout << endl << endl << "Helyszin::betolt() teszt" << endl;
	Helyszin h;
	h.betolt("kozpont.json");  // JSON fájl beolvasása


	cout << endl << endl << "Helyszin::kiir() teszt" << endl;
	h.kiir(); // Kiírás standard kimenetre

//	Helyszin: Varosi rendezveny kozpont (3214, Valami Varos, xy utca 10)
//	Esemenyek:
//	  szinhazi eloadas: 2023.06.20. 19:00 - 22:00 (140 fo)
//	  unnepi vacsora: 2023.05.19. 20:00 - 23:00 (80 fo)
//	  szerepjatek est: 2023.07.28. 16:00 - 23:00 (25 fo)
//	  festeszeti kiallitas: 2023.05.30. 8:00 - 19:00 (583 fo)
//	  virag vasar: 2023.06.03. 10:00 - 20:00 (319 fo)
//	  zenei est: 2023.06.11. 18:00 - 23:00 (89 fo)

	cout << endl << endl << "Helyszin::esemenyHosszKiir() teszt" << endl;
	h.esemenyHosszKiir("kimenet.json"); // JSON fájlba mentés: esemény hosszak
	// kimenet.json tartalma:
//	[
//		{
//			"esemeny": "szinhazi eloadas",
//			"hossz": 3
//		},
//		{
//			"esemeny": "unnepi vacsora",
//			"hossz": 3
//		},
//		{
//			"esemeny": "szerepjatek est",
//			"hossz": 7
//		},
//		{
//			"esemeny": "festeszeti kiallitas",
//			"hossz": 11
//		},
//		{
//			"esemeny": "virag vasar",
//			"hossz": 10
//		},
//		{
//			"esemeny": "zenei est",
//			"hossz": 5
//		}
//	]


	cout << endl << endl << "Vege" << endl;
	return 0;
}
