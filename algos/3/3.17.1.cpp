// 3.17.1. Írjon programot két dinamikus mátrix összeszorzására! 
// Függvényben foglaljon helyet a mátrixoknak, amelyeket véletlen egészekkel 
// töltsön fel! Írjon függvényt a mátrixszorozásra, ellenőrizze, hogy a 
// mátrix mértek kompatibilisek-e, a függvény visszatérési értéke legyen 
// az új eredmény mátrix! Írassa ki az eredetei és az eredmény mátrixokat 
// függvényben, majd szabadítsa fel azokat! 
// 3.17.1.


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using Matrix = std::vector<std::vector<double>>;

Matrix allocMatrix(int rows, int cols) {
    return Matrix(rows, std::vector<double>(cols, 0.0));
}

void randMatrix(Matrix& mat, int min, int max) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (auto& row : mat)
        for (auto& val : row)
            val = std::rand() % (max - min + 1) + min;
}

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        std::cout << "[ ";
        for (double val : row)
            std::cout << std::setw(6) << val << " ";
        std::cout << "]\n";
    }
}

Matrix multMatrix(const Matrix& A, const Matrix& B) {
    int rowA = A.size();
    int colA = A[0].size();
    int rowB = B.size();
    int colB = B[0].size();

    if (colA != rowB) {
        std::cerr << "Matrix dimensions incompatible for multiplication!\n";
        return Matrix(); // üres mátrix
    }

    Matrix C = allocMatrix(rowA, colB);

    for (int i = 0; i < rowA; ++i) {
        for (int j = 0; j < colB; ++j) {
            double sum = 0.0;
            for (int k = 0; k < colA; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
    return C;
}

int main() {
    int rowA, colA, rowB, colB;

    std::cout << "Number of rows of matrix A: ";
    std::cin >> rowA;
    std::cout << "Number of columns of matrix A: ";
    std::cin >> colA;

    std::cout << "Number of rows of matrix B: ";
    std::cin >> rowB;
    std::cout << "Number of columns of matrix B: ";
    std::cin >> colB;

    Matrix A = allocMatrix(rowA, colA);
    Matrix B = allocMatrix(rowB, colB);

    randMatrix(A, 12, 16);
    randMatrix(B, -4, 5);

    std::cout << "Matrix A:\n";
    printMatrix(A);
    std::cout << "Matrix B:\n";
    printMatrix(B);

    Matrix C = multMatrix(A, B);

    if (!C.empty()) {
        std::cout << "Matrix A * B:\n";
        printMatrix(C);
    } else {
        std::cout << "No result due to dimension mismatch.\n";
    }

    return 0;
}
