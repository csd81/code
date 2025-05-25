// 2.6. Adatbekérés

// 2.6.1. Írjon programot, amellyel bekéri egy ember adati közül a 
// következőket: azonosító szám - int, életkor - unsigned int, neme - char, 
// súlya - float, bankszámla egyenlege - double, neve - char[200]! A bekért 
// adatokat írja ki újból a képernyőre! A megadott és a kiírt érték mikor 
// különbözhet? Mutasson rá példát! 
// 2.6.1.

#include <iostream>
#include <string>
#include <limits>

int main() {
    int id;
    unsigned int age;
    char sex;
    float weight;
    double accountBalance;
    std::string name;

    std::cout << "id = ";
    std::cin >> id;

    std::cout << "age = ";
    std::cin >> age;

    // Input buffer ürítése enter után
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "sex = ";
    std::cin >> sex;

    std::cout << "weight = ";
    std::cin >> weight;

    std::cout << "account balance = ";
    std::cin >> accountBalance;

    // Input buffer ürítése enter után, a teljes név bekéréséhez
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "name = ";
    std::getline(std::cin, name);  // szóközöket is kezel

    // Kiírás
    std::cout << "\nYour data:\n";
    std::cout << "id = " << id << "\n";
    std::cout << "age = " << age << "\n";
    std::cout << "sex = " << sex << "\n";
    std::cout << "weight = " << weight << "\n";
    std::cout << "account balance = " << accountBalance << "\n";
    std::cout << "name = " << name << "\n";

    return 0;
}
