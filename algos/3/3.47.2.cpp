// 3.47.2. Módosítsa az előző programot úgy, hogy addig olvassa be az 
// átlagokat, amíg bukott embert nem talál! Amennyiben 0-t olvasunk be, az azt 
// jelenti, hogy vége a beolvasásnak, vagyis ez nem egy átlag. A program ez 
// esetben is írja ki, hogy bukik-e valaki! 



#include <iostream>

constexpr double BUKAS_HATAR = 1.5;

int main() {
    double atlag = 0.0;
    int sorszam = 1;
    bool voltBukas = false;

    while (true) {
        std::cout << "Kerem a(z) " << sorszam++ << ". atlagot: ";
        std::cin >> atlag;

        if (atlag == 0.0) {
            break;
        }

        if (atlag < BUKAS_HATAR) {
            voltBukas = true;
            break;
        }
    }

    std::cout << (voltBukas ? "Volt bukas!\n" : "Nem volt bukas!\n");

    return 0;
}
