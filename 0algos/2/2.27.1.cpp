// 2.27. Két kulcsos hozzáférés

// 2.27.1. Írjon programot, amely egy titkos adatnak (változónak) a címét egy 
// mutatóba és egy egészbe kódolja úgy, hogy a mutató és az egész összege 
// a változó címét eredményezi! A program adja meg a két adatot két 
// embernek egyenként. Később kérje be a mutatót és az egészet és ha őket 
// összeadva visszakapjuk a változó címét, akkor írja ki a változó 
// értékét. 

// 2.27.1


#include <iostream>
#include <cstdint>  // uintptr_t

int main() {
    int data = 42;
    int code = 666;
    int temp;

    // Eredeti cím
    int* realAddress = &data;

    // Az 1. kulcs (pointer - code) eltárolva biztonságos módon
    uintptr_t firstKey = reinterpret_cast<uintptr_t>(realAddress) - code;

    std::cout << "The 1st key: " << reinterpret_cast<void*>(firstKey) << std::endl;

    std::cout << "Press 1 if the other person arrived: ";
    std::cin >> temp;

    std::cout << "The 2nd key: " << code << std::endl;

    // Nullázzuk az eredeti adatokat
    firstKey = 0;
    code = 0;

    // Kulcsok újra bekérése
    std::cout << "To retrieve the data provide the 1st key (as pointer): ";
    void* inputPtr;
    std::cin >> inputPtr;

    std::cout << "Provide the 2nd key: ";
    std::cin >> code;

    // Újra kiszámoljuk a címet
    uintptr_t tryAddressRaw = reinterpret_cast<uintptr_t>(inputPtr) + code;
    int* tryAddress = reinterpret_cast<int*>(tryAddressRaw);

    if (tryAddress == realAddress) {
        std::cout << "Access granted, the data is: " << *tryAddress << std::endl;
    } else {
        std::cout << "Access denied!" << std::endl;
    }

    return 0;
}
