// 2.4.2. Módosítsa az előző programot úgy, hogy 40-től 60-ig fordított 
// sorrendben, a páros számokat írja ki! Az intervallum mindkét határát 
// írja ki!
// 2.4.2.

#include <iostream>

int main() {
    for (int idxI = 60; idxI >= 40; idxI -= 2) {
        std::cout << "idxI is " << idxI << "\n";
    }
    return 0;
}
