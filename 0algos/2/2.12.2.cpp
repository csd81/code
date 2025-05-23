


2.12.2. Írjon programot a logikai és bitenkénti operátorok használatának 
a szemléltetésére! 
2.12.2.
#include <stdio.h>
#include <math.h> int main() { int op1, op2;
char more = 'y';
while (more == 'y') { printf("\nop1= ");
scanf("%d", &op1);
printf("op2= ");
scanf("%d", &op2);
printf("%d&%d = %d\n", op1, op2, op1 & op2);
printf("%d|%d = %d\n", op1, op2, op1 | op2);
printf("%d^%d = %d\n", op1, op2, op1 ^ op2);
printf("~%d = %d\n", op1, ~op1);
printf("~%d = %d\n", op2, ~op2);
printf("Do you want to continue? (y, n) ");
_flushall();
scanf("%c", &more);
} return 0;
} 

```cpp
#include <iostream>
#include <limits>

int main() {
    int op1, op2;
    char more = 'y';

    std::cout << "Demonstrate logical and bitwise operators on two 
integers\n\n";

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
        std::cout << "\nLogical operations (treating 0 as false, non-zero as 
true):\n";
        std::cout << op1 << " && " << op2 << " = " << ( (op1 && op2) ? 1 : 0 ) 
<< "\n";
        std::cout << op1 << " || " << op2 << " = " << ( (op1 || op2) ? 1 : 0 ) 
<< "\n";
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
```

**How it works**

* We read two integers `op1` and `op2`, validating input to ensure they’re 
integers.
* **Bitwise operators**

  * `&` (AND), `|` (OR), `^` (XOR), `~` (NOT).
* **Logical operators**

  * `&&` (logical AND), `||` (logical OR), `!` (logical NOT).
    Results are normalized to `1` (true) or `0` (false) in the output.
* After displaying all results, the program asks if you’d like to repeat; 
entering `y` or `Y` continues the loop.
* We use `std::numeric_limits<std::streamsize>::max()` with `ignore()` to clear 
any leftover input and keep the stream in a good state.



