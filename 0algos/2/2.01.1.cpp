


2.1.1. Írjon programot, amely bekéri egy vizsga eredményének százalékos értékét és kiírja, hogy sikeres volt-e a vizsga! A siker feltétele az 50%-nál jobb teljesítmény. Ötlet: ügyeljen arra, hogy az 50% még bukást jelent! 
2.1.1.
#include <stdio.h> int main() { float result;
printf("result=");
_flushall();
scanf("%f", &result);
if (result>50) { printf("Passed\n");
} else { printf("Failed\n");
} return 0;
} 

Here’s a clean C++11 version that reads a percentage grade, checks if it’s strictly greater than 50 % (so exactly 50 % still fails), and prints “Passed” or “Failed”:

```cpp
#include <iostream>
#include <iomanip>

int main() {
    double result;

    std::cout << "Enter exam result (in %): ";
    std::cin  >> result;

    if (!std::cin) {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    // 50.0% is still a fail; must be >50.0 to pass
    if (result > 50.0) {
        std::cout << "Passed\n";
    } else {
        std::cout << "Failed\n";
    }

    return 0;
}
```

**How it works**

* We use `double` for the percentage to handle fractional inputs (e.g. 50.5).
* `std::cin >> result` reads the value; we guard against invalid input.
* The `if (result > 50.0)` check ensures that exactly 50.0 counts as a failure.

Compile with any C++11-compliant compiler:

```bash
g++ -std=c++11 -o pass_fail pass_fail.cpp
./pass_fail
```
