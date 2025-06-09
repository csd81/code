// 3.37. Mátrixműveletek
// 3.37.1. Írjon programot mátrixösszeadás és skalárral való szorzás 
// megvalósítására! A program olvassa be fájlból két mátrixot! Adja össze 
// a két mátrixot, és az eredményt szorozza meg 2-vel! A mátrixokat 
// dinamikusan hozza létre! Ha A, B és C azonos méretű mátrixok, akkor Cij = 
// Aij + Bij , ahol C az A és B mátrixok összege. Egy mátrix „d” 
// skalárral való szorzásakor a mátrix minden elemét „d”-vel szorozzuk. 
// Az input fájl formátuma: Első sor: Két szám, az első a sorok, a második 
// az oszlopok száma. A többi sorban a két mátrix található, a példában 
// látható módon. Minden sorban egy-egy mátrix-sor van, a számok szóköz 
// karakterekkel vannak elválasztva. A mátrixok elemei egész számok. Példa 
// bemenet: 2 3 4 3 4 3 1 5 2 4 1 1 7 3 Kimenet: A : 4 3 4 3 1 5 B : 2 4 1 1 7 3 
// ************************ (A + B) * 2 = 12 14 10 8 16 16 

// 3.37.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

using Matrix = std::vector<std::vector<int>>;

Matrix readMatrix(std::ifstream& in, int rows, int cols) {
    Matrix mat(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            in >> mat[i][j];
    return mat;
}

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        for (int val : row)
            std::cout << std::setw(4) << val;
        std::cout << '\n';
    }
    std::cout << '\n';
}

Matrix addAndMultiplyMatrix(const Matrix& A, const Matrix& B, int scalar) {
    int rows = A.size();
    int cols = A[0].size();
    Matrix C(rows, std::vector<int>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            C[i][j] = (A[i][j] + B[i][j]) * scalar;

    return C;
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : "3.37.1.txt";
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << filename << '\n';
        return 1;
    }

    int rows, cols;
    file >> rows >> cols;

    Matrix A = readMatrix(file, rows, cols);
    Matrix B = readMatrix(file, rows, cols);

    std::cout << "A:\n";
    printMatrix(A);

    std::cout << "B:\n";
    printMatrix(B);

    Matrix C = addAndMultiplyMatrix(A, B, 2);

    std::cout << "************************\n(A + B) * 2 =\n\n";
    printMatrix(C);

    return 0;
}
