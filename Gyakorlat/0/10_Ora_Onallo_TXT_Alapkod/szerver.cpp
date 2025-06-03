#include "szerver.h"

using namespace std;
void Szerver::betolt() {
    std::ifstream file("karakterek.txt");
    if (!file.is_open()) {
        std::cerr << "Hiba a karakterek.txt fajl megnyitasa soran!" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line == "*") break; // A bemenet vége

        std::istringstream iss(line);
        std::string nev, kaszt;
        int szint;
        iss >> nev >> kaszt >> szint;

        if (kaszt == "harcos") {
            std::string fegyver;
            iss >> fegyver;
            karakterek.push_back(new Harcos(nev, szint, fegyver));
        } else if (kaszt == "ijasz") {
            int pontossag;
            iss >> pontossag;
            karakterek.push_back(new Ijasz(nev, szint, pontossag));
        } else if (kaszt == "magus") {
            int mana;
            iss >> mana;
            karakterek.push_back(new Magus(nev, szint, mana));
        }
    }
    file.close();
    std::cout << "Karakterek betoltve a szerverre." << std::endl;
}

// A Szerver osztálynak legyen egy listaz metódusa, amely kilistázza a játékosokat (a Karakter osztály kiir metódusát felhasználva).

void Szerver::listaz() const {
    if (karakterek.empty()) {
        std::cout << "Nincsenek karakterek a szerveren." << std::endl;
        return;
    }

    std::cout << "Jatekosok listaja:" << std::endl;
    for (const auto& karakter : karakterek) {
        karakter->kiir();
    }
}
// A Szerver osztálynak legyen egy legtobbElet metódusa, amely visszaadja a legtöbb élettel rendelkező karaktert.
Karakter* Szerver::legtobbElet() const {
    if (karakterek.empty()) {
        std::cout << "Nincsenek karakterek a szerveren." << std::endl;
        return nullptr;
    }

    Karakter* maxKarakter = karakterek[0];
    for (const auto& karakter : karakterek) {
        if (karakter->getElet() > maxKarakter->getElet()) {
            maxKarakter = karakter;
        }
    }
    return maxKarakter;
}
// A Szerver osztálynak legyen egy csata metódusa, amely két karakter nevét várja, és szimulálja a köztük lévő csatát.
std::string Szerver::csata(const std::string& nev1, const std::string& nev2) const {
    Karakter* karakter1 = nullptr;
    Karakter* karakter2 = nullptr;

    for (const auto& karakter : karakterek) {
        if (karakter->getNev() == nev1) {
            karakter1 = karakter;
        } else if (karakter->getNev() == nev2) {
            karakter2 = karakter;
        }
    }

    if (!karakter1 || !karakter2) {
        return "Hiba: Egyik vagy mindkét karakter nem található.";
    }

    // Egyszerű csata logika
    while (karakter1->getElet() > 0 && karakter2->getElet() > 0) {
        karakter1->tamad(karakter2);
        if (karakter2->getElet() <= 0) {
            return nev1 + " nyert!";
        }
        karakter2->tamad(karakter1);
        if (karakter1->getElet() <= 0) {
            return nev2 + " nyert!";
        }
    }
    return "Csata vege.";
}
// A Szerver osztálynak legyen egy tornaSzimulacio metódusa, amely szimulálja a karakterek közötti tornát.
void Szerver::tornaSzimulacio() const {
    if (karakterek.size() < 2) {
        std::cout << "Nem eleg karakter a tornahoz." << std::endl;
        return;
    }

    std::cout << "Torna szimulacio kezdodik:" << std::endl;
    for (size_t i = 0; i < karakterek.size(); ++i) {
        for (size_t j = i + 1; j < karakterek.size(); ++j) {
            std::string eredmeny = csata(karakterek[i]->getNev(), karakterek[j]->getNev());
            std::cout << eredmeny << std::endl;
        }
    }
}

Szerver::~Szerver() {
    for (auto k : karakterek) {
        delete k; // felszabadítjuk a dinamikusan foglalt memóriát
    }
}





