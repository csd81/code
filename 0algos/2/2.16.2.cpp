// 2.16.2. Kérje be a következő változókat: a - esik az eső, b - jönnek 
// mások is, c - van szabadnapom. Ezen változók alapján határozzuk meg, hogy 
// mikor megy a felhasználó túrázni. A feltételek a következőek: akkor 
// megyek túrázni ha, nem esik az eső és van szabadnapom;
// akkor is túrázom, ha mások nem jönnek, de az eső esik. Írja át a 
// feltételeket De Morgan azonosságok segítségével! 

#include <iostream>

int main() {
    int isRaining, comeOthers, gotFreeTime;

    std::cout << "Type 1 for yes and 0 for no!\n";
    std::cout << "isRaining: ";
    std::cin >> isRaining;
    std::cout << "comeOthers: ";
    std::cin >> comeOthers;
    std::cout << "gotFreeTime: ";
    std::cin >> gotFreeTime;

    // Eredeti logikai forma:
    bool hikeOriginal = (!isRaining && gotFreeTime) || (isRaining && !comeOthers);

    // DeMorgan forma:
    // (!isRaining && gotFreeTime) → !(isRaining || !gotFreeTime)
    // (isRaining && !comeOthers) → !( !isRaining || comeOthers )
    bool hikeDeMorgan = !(isRaining || !gotFreeTime) || !( !isRaining || comeOthers );

    std::cout << "\n[Original logic] ";
    if (hikeOriginal)
        std::cout << "I'm going hiking!\n";
    else
        std::cout << "Perhaps next time.\n";

    std::cout << "[DeMorgan logic] ";
    if (hikeDeMorgan)
        std::cout << "I'm going hiking!\n";
    else
        std::cout << "Perhaps next time.\n";

    return 0;
}
