// 3.17.2. Készítse el az újraméretez függvényt, amely vagy levág a 
// mátrixból egy darabot, és/vagy a mátrix jobb oldalához illetve aljához 
// hozzáfűz egy új részt! Az új rész egységmátrix szerűen tartalmazzon 
// 0-kat és 1-ket, ha az új rész nem négyzet alakú, akkor az egyesek 
// fűrészfog szerűen helyezkedjenek el! 1 1 1 1 1 1 1 3.3. ábra: Téglalap 
// alakú egységmátrix 
// 3.17.2.

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using Matrix = std::vector<std::vector<double>>;

Matrix allocMatrix(int rows, int cols) {
    return Matrix(rows, std::vector<double>(cols));
}

void randMatrix(Matrix& mat, int min, int max) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (auto& row : mat)
        for (auto& val : row)
            val = std::rand() % (max - min + 1) + min;
}

void printMatrix(const Matrix& mat) {
    for (const auto& row : mat) {
        std::cout << "[ ";
        for (double val : row) {
            std::cout << std::setw(5) << val << " ";
        }
        std::cout << "]\n";
    }
}

Matrix generatePattern(int rows, int cols) {
    Matrix result(rows, std::vector<double>(cols, 0));
    for (int i = 0; i < rows && i < cols; ++i)
        result[i][i] = 1;

    // fűrészfog-szerű minta nem négyzetes esetben
    if (rows != cols) {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if ((i + j) % std::max(1, std::min(rows, cols)) == 0)
                    result[i][j] = 1;
    }
    return result;
}

Matrix cutAndResizeMatrix(const Matrix& original, int option) {
    int rows = original.size();
    int cols = original[0].size();
    int cutRows = 0, addCols = 0;

    if (option == 1 || option == 2) {
        std::cout << "How many rows would you like to delete? ";
        std::cin >> cutRows;
        if (cutRows >= rows) cutRows = rows - 1;
    }

    if (option == 1 || option == 3) {
        std::cout << "How many columns would you like to add? ";
        std::cin >> addCols;
    }

    int newRows = rows - cutRows;
    int newCols = cols + addCols;
    Matrix newMat = allocMatrix(newRows, newCols);

    // Copy old data
    for (int i = 0; i < newRows; ++i)
        for (int j = 0; j < cols; ++j)
            newMat[i][j] = original[i][j];

    // Generate pattern and fill extended part
    if (addCols > 0) {
        Matrix pattern = generatePattern(newRows, addCols);
        for (int i = 0; i < newRows; ++i)
            for (int j = 0; j < addCols; ++j)
                newMat[i][cols + j] = pattern[i][j];
    }

    return newMat;
}

int main() {
    int rows, cols;
    std::cout << "Number of rows: ";
    std::cin >> rows;
    std::cout << "Number of columns: ";
    std::cin >> cols;

    Matrix mat = allocMatrix(rows, cols);
    randMatrix(mat, 12, 16);

    std::cout << "\nOriginal matrix:\n";
    printMatrix(mat);

    std::cout << "\nResize options:\n"
              << "1. Cut rows and add columns\n"
              << "2. Cut rows only\n"
              << "3. Add columns only\n"
              << "Choose: ";
    int choice;
    std::cin >> choice;

    Matrix newMat = cutAndResizeMatrix(mat, choice);

    std::cout << "\nNew matrix:\n";
    printMatrix(newMat);

    return 0;
}
