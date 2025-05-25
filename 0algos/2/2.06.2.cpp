// 2.6.2. Kérje be majd írassa ki egy autó tulajdonságait! A tulajdonságok a 
// következőek: márka - char[200], végsebesség - float, regisztrációs szám 
// - hexa, tömeg double, típus név - char[300], utas szám - int, műholdas 
// navigáció - char. 
// 2.6.2.


#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string marka;
    float vegsebesseg;
    int rendszam;
    double tomeg;
    std::string tipusnev;
    int utasszam;
    char muszNav;

    std::cout << "Adja meg az autó adatait:\n";

    std::cout << "Márka: ";
    std::getline(std::cin, marka);

    std::cout << "Végsebesség (km/h): ";
    std::cin >> vegsebesseg;

    std::cout << "Regisztrációs szám (hexadecimális számként): 0x";
    std::cin >> std::hex >> rendszam; // hex bemenet

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Tömeg (kg): ";
    std::cin >> tomeg;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Típusnév: ";
    std::getline(std::cin, tipusnev);

    std::cout << "Utasszám: ";
    std::cin >> utasszam;

    std::cout << "Műholdas navigáció van? (y/n): ";
    std::cin >> muszNav;

    // Kiírás
    std::cout << "\nMegadott autó adatai:\n";
    std::cout << "Márka: " << marka << "\n";
    std::cout << "Végsebesség: " << vegsebesseg << " km/h\n";
    std::cout << "Regisztrációs szám (decimálisan): " << std::dec << rendszam << "\n";
    std::cout << "Tömeg: " << tomeg << " kg\n";
    std::cout << "Típusnév: " << tipusnev << "\n";
    std::cout << "Utasszám: " << utasszam << "\n";
    std::cout << "Műholdas navigáció: " << ((muszNav == 'y' || muszNav == 'Y') ? "igen" : "nem") << "\n";

    return 0;
}
