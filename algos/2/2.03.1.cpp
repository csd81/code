// 2.3. Terület és kerületszámítás
// 2.3.1. Írjon programot, amely bekéri egy téglalap két oldalának a 
// hosszát, és hogy területet vagy kerületet akar-e a felhasználó számolni! 
// A választástól függően számolja ki a területet vagy a kerületet! Az 
// oldal hosszak egész értékek, a választás karakter típusú. Ötlet: 
// ügyeljen arra, hogy negatív nagyságú oldal nincsen! 
 

#include <iostream>

int main() {
    int a, b;
    char decision;

    std::cout << "Program to calculate the area or perimeter of a rectangle.\n";

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    // Oldalak érvényességének ellenőrzése
    if (a <= 0 || b <= 0) {
        std::cerr << "Hibás bemenet! Az oldalaknak pozitív egész számoknak kell lenniük.\n";
        return 1;
    }

    std::cout << "Would you like to calculate area (a) or perimeter (p)? ";
    std::cin >> decision;

    if (decision == 'a') {
        std::cout << "The area of the rectangle is: " << (a * b) << "\n";
    } else if (decision == 'p') {
        std::cout << "The perimeter of the rectangle is: " << (2 * (a + b)) << "\n";
    } else {
        std::cerr << "Érvénytelen választás! Csak 'a' vagy 'p' lehet.\n";
        return 1;
    }

    return 0;
}
