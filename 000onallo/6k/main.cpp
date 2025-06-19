#include <iostream>
#include "jarmu.h"
#include "tarolo.h"
#include "repulo.h"
#include "hajo.h"

// using namespace std;

void jarmuKiirSima(const Jarmu& j)
{
    j.kiir();
}

void jarmuKiirVirtualis(const Jarmu &j)
{
    j.kiir();
}

int main()
{
	// Jarmu osztály teszt
    std::cout << std::endl;
    std::cout << "Jarmu teszt" << std::endl;
    Hajo j1(5,6,4);
    j1.kiir();

	// Tarolo osztály teszt
    std::cout << std::endl;
    std::cout << "Tarolo teszt" << std::endl;
	Tarolo t1;
	t1.megjelenit();
     t1.beallit(2,new Hajo(3,7,1));
     t1.beallit(4,new Repulo(8,1,32));
	t1.megjelenit();
     t1.beallit(6,new Repulo(0,1,2));
     t1.beallit(2,new Hajo(1,3,9));
	t1.megjelenit();

    // Repulo és Hajo teszt
    std::cout << std::endl;
    std::cout << "Repulo es Hajo teszt" << std::endl;
    Repulo r1(12,13,14);
    Hajo h1(65,54,43);
    r1.kiir();
    h1.kiir();
    t1.beallit(0, new Hajo(32,33,34));
    t1.beallit(1, new Repulo(76,86,96));
    t1.megjelenit();

    // virtuális kiir függvény teszt
    std::cout << std::endl;
    std::cout << "virtualis kiir teszt" << std::endl;
    jarmuKiirSima(h1);
    jarmuKiirSima(r1);
    jarmuKiirVirtualis(h1);
    jarmuKiirVirtualis(r1);

    // Tarolo osztály másoló konstruktor teszt
    std::cout << std::endl;
    std::cout << "Tarolo masolo konstruktor teszt" << std::endl;
    Tarolo t2(t1);
    t2.megjelenit();
    t2.beallit(4, new Hajo(4,3,2));
    t2.megjelenit();
	return 0;
}
