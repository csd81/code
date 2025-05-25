// 2.7. Blokkon belüli változók
// 2.7.1. Hozzon létre egy olyan main függvényt, amelyben 3 különböző 
// típusú, 'a' nevű változó szerepel! Az egyes változók típusai: const 
// float, char [200], unsigned long int. Ugyanolyan nevű változókat egy 
// függvényben belül úgy tud létrehozni, hogy a változó definiálások 
// különböző blokkokban vannak. Egy negyedik változóba kérje be, melyik 
// blokkba menjen be a program, írassa ki az ott lévő a változó értékét! 
// 2.7.1.


#include <iostream>
#include <string>

int main() {
    int direction;

    std::cout << "Choose a direction:\n";
    std::cout << "1 - const float\n";
    std::cout << "2 - char[200]\n";
    std::cout << "3 - unsigned long int\n";
    std::cout << "Your choice: ";
    std::cin >> direction;

    if (direction == 1) {
        const float a = 12.345f;
        std::cout << "a (const float) = " << a << std::endl;
    }

    if (direction == 2) {
        char a[200] = "test123";
        std::cout << "a (char[200]) = " << a << std::endl;
    }

    if (direction == 3) {
        unsigned long int a = 98765;
        std::cout << "a (unsigned long int) = " << a << std::endl;
    }

    if (direction < 1 || direction > 3) {
        std::cout << "The direction value is incorrect." << std::endl;
    }

    return 0;
}
