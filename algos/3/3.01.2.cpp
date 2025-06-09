
/* c++11
3.1.2. Alakítsa át a program kiírását úgy, hogy a bekért szó 
függőlegesen jelenjen meg és a hozzá tartozó kiírások az egyes 
karakterektől jobbra helyezkedjenek el! 

3.1.2.
*/


#include <iostream>
#include <iomanip>
#include <string>

int main() {
    const int size = 6;
    char str[size + 1] = {};  // +1 a null terminátor miatt

    std::cout << "string = ";
    std::cin >> std::setw(size + 1) >> str;

    std::cout << "\nThe string is: " << str << '\n';
    std::cout << "The static string address, str: " << static_cast<void*>(str) << '\n';
    std::cout << "The dynamic string address, &str: " << static_cast<void*>(&str) << "\n\n";

    for (int i = 0; i < size; ++i) {
        char ch = str[i];
        std::cout << "'" << ch << "'\t";

        // Hexadecimális ASCII érték
        std::cout << "0x" << std::hex << std::uppercase
                  << std::setw(2) << std::setfill('0')
                  << static_cast<int>(static_cast<unsigned char>(ch)) << std::dec;

        // Index és cím
        std::cout << "\tstring[" << i << "]"
                  << "\t" << static_cast<void*>(&str[i]) << '\n';
    }

    return 0;
}
