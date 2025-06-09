// 2.31. Esküvő
// 2.31.1. Készítsen programot, amely tartalmazza a következő 
// adatszerkezeteket: ember típus: név, életkor, azonosító;
// gyűrű típus: karát, érték, kövek száma;
// esküvő típus: férj, feleség, eljegyzési gyűrű, esküvői gyűrű, 
// vendégek (dinamikus tömb), vendégek száma. Inicializáljon egy esküvő 
// típusú változót, írja ki a változó értékét szépen tördelve úgy, 
// hogy minden struktúra kiíráshoz külön függvényt hoz létre! 
// 2.31.1.

#include <iostream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    int age;
    int ID;
};

struct Ring {
    int carat;
    double price;
    int numberOfStones;
};

struct Wedding {
    Person man;
    Person wife;
    Ring engagementRing;
    Ring weddingRing;
    std::vector<Person> guests;
};

// Kiíró függvények
void printPerson(const Person& p) {
    std::cout << "Person { "
              << "name: \"" << p.name << "\", "
              << "age: " << p.age << ", "
              << "ID: " << p.ID
              << " }";
}

void printRing(const Ring& r) {
    std::cout << "Ring { "
              << "carat: " << r.carat << ", "
              << "price: " << r.price << ", "
              << "stones: " << r.numberOfStones
              << " }";
}

void printWedding(const Wedding& w) {
    std::cout << "Wedding {\n";
    std::cout << "  Man: ";    printPerson(w.man);    std::cout << "\n";
    std::cout << "  Wife: ";   printPerson(w.wife);   std::cout << "\n";
    std::cout << "  Engagement Ring: "; printRing(w.engagementRing); std::cout << "\n";
    std::cout << "  Wedding Ring:    "; printRing(w.weddingRing);    std::cout << "\n";
    std::cout << "  Guests (" << w.guests.size() << "):\n";
    for (const auto& guest : w.guests) {
        std::cout << "    - "; printPerson(guest); std::cout << "\n";
    }
    std::cout << "}\n";
}

int main() {
    // Vendégek (dinamikus vektor)
    std::vector<Person> friends = {
        { "Jani",  28, 12345 },
        { "Emese", 29, 66666 },
        { "Zoli",  32, 222222 }
    };

    // Esküvő inicializálása
    Wedding brotherWedding {
        { "Arpi",  32, 23332 },    // férj
        { "Panna", 29, 22222 },    // feleség
        { 16,     60000.0, 0    }, // eljegyzési gyűrű
        { 24,    200000.0, 3    }, // esküvői gyűrű
        friends                   // vendégek
    };

    // Kiírás
    printWedding(brotherWedding);

    return 0;
}
