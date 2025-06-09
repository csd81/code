// 2.56. Pascal háromszög
// 2.56.1. Írjon programot, amely kiírja a képernyőre a Pascal háromszög 
// első 10 sorát! Két szám között 4 szóköz karakter legyen! Az r-edik sor 
// i-edik tagját számolja a következőképlettel: r! / ( i! * ( r - i )! ) 
// Kimenet: 1 1 1 1 1 1 1 9 1 1 8 7 1 6 1 5 4 2 3 6 1 3 4 1 5 1 6 1 7 1 8 1 9 1 1 
// 2.56.1.


#include <iostream>
#include <iomanip>
#include <cstdlib>

const int DEFAULT_ROWNUM = 10;
const int SPACE_WIDTH = 4;

int BinomialCoefficient(int n, int k) {
    int bc = 1;
    if (k == 0 || k == n) return 1;
    for (int i = 1; i <= k; ++i) {
        bc *= n--;
        bc /= i;
    }
    return bc;
}

int GetRowWidth(int n) {
    return n * 3 + (n - 1) * SPACE_WIDTH;
}

void PascalsTriangle(int rows) {
    int triangleWidth = GetRowWidth(rows);
    for (int r = 0; r < rows; ++r) {
        int rowWidth = GetRowWidth(r + 1);
        int spaces = (triangleWidth - rowWidth) / 2;
        std::cout << std::string(spaces, ' ');

        for (int i = 0; i <= r; ++i) {
            std::cout << std::setw(3) << BinomialCoefficient(r, i);
            std::cout << std::string(SPACE_WIDTH, ' ');
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    int rows = (argc > 1) ? std::atoi(argv[1]) : DEFAULT_ROWNUM;
    PascalsTriangle(rows);
    return 0;
}
