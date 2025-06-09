// 2.16. DeMorgan
// 2.16.1. Írjon programot, amelyben egész változókat használ logikaiként! A 
// változók a következőek: a - van pénzem, b - van kedvem, c - nincs időm, d 
// - nagyon érdekel. Kérje be a változók értékeit és a következők 
// alapján döntse el, hogy megy-e nyaralni: ha van pénze, kedve és ideje, 
// akkor megy, ha az előzőek közül csak egyik igaz, de nagyon érdekli akkor 
// is megy. Írja át a feltételeket DeMorgan azonosságok segítségével! 

#include <iostream>

int main() {
    int gotMoney, gotMood, noTime, veryInterested;

    std::cout << "Type 1 for yes and 0 for no!\n";
    std::cout << "gotMoney = ";
    std::cin >> gotMoney;
    std::cout << "gotMood = ";
    std::cin >> gotMood;
    std::cout << "noTime = ";
    std::cin >> noTime;
    std::cout << "veryInterested = ";
    std::cin >> veryInterested;

    bool hasTime = !noTime;

    // Eredeti logika:
    bool goOriginal =
        (gotMoney && gotMood && hasTime) ||
        ((gotMoney + gotMood + hasTime == 1) && veryInterested);

    // DeMorgan-os forma:
    bool notGo = (!gotMoney || !gotMood || !hasTime) && !(veryInterested && (
        (gotMoney && !gotMood && !hasTime) ||
        (!gotMoney && gotMood && !hasTime) ||
        (!gotMoney && !gotMood && hasTime)
    ));
    bool goDeMorgan = !notGo;

    std::cout << "\n[Original logic] ";
    if (goOriginal)
        std::cout << "I will go on holiday!\n";
    else
        std::cout << "I will not go on holiday!\n";

    std::cout << "[DeMorgan logic] ";
    if (goDeMorgan)
        std::cout << "I will go on holiday!\n";
    else
        std::cout << "I will not go on holiday!\n";

    return 0;
}
