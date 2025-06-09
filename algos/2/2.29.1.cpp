// 2.29.1. Írjon programot, amelyben bekéri, hogy rövid egész vagy hosszú 
// lebegőpontos típussal akar dolgozni. Hozzon létre két dinamikus változót 
// a megfelelő típusból! Kérje be a változók értékeit és az első 
// változó értékét növelje meg a másodikéval! 

// 2.29.1.

#include <iostream>
#include <memory>    // opcionális: std::unique_ptr
using namespace std;

int main() {
    int choice;
    cout << "Choose operand type:\n"
         << "  1) short int\n"
         << "  2) long double\n"
         << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        // Dinamikus short int változók
        short int* si1 = new short int;
        short int* si2 = new short int;

        cout << "Enter si1: ";
        cin >> *si1;
        cout << "Enter si2: ";
        cin >> *si2;

        *si1 += *si2;
        cout << "The increased value is: " << *si1 << "\n";

        delete si1;
        delete si2;
    }
    else if (choice == 2) {
        // Dinamikus long double változók
        long double* ld1 = new long double;
        long double* ld2 = new long double;

        cout << "Enter ld1: ";
        cin >> *ld1;
        cout << "Enter ld2: ";
        cin >> *ld2;

        *ld1 += *ld2;
        cout << "The increased value is: " << *ld1 << "\n";

        delete ld1;
        delete ld2;
    }
    else {
        cerr << "Invalid choice.\n";
        return 1;
    }

    return 0;
}
