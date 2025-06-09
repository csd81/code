// 3.26. Polinomok összeadása
// 3.26.1. Írjon programot, amely polinomokat ad össze! Olvasson be fájlból 
// két polinomot! Írja ki a képernyőre a két polinomot, illetve ezek 
// összegét! A polinomok tárolására használjon dinamikus tömböket és 
// struktúrákat. Az input fájl formátuma: Első sor: Number1 - az első 
// polinom foka Második sor: Number1 + 1 egész szám, az első polinom 
// együtthatói (az utolsó szám a konstans). Harmadik sor: Number2 - a második 
// polinom foka Negyedik sor: Number2 + 1 egész szám, a második polinom (az 
// utolsó szám a konstans). A számok egy-egy szóköz karakterrel vannak 
// elválasztva Példa bemenet: 5 -3 5 -4 0 4 2 4 5 4 5 -1 0 Kimenet: - 3x^5 + 
// 5x^4 - 4x^3 + 4x + 2 + 5x^4 + 4x^3 + 5x^2 - x = - 3x^5 + 10x^4 + 5x^2 + 3x + 2 
// 3.26.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cmath>

struct Polynomial {
    int degree;
    std::vector<int> coeffs; // coeffs[0] is highest degree term

    void read(std::ifstream& in) {
        in >> degree;
        coeffs.resize(degree + 1);
        for (int i = 0; i <= degree; ++i)
            in >> coeffs[i];
    }

    void print() const {
        bool firstTerm = true;
        for (int i = 0; i <= degree; ++i) {
            int exp = degree - i;
            int coeff = coeffs[i];
            if (coeff == 0) continue;

            if (!firstTerm) std::cout << (coeff > 0 ? " + " : " - ");
            else if (coeff < 0) std::cout << "-";

            if (std::abs(coeff) != 1 || exp == 0)
                std::cout << std::abs(coeff);
            else if (exp == 0 && std::abs(coeff) == 1)
                std::cout << "1";

            if (exp > 0) {
                std::cout << "x";
                if (exp > 1)
                    std::cout << "^" << exp;
            }

            firstTerm = false;
        }
        if (firstTerm) std::cout << "0"; // if all coefficients were 0
    }
};

Polynomial add(const Polynomial& A, const Polynomial& B) {
    int maxDegree = std::max(A.degree, B.degree);
    int minDegree = std::min(A.degree, B.degree);

    Polynomial result;
    result.degree = maxDegree;
    result.coeffs.resize(maxDegree + 1, 0);

    int offsetA = maxDegree - A.degree;
    int offsetB = maxDegree - B.degree;

    for (int i = 0; i <= A.degree; ++i)
        result.coeffs[i + offsetA] += A.coeffs[i];
    for (int i = 0; i <= B.degree; ++i)
        result.coeffs[i + offsetB] += B.coeffs[i];

    // Trim leading zeros
    while (result.degree > 0 && result.coeffs[0] == 0) {
        result.coeffs.erase(result.coeffs.begin());
        result.degree--;
    }

    return result;
}

int main(int argc, char* argv[]) {
    const std::string filename = (argc > 1) ? argv[1] : "polynoms.txt";
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Error opening file: " << filename << "\n";
        return 1;
    }

    Polynomial A, B;
    A.read(in);
    B.read(in);

    std::cout << "First polynomial: ";
    A.print();
    std::cout << "\nSecond polynomial: ";
    B.print();

    Polynomial C = add(A, B);
    std::cout << "\nSum: ";
    C.print();
    std::cout << "\n";

    return 0;
}
