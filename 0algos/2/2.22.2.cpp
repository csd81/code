// 2.22.2. Írja át úgy a programot, hogy elől tesztelős ciklust használ és 
// a program nevét nem írja ki! 
// 2.22.2.


#include <iostream>

int main(int argc, char* argv[]) {
    int i = argc - 1;

    while (i >= 1) { // program neve (argv[0]) kihagyva
        std::cout << "The " << i << ". parameter is: " << argv[i] << std::endl;
        --i;
    }

    return 0;
}


