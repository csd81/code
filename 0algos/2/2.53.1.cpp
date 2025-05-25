// 2.53. Binomiális tétel
// 2.53.1. Írjon programot, amely beolvas egy n értéket a billentyűzetről, 
// majd a binomiális tétel jobb oldalának kifejtett alakját kiírja a 
// képernyőre! n ne legyen nagyobb 10-nél! A binomiális tétel szerint: (a + 
// b)n = ahol n pozitív egész szám, és (a + b)n = Példa bemenet: n=3 Kimenet: 
// ( a + b )^3 = a^3 + 3ba^2 + 3b^2a + b^3 
// 2.53.1.


#include <iostream>
#include <cstdlib>

using ULint = unsigned long int;

ULint BinomialCoefficient(int n, int k) {
    ULint bc = 1;
    for (int i = 1; i <= k; ++i) {
        bc *= n--;
        bc /= i;
    }
    return bc;
}

void PrintPow(char ch, int p) {
    if (p == 0) return;
    if (p == 1) std::cout << ch;
    else std::cout << ch << "^" << p;
}

void PrintBinom(int n) {
    std::cout << "(a + b)^" << n << " = ";
    for (int i = 0; i <= n; ++i) {
        ULint coeff = BinomialCoefficient(n, i);

        // Ne írjuk ki az 1-est
        if (coeff > 1) std::cout << coeff;

        PrintPow('b', i);
        PrintPow('a', n - i);

        if (i < n) std::cout << " + ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        n = std::atoi(argv[1]);
    } else {
        std::cout << "Degree (max 10): ";
        std::cin >> n;
    }

    if (n < 0 || n > 10) {
        std::cerr << "Error: n must be between 0 and 10.\n";
        return 1;
    }

    PrintBinom(n);
    return 0;
}
