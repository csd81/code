// 3.4. Sztring bekérés
// 3.4.1. Kérjen be egy-egy sztringet gets, getchar és scanf segítségével! 
// Írja ki a sztringeket puts, putchar és printf segítségével! 


#include <iostream>
#include <string>

int main() {
    std::string string1, string2, string3;
    char ch;

    std::cout << "String input with getchar-like (character by character).\n";
    std::cout << "Type something and press Enter (ends on newline):\n";

    // getchar alternatívája: karakterenként olvasás
    while (std::cin.get(ch) && ch != '\n') {
        string1 += ch;
    }

    std::cout << "String input with gets-like (getline): ";
    std::getline(std::cin, string2); // teljes sort beolvas

    std::cout << "String input with scanf-like (cin >>): ";
    std::cin >> string3; // szóközig olvas

    std::cout << "\nstring1 with getchar = " << string1 << std::endl;
    std::cout << "string2 with gets = " << string2 << std::endl;
    std::cout << "string3 with scanf = " << string3 << std::endl;

    std::cout << "Press Enter to exit...";
    std::cin.ignore(); // elnyeli az utolsó sortörést
    std::cin.get();    // vár Entert

    return 0;
}
