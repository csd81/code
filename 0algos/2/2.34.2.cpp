// 2.34.2. Módosítsa úgy a struktúrát, hogy bitmezők helyett egész 
// változókat használ! Mennyivel nő a struktúra mérete? 
// 2.34.2.


#include <iostream>
#include <string>
#include <array>
#include <limits>    // <-- ide kell
#include <iomanip>   // ha fixed/setprecision kellene

struct Person {
    std::string name;
    unsigned int sex;
    unsigned int grownUp;
    unsigned int zodiac;
    unsigned int religion;
    unsigned int bloodType;
    unsigned int RH;
};

void readPerson(Person& p) {
    std::cout << "name: ";
    std::getline(std::cin, p.name);

    std::cout << "sex (0=female,1=male): ";
    std::cin >> p.sex;

    std::cout << "grownUp (0=no,1=yes): ";
    std::cin >> p.grownUp;

    std::cout << "zodiac (0=Aries ... 11=Pisces): ";
    std::cin >> p.zodiac;

    std::cout << "religion (0=Judaism ... 5=other): ";
    std::cin >> p.religion;

    std::cout << "bloodType (0=O,1=A,2=B,3=AB): ";
    std::cin >> p.bloodType;

    std::cout << "RH (0='-',1='+'): ";
    std::cin >> p.RH;

    // Töröljük a \n-t, hogy a következő getline jól menjen
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printPerson(const Person& p) {
    static const std::array<std::string,12> ZODIAC = {
      "Aries","Taurus","Gemini","Cancer","Leo","Virgo",
      "Libra","Scorpio","Sagittarius","Capricorn",
      "Aquarius","Pisces"
    };
    static const std::array<std::string,6> RELIGION = {
      "Judaism","Christian","Islam","Hinduism","Buddhism","other"
    };
    static const std::array<std::string,4> BLOOD = { "O","A","B","AB" };

    std::cout << "\nPerson {\n"
              << "  name:       " << p.name       << "\n"
              << "  sex:        " << (p.sex ? "male" : "female") << "\n"
              << "  grownUp:    " << (p.grownUp ? "yes" : "no")     << "\n"
              << "  zodiac:     " << ZODIAC[p.zodiac]                << "\n"
              << "  religion:   " << RELIGION[p.religion]            << "\n"
              << "  bloodType:  " << BLOOD[p.bloodType]             << "\n"
              << "  RH:         " << (p.RH ? "+" : "-")              << "\n"
              << "}\n"
              << "sizeof(Person) = " << sizeof(Person) << " bytes\n";
}

int main() {
    Person me;
    readPerson(me);
    printPerson(me);
    return 0;
}
