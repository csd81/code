/*
3.2. Osztás és maradékképzés
3.2.1. Tároljon két tömbben 5-5 egész számot, az osztókat és az 
osztandókat! Az értékeket inicializálással adja át a tömböknek, legyen 
köztük negatívok is! Tippelje meg az egészosztás és maradékképzés 
eredményét! Írja ki a helyes választ és számolja, a helyes válaszok 
számát! Ötlet: ellenőrizze, hogy a második tömbben ne legyen nulla! 
*/ 


#include <iostream>
#include <vector>

int main() {
    const int size = 5;
    std::vector<int> osztandok   = {10, -9, 0, 7, -12};  // op1
    std::vector<int> osztok      = {2, 3, -4, 5, -6};     // op2

    int valasz = 0;
    int pontszam = 0;

    for (int i = 0; i < size; ++i) {
        if (osztok[i] == 0) {
            std::cout << "Hiba: 0-val nem lehet osztani! (" << osztandok[i] << "/0 kihagyva)\n";
            continue;
        }

        // Egész osztás tipp
        std::cout << osztandok[i] << " / " << osztok[i] << " = ";
        std::cin >> valasz;

        int helyes = osztandok[i] / osztok[i];
        std::cout << "Helyes válasz: " << helyes << '\n';
        if (valasz == helyes) {
            ++pontszam;
        }

        // Maradékképzés tipp
        std::cout << osztandok[i] << " % " << osztok[i] << " = ";
        std::cin >> valasz;

        helyes = osztandok[i] % osztok[i];
        std::cout << "Helyes válasz: " << helyes << "\n\n";
        if (valasz == helyes) {
            ++pontszam;
        }
    }

    std::cout << "Összesen " << pontszam << " pontot értél el.\n";
    return 0;
}
