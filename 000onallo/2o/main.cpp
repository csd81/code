
#include <iostream>
#include "Tarolo.h"


	int kisebbTarolo(const Tarolo& t1, const Tarolo& t2){
		if (t1.darabLeker() > t2.darabLeker()){
			return 1;
		}
		else if (t1.darabLeker() < t2.darabLeker()){
			return -1;
		}
		else return 0;
	}


using namespace EpicToolbox;
int main(){
	Tarolo t1;
	t1.kiir();
	Tarolo t2(5);
	t2.kiir();
	Tarolo t3(10);
	t3.kiir();

	int melyik = kisebbTarolo(t2, t3);
	if (melyik == 1) {
		std::cout << "t2 nagyobb" << std::endl;
	} else if (melyik == -1) {
		std::cout << "t3 nagyobb" << std::endl;
	} else {
		std::cout << "ugyanakkorák" << std::endl;
	}


std::cout << "t1 tartománya: " << t1.tartomany()<< std::endl;

	std::cout << "t1 rendezés növekvő: ";
	 t1.rendez(true);
	t1.kiir();

	std::cout << "t1 rendezés csökkenő: ";
	t1.rendez(false);
	t1.kiir();

	std::cout << "t1 hozzafuz t2: ";
	t1.hozzafuz(t2);
	t1.kiir();
    return 0;
}