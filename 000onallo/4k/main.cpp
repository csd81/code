#include <iostream>
#include <fstream>
#include "datum.h"
#include "hatarido.h"

// using namespace std;

void datumKiir(const Datum* d)
{
    if (d == nullptr) {
        std::cout << "Nem letezo datum" << std::endl;
    }
    else {
        std::cout << d->getEv() << "." <<
                    d->getHonap() << "." <<
                    d->getNap() << std::endl;
    }
}

void hataridotKiir(const Hatarido &h)
{
    std::cout << h.getNev() << ": " << std::endl;
    std::cout << "  alpha: ";
    datumKiir(h.getAlphaDatum());
    std::cout << "  beta: ";
    datumKiir(h.getBetaDatum());
    std::cout << "  vegso: ";
    datumKiir(h.getVegsoDatum());
}




void setAll(Hatarido& h){
    std::cout << h.getNev() << " beallitasa: ";
    std::cout << "Kerek egy A datumot (ev, honap, nap): ";
    unsigned int ea, ha, na;
    std::cin >> ea >> ha >> na;
    Datum da(ea,ha,na);
    h.setAlphaDatum(da);


    std::cout << "Kerek egy b datumot (ev, honap, nap): ";
    unsigned int eb, hb, nb;
    std::cin >> eb >> hb >> nb;
    Datum db( eb, hb, nb);
    h.setBetaDatum(db);

    std::cout << "Kerek egy v datumot (ev, honap, nap): ";
    unsigned int ev, hv, nv;
    std::cin >> ev >> hv >> nv;
    Datum dv(ev, hv, nv);
    h.setVegsoDatum(dv);
}

int main()
{

    // Létrehozás és név beállítás
    std::cout << "Kerek egy h1 nevet: ";
    std::string nev0;
    getline(std::cin, nev0);
    Hatarido h1(nev0);

    std::cout << "Kerek egy h2 nevet: ";
    std::string nev;
    getline(std::cin, nev); // Teljes sor bekérése
    Hatarido h2(nev);

    std::cout << "eredetei nevek: " << std::endl;
    std::cout << h1.getNev() << std::endl;
    std::cout << h2.getNev() << std::endl;

    h1.setNev("Atallitott nev");
    std::cout << "h1 atallitva" << std::endl;
    std::cout << "mi legyen h2 uj nev?" << std::endl;
    getline(std::cin, nev);
    h2.setNev(nev);



    std::cout << "új nevek: " << std::endl;
    std::cout << h1.getNev() << std::endl;
    std::cout << h2.getNev() << std::endl;

//	// Dátum beállítása
    std::cout << std::endl;

    setAll(h1);
    setAll(h2);
    Hatarido h3("hat3");
    setAll(h3);

   hataridotKiir(h1);
   hataridotKiir(h2);
   hataridotKiir(h3);

//	// Aktuális dátum kezelése
   int e, h, n;
    Datum aktualis = Hatarido::getAktualisDatum();
   std::cout << "Aktualis datum: " << aktualis.getEv() << "." << aktualis.getHonap() << "." << aktualis.getNap() << std::endl;
    std::cout << h1.getNev() << " lejart?" << std::endl;
    h1.lejart();
    std::cout << h2.getNev() << " lejart?" << std::endl;
    h2.lejart();
    std::cout << "Kerem az uj aktualis datumot (ev, honap, nap): ";
    std::cin >> e >> h >> n;
    Hatarido::setAktualisDatum(Datum(e,h,n));
    aktualis = Hatarido::getAktualisDatum();
    std::cout << "Aktualis datum: " << aktualis.getEv() << "." << aktualis.getHonap() << "." << aktualis.getNap() << std::endl;
    std::cout << h1.getNev() << " lejart?" << std::endl;
    h1.lejart();
    std::cout << h2.getNev() << " lejart?" << std::endl;
    h2.lejart();

//	// Dátum átállítása és törlése
    std::cout << std::endl;
    h1.setVegsoDatum(Datum(2000,1,1));
    h1.hataridoTorol("alpha"); // Ezt kitörli
    h1.hataridoTorol("beta"); // Itt nincs dátum tárolva
    h1.hataridoTorol("gamma"); // Ilyen meg nincs is
    hataridotKiir(h1);

//	// Másolat készítése
    std::cout << std::endl;
    Hatarido uj(h1);
    hataridotKiir(h1);
    hataridotKiir(uj);
    uj.setNev("UJ");
    uj.setBetaDatum(Datum(1996,8,9));
    hataridotKiir(h1);
    hataridotKiir(uj);

	return 0;
}
