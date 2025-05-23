 
// 3.39.  Mátrix szorzása vektorral

// 3.39.1. Írjon programot, amely megszoroz egy mátrixot egy vektorral! A 
// mátrixot és a vektort fájlból olvassa be és tárolja őket dinamikus 
// adatszerkezetekkel! Írja ki a képernyőre az eredeti mátrixot és vektort, 
// majd a szorzatvektort! A szorzatvektor annyi értéket tartalmaz, amennyi a 
// mátrix sorainak száma. Ha „P” a szorzatvektor, „A” a mátrix, és 
// „V” az eredeti vektor, akkor Pi = Sum(j=1…c, Aij*Vj), ahol Aij a mátrix 
// i-edik sorának j-edik oszlopában van, c a mátrix oszlopainak száma. Az 
// input fájl formátuma: Első sor: num1 num2 num1: a mátrix sorainak száma 
// num2: a mátrix oszlopainak száma, amely egyben az eredeti vektor elemeinek 
// száma is A következő num1 db sor a mátrix sorait tartalmazza, mindegyik 
// sorban num2 db érték található, szóköz karakterrel elválasztva. A 
// mátrix után num2 db szám következik, az eredeti vektor elemei. Példa 
// bemenet: 2 3 4 1 3 7 2 2 6 2 3 Kimenet: Matrix : 4 1 7 2 Vector : 6 3 2 2 3 
// ************************ Matrix * Vector =  

// 3.39.1

#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>

using Matrix = std::vector<std::vector<int>>;
using Vector = std::vector<int>;

void readMatrix(std::ifstream& in, Matrix& matrix, int rows, int cols) {
    matrix.resize(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            in >> matrix[i][j];
}

void readVector(std::ifstream& in, Vector& vec, int size) {
    vec.resize(size);
    for (int i = 0; i < size; ++i)
        in >> vec[i];
}

void printMatrix(const Matrix& matrix) {
    for (const auto& row : matrix) {
        for (int val : row)
            std::cout << std::setw(4) << val;
        std::cout << '\n';
    }
}

void printVector(const Vector& vec) {
    for (int val : vec)
        std::cout << std::setw(4) << val << '\n';
}

Vector multiply(const Matrix& mat, const Vector& vec) {
    Vector result(mat.size(), 0);
    for (size_t i = 0; i < mat.size(); ++i)
        for (size_t j = 0; j < vec.size(); ++j)
            result[i] += mat[i][j] * vec[j];
    return result;
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : "3.39.1.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Nem sikerült megnyitni a fájlt: " << filename << '\n';
        return 1;
    }

    int rows, cols;
    file >> rows >> cols;

    Matrix matrix;
    Vector vector;

    readMatrix(file, matrix, rows, cols);
    readVector(file, vector, cols);

    Vector result = multiply(matrix, vector);

    std::cout << "Matrix:\n";
    printMatrix(matrix);
    std::cout << "\nVector:\n";
    printVector(vector);
    std::cout << "\n************************\nMatrix * Vector = \n\n";
    printVector(result);

    return 0;
}
