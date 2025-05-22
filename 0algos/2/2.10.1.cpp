



// 2.10.1. Készítsünk 5*5-ös egyedi szorzótáblát, amelyet a karakteres képernyőn jelenítünk meg! Az első sor és oszlop értékeit, amelyek mutatják, hogy mit mivel kell összeszorozni, vonalakkal különítsük el a szorzatoktól! Az első sor és az első oszlop értékeit a billentyűzetről kérjük be! 


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int SIZE = 5;
    double top[SIZE], side[SIZE];

    // Read the values for the top (first row) headers
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value for top[" << i << "]: ";
        cin >> top[i];
    }

    // Read the values for the side (first column) headers
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value for side[" << i << "]: ";
        cin >> side[i];
    }

    cout << "\nCustom 5 x 5 multiplication table:\n\n";

    // Print the top header row
    // First cell is blank
    cout << setw(10) << " " << "|";
    for (int j = 0; j < SIZE; j++) {
        cout << setw(10) << fixed << setprecision(4) << top[j] << "|";
    }
    cout << "\n";

    // Separator line
    int totalWidth = 10 + 1 + SIZE * (10 + 1);
    for (int k = 0; k < totalWidth; k++) {
        cout << "-";
    }
    cout << "\n";

    // Print each row: side header, then the products
    for (int i = 0; i < SIZE; i++) {
        // Side header
        cout << setw(10) << fixed << setprecision(4) << side[i] << "|";
        // Products
        for (int j = 0; j < SIZE; j++) {
            cout << setw(10) << fixed << setprecision(4)
                 << side[i] * top[j] << "|";
        }
        cout << "\n";
    }

    return 0;
}




