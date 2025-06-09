// 2.59. Törtek összeadása
// 2.59.1. Egy fájl több törtet tartalmaz. Írjon programot, amely beolvassa a 
// törteket, és összeadja őket! Minden összeadás után számolja ki az 
// aktuális összeg számlálójának és nevezőjének legnagyobb közös 
// osztóját az Euklideszi algoritmus segít- ségével, és ha lehet, akkor 
// egyszerűsítse a törtet, majd folytassa az összeadást! Minden műveletet 
// írjon ki a képernyőre a példában látható módon! Az Euklideszi 
// algoritmus megadja két szám legnagyobb közös osztóját. procedure 
// Euclidean(A, B) M = B while M is not zero { B = M M = A mod B A = B } Az input 
// fájl formátuma: Első sor: a törtek száma A többi sorban két pozitív 
// egész található, az első a számláló, a második a nevező értéke. A 
// két érték szóköz karakterrel van elválasztva. Példa bemenet: 3 2 3 4 5 6 
// 11 Kimenet: 2 4 ------ + ------ = 3 5 -----15 6 ------ + ------ = -----165 4 
// ------ + ------ = 3 1656 ------ = -----55 
// 2.59.1.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int gcd(int a, int b) {
    while (b != 0) {
        int m = b;
        b = a % b;
        a = m;
    }
    return a;
}

void ReadAndAdd(std::istream& in) {
    int count;
    in >> count;

    int numer = 0, denom = 0;

    for (int i = 0; i < count; ++i) {
        int num, den;
        in >> num >> den;

        if (denom == 0) {
            // Első tört
            numer = num;
            denom = den;
        } else {
            int new_numer = numer * den + num * denom;
            int new_denom = denom * den;
            int d = gcd(new_numer, new_denom);

            if (d > 1) {
                std::cout << std::setw(4) << numer << " " << std::setw(4) << num << " "
                          << std::setw(4) << new_numer << " " << std::setw(4) << (new_numer / d) << "\n";
                std::cout << "------ + ------ = ------ = ------\n";
                std::cout << std::setw(4) << denom << " " << std::setw(4) << den << " "
                          << std::setw(4) << new_denom << " " << std::setw(4) << (new_denom / d) << "\n\n";
            } else {
                std::cout << std::setw(4) << numer << " " << std::setw(4) << num << " "
                          << std::setw(4) << new_numer << "\n";
                std::cout << "------ + ------ = ------\n";
                std::cout << std::setw(4) << denom << " " << std::setw(4) << den << " "
                          << std::setw(4) << new_denom << "\n\n";
            }

            numer = new_numer / d;
            denom = new_denom / d;
        }
    }

    std::cout << "Final result:\n";
    std::cout << std::setw(4) << numer << "\n";
    std::cout << "-----\n";
    std::cout << std::setw(4) << denom << "\n";
}

int main(int argc, char* argv[]) {
    const std::string default_filename = "nums.txt";
    std::ifstream file(argc > 1 ? argv[1] : default_filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    ReadAndAdd(file);
    file.close();
    return 0;
}
