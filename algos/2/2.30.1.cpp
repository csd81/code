// 2.30. Struktúra kezelés
// 2.30.1. Készítsen struktúrát, amely minden egyszerű adattípusból 
// tartalmaz egyet valamint egy egészre mutató mutatót! Kérje be a struktúra 
// adattagjait a konzolról, majd írja ki azokat! 
// 2.30.1.


#include <iostream>
#include <memory>   // std::unique_ptr

struct Var {
    char        varChar;
    short       varShortInt;
    int         varInt;
    float       varFloat;
    double      varDouble;
    long double varLongDouble;
    int*        varPInt;
};

int main() {
    Var myVar;

    std::cout << "varChar: ";
    std::cin >> myVar.varChar;

    std::cout << "varShortInt: ";
    std::cin >> myVar.varShortInt;

    std::cout << "varInt: ";
    std::cin >> myVar.varInt;

    std::cout << "varFloat: ";
    std::cin >> myVar.varFloat;

    std::cout << "varDouble: ";
    std::cin >> myVar.varDouble;

    std::cout << "varLongDouble: ";
    std::cin >> myVar.varLongDouble;

    // A mutatóhoz bekérünk egy egész értéket, és dinamikusan lefoglaljuk
    int temp;
    std::cout << "Enter integer for varPInt (we'll allocate and store it): ";
    std::cin >> temp;
    myVar.varPInt = new int(temp);

    // Kiírás
    std::cout << "\n--- myVar contents ---\n";
    std::cout << "varChar        = " << myVar.varChar        << "\n";
    std::cout << "varShortInt    = " << myVar.varShortInt    << "\n";
    std::cout << "varInt         = " << myVar.varInt         << "\n";
    std::cout << "varFloat       = " << myVar.varFloat       << "\n";
    std::cout << "varDouble      = " << myVar.varDouble      << "\n";
    std::cout << "varLongDouble  = " << myVar.varLongDouble  << "\n";
    std::cout << "varPInt (addr) = " << static_cast<void*>(myVar.varPInt)
              << "  *varPInt = " << *myVar.varPInt      << "\n";

    // Felszabadítás
    delete myVar.varPInt;
    myVar.varPInt = nullptr;

    return 0;
}
