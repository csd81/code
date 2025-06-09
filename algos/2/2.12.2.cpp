// 2.12.2. Írjon programot a logikai és bitenkénti operátorok használatának 
// a szemléltetésére! 


#include <iostream>
#include <limits>

int main() {
    int op1, op2;
    char more = 'y';

    std::cout << "Demonstrate logical and bitwise operators on two integers\n\n";

    while (more == 'y' || more == 'Y') {
        // Read first integer
        std::cout << "Enter first integer (op1): ";
        while (!(std::cin >> op1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Read second integer
        std::cout << "Enter second integer (op2): ";
        while (!(std::cin >> op2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Bitwise operations
        std::cout << "\nBitwise operations:\n";
        std::cout << op1 << " &  " << op2 << "  = " << (op1 & op2) << "\n";
        std::cout << op1 << " |  " << op2 << "  = " << (op1 | op2) << "\n";
        std::cout << op1 << " ^  " << op2 << "  = " << (op1 ^ op2) << "\n";
        std::cout << "~"  << op1 << "       = " << (~op1) << "\n";
        std::cout << "~"  << op2 << "       = " << (~op2) << "\n";

        // Logical operations
        std::cout << "\nLogical operations (treating 0 as false, non-zero as true):\n";
        std::cout << op1 << " && " << op2 << " = " << ( (op1 && op2) ? 1 : 0 ) << "\n";
        std::cout << op1 << " || " << op2 << " = " << ( (op1 || op2) ? 1 : 0 ) << "\n";
        std::cout << "!"  << op1 << "       = " << ( (!op1) ? 1 : 0 ) << "\n";
        std::cout << "!"  << op2 << "       = " << ( (!op2) ? 1 : 0 ) << "\n";

        // Repeat?
        std::cout << "\nDo you want to try again? (y/n): ";
        std::cin >> more;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }

    std::cout << "Program terminated.\n";
    return 0;
}

