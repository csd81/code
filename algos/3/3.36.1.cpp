// 3.36. Inverz mátrix
// 3.36.1. Írjon programot, amely kiszámítja egy 3x3-as mátrix inverzét! A 
// program írja ki a képernyőre a mátrix adjungáltját, determinánst és az 
// inverz mátrixot. Az inverz mátrixot a következőképpen számíthatjuk ki: 
// A-1 = adj(A) / det(A), ahol adj(A) az A mátrix adjungáltja, és det(A) az A 
// mátrix determinánsa. Ha det(A) = 0, akkor A nem invertálható. = Ábra: 
// Mátrix elemeinek az indexelése Determináns: A 2x2-es mátrix determinánsa a 
// következő: a11*a22 - a21*a12 A 3x3-as mátrix determinánsa: a11 * a22 * a33 
// + a12 * a23 * a31 + a13 * a21 * a32 - a13 * a22 * a31 - a12 * a21 * a33 - a11 * 
// a23 * a32 Adjungált: A A ⎛ A adj( ) = ⎜- ⎜ A A + ⎝ A + ahol A A A A 
// A A A A A + A A - A - = det A A A A A A A A A - A A + A + A A A A A A ⎞ 
// ⎟ ⎟ ⎠ ;
// Példa bemenet: Original matrix: 1 2 3 2 4 5 3 5 6 Adjugate matrix: -1 3 -2 3 
// -3 1 -2 1 0 Determinant of the matrix: -1 Inverse matrix: 1 -3 2 -3 3 -1 2 -1 
// -0 

// 3.36.1.


#include <iostream>
#include <array>
#include <iomanip>

constexpr int SIZE = 3;
using Matrix = std::array<std::array<double, SIZE>, SIZE>;

// Mátrix kiírás
void printMatrix(const Matrix& m) {
    std::cout << '\n';
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            std::cout << std::setw(6) << m[i][j] << ' ';
        std::cout << '\n';
    }
    std::cout << '\n';
}

// 3x3 determináns számítása
double getDeterminant(const Matrix& m) {
    return  m[0][0] * m[1][1] * m[2][2]
          + m[0][1] * m[1][2] * m[2][0]
          + m[0][2] * m[1][0] * m[2][1]
          - m[0][2] * m[1][1] * m[2][0]
          - m[0][1] * m[1][0] * m[2][2]
          - m[0][0] * m[1][2] * m[2][1];
}

// Kofaktor egy (i, j) helyen
double getMinor(const Matrix& m, int row, int col) {
    std::array<double, 4> vals;
    int idx = 0;
    for (int i = 0; i < SIZE; ++i) {
        if (i == row) continue;
        for (int j = 0; j < SIZE; ++j) {
            if (j == col) continue;
            vals[idx++] = m[i][j];
        }
    }
    return vals[0]*vals[3] - vals[1]*vals[2];
}

// Adjungált mátrix (transzponált kofaktor mátrix)
Matrix makeAdjugate(const Matrix& m) {
    Matrix adj;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            double minor = getMinor(m, i, j);
            adj[j][i] = ((i + j) % 2 == 0 ? 1 : -1) * minor; // transzponált
        }
    }
    return adj;
}

// Inverz mátrix
bool invertMatrix(const Matrix& m, Matrix& inverse) {
    double det = getDeterminant(m);
    std::cout << "Determinant of the matrix: " << det << '\n';

    if (det == 0.0) {
        std::cout << "We cannot invert this matrix!\n";
        return false;
    }

    Matrix adj = makeAdjugate(m);

    std::cout << "Adjugate matrix:\n";
    printMatrix(adj);

    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            inverse[i][j] = adj[i][j] / det;

    return true;
}

int main() {
    Matrix matrix = {{
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    }};

    std::cout << "Original matrix:\n";
    printMatrix(matrix);

    Matrix inverse;
    if (invertMatrix(matrix, inverse)) {
        std::cout << "Inverse matrix:\n";
        printMatrix(inverse);
    }

    return 0;
}
