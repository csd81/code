// 2.28.2. Írjon programot, amely a konzolos képernyőn szemléltet egy 2*3 
// dinamikus double tömböt! 
// 2.28.2


#include <iostream>
#include <iomanip>

int main() {
    // Dinamikus 2×3-as mátrix
    double** myMatrix = new double*[2];
    for (int i = 0; i < 2; ++i) {
        myMatrix[i] = new double[3];
    }

    // Feltöltés
    int temp = 0;
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 3; ++j)
            myMatrix[i][j] = ++temp;

    // Címek
    std::cout << "**** Addresses ****\n";
    std::cout << "myMatrix:             " << reinterpret_cast<void*>(&myMatrix)
              << "  -> rows: [" << reinterpret_cast<void*>(myMatrix[0]) 
              << ", " << reinterpret_cast<void*>(myMatrix[1]) << "]\n";

    std::cout << "myMatrix[0] pointer:  " << reinterpret_cast<void*>(&myMatrix[0])
              << "  -> elements: [" 
              << reinterpret_cast<void*>(&myMatrix[0][0]) << ", "
              << reinterpret_cast<void*>(&myMatrix[0][1]) << ", "
              << reinterpret_cast<void*>(&myMatrix[0][2]) << "]\n";

    std::cout << "myMatrix[1] pointer:  " << reinterpret_cast<void*>(&myMatrix[1])
              << "  -> elements: [" 
              << reinterpret_cast<void*>(&myMatrix[1][0]) << ", "
              << reinterpret_cast<void*>(&myMatrix[1][1]) << ", "
              << reinterpret_cast<void*>(&myMatrix[1][2]) << "]\n\n";

    // Értékek és azok címei
    std::cout << "*** Values ***\n";
    std::cout << "Row pointers:         [" 
              << reinterpret_cast<void*>(myMatrix[0]) << ", "
              << reinterpret_cast<void*>(myMatrix[1]) << "]\n";

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Row 0 values @ " << reinterpret_cast<void*>(myMatrix[0])
              << ": [" << myMatrix[0][0] << ", "
              << myMatrix[0][1] << ", "
              << myMatrix[0][2] << "]\n";

    std::cout << "Row 1 values @ " << reinterpret_cast<void*>(myMatrix[1])
              << ": [" << myMatrix[1][0] << ", "
              << myMatrix[1][1] << ", "
              << myMatrix[1][2] << "]\n";

    // Felszabadítás
    for (int i = 0; i < 2; ++i) {
        delete[] myMatrix[i];
    }
    delete[] myMatrix;

    return 0;
}
