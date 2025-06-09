// 3.47.1. Egy 30 fős osztályban minden tanulóról tudjuk, hogy 
// informatikából mennyi a jegyeinek az átlaga. Írjon programot, amely 
// billentyűzetről beolvassa a 30 átlagot, majd kiírja a képernyőre, hogy 
// volt-e bukás idén! Az bukik meg, akinek az átlaga kevesebb, mint 1.5. 
// 3.47.1.

#include <iostream>
#include <vector>

constexpr int N = 30;
constexpr double BUKAS_HATAR = 1.5;

int main() {
    std::vector<double> atlagok(N);
    bool voltBukas = false;

    for (int i = 0; i < N; ++i) {
        std::cout << "A(z) " << (i + 1) << ". atlag: ";
        std::cin >> atlagok[i];
        if (atlagok[i] < BUKAS_HATAR) {
            voltBukas = true;
        }
    }

    std::cout << "\n" << (voltBukas ? "Volt bukas!" : "Nem volt bukas!") << "\n";

    return 0;
}
