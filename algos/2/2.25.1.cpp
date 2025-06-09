// 2.25. Lépésenkénti összegzés
// 2.25.1. Írjon programot, amely a konzolról kér be egész számokat egy 
// ciklus segítségével és egy függvény segítségével számolja ki azok 
// összegét! Ezt a függvényt minden szám bekérése után hívja, ami ezután 
// visszaadja az eddigi számok összegét. Használjon statikus változót a 
// részösszeg tárolására! 
// 2.25.1.


#include <iostream>

int sum(int data) {
    static int result = 0;
    result += data;
    return result;
}

int main() {
    int num, total = 0;
    char more = 'y';

    do {
        std::cout << "Provide the next number: ";
        std::cin >> num;

        total = sum(num);

        std::cout << "Are there more numbers? (y/n): ";
        std::cin >> more;
        std::cin.ignore(10000, '\n');  // input buffer ürítése
    } while (more == 'y' || more == 'Y');

    std::cout << "The total is " << total << "." << std::endl;

    return 0;
}
