// 2.22. main paraméterek
// 2.22.1. Írjon programot, amely kiírja a program paramétereit fordított 
// sorrendben! 
// 2.22.1.


#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = argc - 1; i >= 0; --i) {
        std::cout << "The " << i << ". parameter is: " << argv[i] << std::endl;
    }
    return 0;
}
