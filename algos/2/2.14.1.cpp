// 2.14. Hatványsor
// 2.14.1. Írjunk programot, amely hatványsor és könyvtári függvény 
// segítségével is kiszámolja ex értékét a következő képlettel: = ! 
// Megfelelően pontos értéket kapunk, ha a sort a negyedik elemig határozzuk 
// meg. Írjuk ki a hatványsor és a valós érték közötti különbséget!
// 2.14.1.


#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x;
    int length;

    std::cout << "The accuracy of power series calculating e^x\n";
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "Length of the power series = ";
    std::cin >> length;

    double powerSeries = 1.0;
    double factorial = 1.0;

    // Hatványsor számítás: 1 + x/1! + x^2/2! + ... + x^(n-1)/(n-1)!
    for (int i = 1; i < length; ++i) {
        factorial *= i;
        powerSeries += std::pow(x, i) / factorial;
    }

    double accurate = std::exp(x);
    double difference = std::fabs(accurate - powerSeries);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Power series approximation: " << powerSeries << "\n";
    std::cout << "Library value (exp):        " << accurate << "\n";
    std::cout << "Difference:                 " << difference << "\n";

    return 0;
}
