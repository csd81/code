// 2.34.  Bitmezők
// 2.34.1. Írjon programot egyén adatainak a tárolásához! Az ember típus 
// mezői a név (statikus tömb), nem, nagykorú-e, csillagjegye, vallása (5 
// nagy vallás vagy egyéb), élő személy-e, vércsoport, RH csoport! 
// Használjon megfelelő hosszú bitmezőket! Írjon bekérő és kiíró 
// függvényt, a kiíró függvénynél ne számokat, hanem azok jelentéseit 
// írja ki! Határozza meg a struktúra méretét! 
// 2.34.1.

#include <iostream>
#include <string>
#include <array>
#include <iomanip>

struct Person {
    // Name as fixed-size C-string
    char name[100];

    // Bitfields
    unsigned sex       : 1;  // 0=female,1=male
    unsigned grownUp   : 1;  // 0=no,1=yes
    unsigned zodiac    : 4;  // 0–11 covers 12 signs
    unsigned religion  : 3;  // 0–5 covers 6 choices
    unsigned bloodType : 2;  // 0=O,1=A,2=B,3=AB
    unsigned RH        : 1;  // 0='-',1='+'
};

void readPerson(Person& p) {
    int tmp;

    std::cout << "name: ";
    std::cin >> p.name;

    std::cout << "sex (0=female,1=male): ";
    std::cin >> tmp;  p.sex = tmp;

    std::cout << "grown up? (0=no,1=yes): ";
    std::cin >> tmp;  p.grownUp = tmp;

    std::cout
      << "zodiac (0=Aries,1=Taurus,2=Gemini,3=Cancer,\n"
      << "        4=Leo,5=Virgo,6=Libra,7=Scorpio,\n"
      << "        8=Sagittarius,9=Capricorn,10=Aquarius,11=Pisces): ";
    std::cin >> tmp;  p.zodiac = tmp;

    std::cout
      << "religion (0=Judaism,1=Christian,2=Islam,\n"
      << "          3=Hinduism,4=Buddhism,5=other): ";
    std::cin >> tmp;  p.religion = tmp;

    std::cout << "blood type (0=O,1=A,2=B,3=AB): ";
    std::cin >> tmp;  p.bloodType = tmp;

    std::cout << "RH (0='-',1='+'): ";
    std::cin >> tmp;  p.RH = tmp;
}

void printPerson(const Person& p) {
    static const std::array<std::string,12> zodiacs = {
      "Aries","Taurus","Gemini","Cancer",
      "Leo","Virgo","Libra","Scorpio",
      "Sagittarius","Capricorn","Aquarius","Pisces"
    };
    static const std::array<std::string,6> religions = {
      "Judaism","Christian","Islam","Hinduism","Buddhism","other"
    };
    static const std::array<std::string,4> bloods = {
      "O","A","B","AB"
    };

    std::cout << "\nPerson {\n";
    std::cout << "  name:       " << p.name       << "\n";
    std::cout << "  sex:        " << (p.sex ? "male" : "female") << "\n";
    std::cout << "  grownUp:    " << (p.grownUp ? "yes" : "no")      << "\n";
    std::cout << "  zodiac:     " << zodiacs[p.zodiac]                << "\n";
    std::cout << "  religion:   " << religions[p.religion]            << "\n";
    std::cout << "  bloodType:  " << bloods[p.bloodType]             << "\n";
    std::cout << "  RH:         " << (p.RH ? "+" : "-")               << "\n";
    std::cout << "};\n";

    std::cout << "Sizeof(Person) = "
              << sizeof(Person) << " bytes\n";
}

int main() {
    Person me;
    readPerson(me);
    printPerson(me);
    return 0;
}
