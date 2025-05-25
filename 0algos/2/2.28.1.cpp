// 2.28. Többszörös indirekció
// 2.28.1. Írjon programot, amely a konzolos képernyőn szemléltet egy int*** 
// mutatót és az általa mutatott értékeket! Írja ki a jelenlévő változók 
// címét, értékét és hogy milyen alternatív módon lehet hivatkozni a 
// változókra! 

// 2.28.1.


#include <iostream>
#include <iomanip>
#include <cstdint>

int main() {
    int data = 42;
    int* pData = &data;
    int** ppData = &pData;
    int*** pppData = &ppData;

    // Kiírás formázottan
    std::cout << std::left;
    std::cout << std::setw(12) << "Address:"
              << std::setw(18) << reinterpret_cast<void*>(&pppData)
              << std::setw(18) << reinterpret_cast<void*>(&ppData)
              << std::setw(18) << reinterpret_cast<void*>(&pData)
              << reinterpret_cast<void*>(&data) << "\n";

    std::cout << std::setw(12) << ""
              << std::string(18 * 4, '-')
              << "\n";

    std::cout << std::setw(12) << "Value:"
              << std::setw(18) << reinterpret_cast<void*>(pppData)
              << std::setw(18) << reinterpret_cast<void*>(ppData)
              << std::setw(18) << reinterpret_cast<void*>(pData)
              << data << "\n";

    std::cout << std::setw(12) << ""
              << std::string(18 * 4, '-')
              << "\n";

    std::cout << std::setw(12) << "Variable:"
              << std::setw(18) << "pppData"
              << std::setw(18) << "ppData"
              << std::setw(18) << "pData"
              << "data" << "\n";

    std::cout << std::setw(12) << ""
              << std::setw(18) << ""
              << std::setw(18) << "*pppData"
              << std::setw(18) << "*ppData"
              << "*pData" << "\n";

    std::cout << std::setw(12) << ""
              << std::setw(18) << ""
              << std::setw(18) << ""
              << std::setw(18) << "**pppData"
              << "**ppData" << "\n";

    std::cout << std::setw(12) << ""
              << std::setw(18) << ""
              << std::setw(18) << ""
              << std::setw(18) << ""
              << "***pppData" << "\n";

    return 0;
}
