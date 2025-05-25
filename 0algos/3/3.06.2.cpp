// 3.6.2. Oldja meg ugyanezt a feladatot dinamikus tömbre is!
//  Hol lesz eltérés? 

// ### ✅ 3.6.2. feladat: Dinamikus tömbös változat

// A C++11-es verzió **dinamikus tömböt** használ a statikus `int tomb[4]` helyett. A fő eltérések:

// | Rész                          | Statikus változat             | Dinamikus változat (`new`)        |
// | ----------------------------- | ----------------------------- | --------------------------------- |
// | Tömb deklarálása              | `int tomb[size];`             | `int* tomb = new int[size];`      |
// | Tömbre mutató érték (pointer) | `tomb`                        | `tomb`                            |
// | Cím lekérése                  | `&tomb` (tömb egészének címe) | `&tomb` (a pointer változó címe!) |
// | Felszabadítás szükséges?      | ❌ (automatikusan)             | ✅ `delete[] tomb;`                |

// ---

// ### 🧾 **C++11 megoldás (dinamikus tömbbel)**:


#include <iostream>
#include <iomanip>

int main() {
    const int size = 4;
    int* tomb = new int[size]; // dinamikus tömb

    // 1. Értékek bekérése
    for (int i = 0; i < size; ++i) {
        std::cout << "The " << i << ". value: ";
        std::cin >> tomb[i];
    }

    // 2. Felső csillagsor (keret)
    std::cout << std::setw(20) << " ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::string(12, '*');
    }
    std::cout << "\n";

    // 3. Értékek sor keretben
    std::cout << std::setw(20) << " ";
    for (int i = 0; i < size; ++i) {
        std::cout << "*" << std::setw(10) << tomb[i] << "*";
    }
    std::cout << "\n";

    // 4. Alsó csillagsor
    std::cout << std::setw(20) << " ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::string(12, '*');
    }
    std::cout << "\n";

    // 5. Indexek
    std::cout << std::setw(20) << "index: ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(13) << i;
    }
    std::cout << "\n";

    // 6. Címek
    std::cout << std::setw(20) << "address: ";
    for (int i = 0; i < size; ++i) {
        std::cout << std::left << std::setw(13) << static_cast<const void*>(&tomb[i]);
    }
    std::cout << "\n";

    // 7. Mutatóként és mutató változóként
    std::cout << std::setw(20) << "tomb: " << static_cast<const void*>(tomb) << "\n";
    std::cout << std::setw(20) << "&tomb: " << static_cast<const void*>(&tomb) << "\n";

    // 8. Méret
    std::cout << std::setw(20) << "tomb size: " << size << "\n";

    delete[] tomb; // ne felejtsd el!
    return 0;
}




// ### 🧠 Megjegyzés a különbségekről

// * `tomb` **statikus esetben** a teljes tömbre mutat, `&tomb` a tömbre mint objektumra (típus: `int(*)[4]`).
// * `tomb` **dinamikus esetben** csak egy `int*` mutató az első elemre, `&tomb` az a pointer változó címe (típus: `int**` ha értelmezzük).
// * A címek közötti különbséget nézd meg például a `static_cast<const void*>(...)` kiírásban.

 