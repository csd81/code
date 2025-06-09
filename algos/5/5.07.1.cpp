
// c++11
/* //  5.7.1. Állítsuk elő a Pascal háromszöget a k-dik sorig, sor adatszerkezetet használva! Ötlet:ha az i-dik sora megvan a Pascal háromszögnek, akkor abból megkapjuk a i+1-edik sort a következő képen. Vegyük ki az utolsó elemet a sorból és tároljuk el, adjuk hozzá az új utolsó elemet, majd rakjuk be a sor elejére. Az előző műveleteket összesen (i-1)-szer hajtsuk végre, ezután rakjuk be a sor elejére az „1” elemet. Példa: (1 3 3 1);
utolsó elem ki -> (1 3 3);
összeadás, lista elejére fűzés -> (4 1 3 3);
utolsó elem ki -> (4 1 3);
összeadás, lista elejére fűzés -> (6 4 1 3);
utolsó elem ki -> (6 4 1);
összeadás, lista elejére fűzés -> (4 6 4 1);
’1’-es elem befűzése a lista elejére -> (1 4 6 4 1).  
*/

// c++11
#include <iostream>
#include <deque>
#include <iomanip>

int main() {
    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);

    int k;
    std::cout << "Enter number of rows (k): ";
    std::cin >> k;
    if (k < 0) return 0;

    // We'll generate rows 0 through k of Pascal's triangle.
    // We store each row in a deque<int>.
    std::deque<int> row{1};

    for (int i = 0; i <= k; ++i) {
        // Print leading spaces for a nice triangle shape
        int spaces = k - i;
        for (int s = 0; s < spaces; ++s) 
            std::cout << "   ";

        // Print the current row
        for (int v : row) 
            std::cout << std::setw(4) << v;
        std::cout << "\n";

        // Build the next row from the current one
        std::deque<int> next;
        next.push_back(1);
        for (size_t j = 1; j < row.size(); ++j) {
            next.push_back(row[j-1] + row[j]);
        }
        next.push_back(1);
        row.swap(next);
    }

    return 0;
}

