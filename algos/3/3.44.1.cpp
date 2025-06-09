/* 3.44. Kerítés

3.44.1. Egy 400 méter kerületű telket szeretnénk körülvenni 
drótkerítéssel. Több köteg drótkerítésünk van, amelyek hosszát 
egyenként ismerjük. Írjon programot, amely 0 végjelig beolvassa az egyes 
kötegek hosszait, majd a végén kiírja, hogy összesen hány méternyi 
kerítésünk van és, ha kell-e még kerítést vennünk, akkor összesen 
mennyit! 

3.44.1.
*/

#include <iostream>

int main() {
    int koteg = 0;
    int osszeg = 0;

    std::cout << "Adja meg a kerítéskötetek hosszát (0 végjelig):\n";

    do {
        std::cout << "Köteg hossza (m): ";
        std::cin >> koteg;
        if (koteg > 0) {
            osszeg += koteg;
        }
    } while (koteg != 0);

    std::cout << "Összesen van " << osszeg << " méter kerítésünk.\n";

    if (osszeg < 400) {
        std::cout << "Még szükség van " << 400 - osszeg << " méternyi kerítésre.\n";
    } else {
        std::cout << "Megvan a szükséges kerítésmennyiség.\n";
    }

    return 0;
}

