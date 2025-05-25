
// 2.25.2. Írjon olyan függvényt az előző programhoz, amely lenullázza az 
// aktuális összeget! 

// 2.25.2. 

#include <iostream>

class Accumulator {
    static int total;
public:
    static int add(int value) {
        total += value;
        return total;
    }

    static int get() {
        return total;
    }

    static void reset() {
        total = 0;
    }
};

int Accumulator::total = 0;

int main() {
    int num;
    char more = 'y';

    do {
        std::cout << "Provide the next number: ";
        std::cin >> num;
        std::cout << "Current total: " << Accumulator::add(num) << "\n";

        std::cout << "Do you want to cancel total (c), continue (y), or exit (n)? ";
        std::cin >> more;
        std::cin.ignore(10000, '\n');

        if (more == 'c') {
            Accumulator::reset();
            std::cout << "Total reset to 0.\n";
        }

    } while (more == 'y' || more == 'c');

    std::cout << "Final total: " << Accumulator::get() << "\n";

    return 0;
}
