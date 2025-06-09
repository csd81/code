// 2.1.1. Írjon programot, amely bekéri egy vizsga eredményének százalékos 
// értékét és kiírja, hogy sikeres volt-e a vizsga! A siker feltétele az 
// 50%-nál jobb teljesítmény. Ötlet: ügyeljen arra, hogy az 50% még bukást 
// jelent! 
// 2.1.1.
 
#include <iostream>
#include <iomanip>

int main() {
    double result;

    std::cout << "Enter exam result (in %): ";
    std::cin  >> result;

    if (!std::cin) {
        std::cerr << "Invalid input!\n";
        return 1;
    }

    // 50.0% is still a fail; must be >50.0 to pass
    if (result > 50.0) {
        std::cout << "Passed\n";
    } else {
        std::cout << "Failed\n";
    }

    return 0;
}
 // 2.1.2. Kérjen be pontszámot, amelynek -25 és 50 közé kell esnie! A vizsga 
// sikerességét csak akkor vizsgálja, ha a pontszám a helyes intervallumban 
// van! A siker feltétele a 25 pontnál jobb eredmény. 
// 2.1.2.

 
// 2.1.2. Kérjen be pontszámot, amely -25 és 50 közé kell essen!
// A vizsga sikeres, ha a pontszám > 25.

#include <iostream>
#include <limits>  // std::numeric_limits

int main() {
    float result;

    std::cout << "Add meg a pontszámot (-25 és 50 között): ";
    std::cin >> result;

    // Ellenőrizzük, hogy a bemenet valid és az intervallumban van-e
    if (std::cin.fail()) {
        std::cerr << "Hibás bemenet! Számot kellett volna megadni.\n";
        return 1;
    }

    if (result >= -25.0f && result <= 50.0f) {
        if (result > 25.0f) {
            std::cout << "A vizsga SIKERES.\n";
        } else {
            std::cout << "A vizsga SIKERTELEN.\n";
        }
    } else {
        std::cout << "A megadott pontszám kívül esik a megengedett tartományon!\n";
    }

    return 0;
}
// 2.2.1. A sakktábla elkészítéséhez csak printf függvényt használjon a 
// programban! Ötlet: minden sorhoz külön printf-t használjon! 
// 2.2.1.

// 2.2.1. Sakktábla kirajzolása kizárólag cout használatával, minden sor külön sorban

#include <iostream>

int main() {
    std::cout << "  |a |b |c |d |e |f |g |h |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 1|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 2|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 3|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 4|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 5|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 6|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 7|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";
    std::cout << " 8|  |  |  |  |  |  |  |  |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";

    return 0;
}
// 2.2.2. Az azonos sorok kiírásához használjon ciklust! 
// 2.2.2.


#include <iostream>

constexpr int SIZE = 8;

int main() {
    std::cout << "  |a |b |c |d |e |f |g |h |\n";
    std::cout << " -|--|--|--|--|--|--|--|--|\n";

    for (int id = 0; id < SIZE; ++id) {
        std::cout << " " << id + 1 << "|  |  |  |  |  |  |  |  |\n";
        std::cout << " -|--|--|--|--|--|--|--|--|\n";
    }

    return 0;
}
// 2.2.3. Egy adott sor kirajzolásához is használjon ciklust! Keresse meg egy 
// sor ismétlődő mintáját és az kerüljön a ciklus magjába! Figyeljen 
// különösen a fejlécek helyes megjelenítésére. 
// 2.2.3.

#include <iostream>

constexpr int SIZE = 8;

int main() {
    // Fejléc: oszlopbetűk
    std::cout << "  |";
    for (char col = 'a'; col < 'a' + SIZE; ++col) {
        std::cout << col << " |";
    }
    std::cout << "\n";

    // Fejléc alatti elválasztó
    std::cout << " -|";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "--|";
    }

    // Táblázat sorai
    for (int row = 0; row < SIZE; ++row) {
        std::cout << "\n " << row + 1 << "|";
        for (int col = 0; col < SIZE; ++col) {
            std::cout << "  |";
        }

        // Sor alatti elválasztó
        std::cout << "\n -|";
        for (int i = 0; i < SIZE; ++i) {
            std::cout << "--|";
        }
    }

    std::cout << "\n";
    return 0;
}
// 2.3. Terület és kerületszámítás
// 2.3.1. Írjon programot, amely bekéri egy téglalap két oldalának a 
// hosszát, és hogy területet vagy kerületet akar-e a felhasználó számolni! 
// A választástól függően számolja ki a területet vagy a kerületet! Az 
// oldal hosszak egész értékek, a választás karakter típusú. Ötlet: 
// ügyeljen arra, hogy negatív nagyságú oldal nincsen! 
// 2.3.1.

#include <iostream>

int main() {
    int a, b;
    char decision;

    std::cout << "Program to calculate the area or perimeter of a rectangle.\n";

    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;

    // Oldalak érvényességének ellenőrzése
    if (a <= 0 || b <= 0) {
        std::cerr << "Hibás bemenet! Az oldalaknak pozitív egész számoknak kell lenniük.\n";
        return 1;
    }

    std::cout << "Would you like to calculate area (a) or perimeter (p)? ";
    std::cin >> decision;

    if (decision == 'a') {
        std::cout << "The area of the rectangle is: " << (a * b) << "\n";
    } else if (decision == 'p') {
        std::cout << "The perimeter of the rectangle is: " << (2 * (a + b)) << "\n";
    } else {
        std::cerr << "Érvénytelen választás! Csak 'a' vagy 'p' lehet.\n";
        return 1;
    }

    return 0;
}
// 2.3.2. Módosítsa az előző programot úgy, hogy az oldalak hossza tört 
// érték is lehessen! A program elején kérje be, hogy négyzet vagy 
// téglalapot vizsgál-e és ennek függvényében kérjen be egy vagy két oldal 
// hosszat! 
// 2.3.2.


#include <iostream>
#include <limits>

int main() {
    char figure, property;
    double a = 0.0, b = 0.0;

    std::cout << "Program to calculate the area or perimeter of a rectangle or square.\n";
    std::cout << "Calculate rectangle (r) or square (s)? ";
    std::cin >> figure;

    if (figure == 'r') {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;

        if (a <= 0 || b <= 0) {
            std::cerr << "Side lengths must be positive.\n";
            return 1;
        }

        std::cout << "Would you like to calculate area (a) or perimeter (p)? ";
        std::cin >> property;

        if (property == 'a') {
            std::cout << "The area of the rectangle is: " << a * b << "\n";
        } else if (property == 'p') {
            std::cout << "The perimeter of the rectangle is: " << 2 * (a + b) << "\n";
        } else {
            std::cerr << "Invalid choice. Use 'a' for area or 'p' for perimeter.\n";
            return 1;
        }

    } else if (figure == 's') {
        std::cout << "a = ";
        std::cin >> a;

        if (a <= 0) {
            std::cerr << "Side length must be positive.\n";
            return 1;
        }

        std::cout << "Would you like to calculate area (a) or perimeter (p)? ";
        std::cin >> property;

        if (property == 'a') {
            std::cout << "The area of the square is: " << a * a << "\n";
        } else if (property == 'p') {
            std::cout << "The perimeter of the square is: " << 4 * a << "\n";
        } else {
            std::cerr << "Invalid choice. Use 'a' for area or 'p' for perimeter.\n";
            return 1;
        }

    } else {
        std::cerr << "Invalid shape selection. Use 'r' for rectangle or 's' for square.\n";
        return 1;
    }

    return 0;
}
// 2.3.3. Bővítse ki a programot úgy, hogy az oldalak hossza csak pozitív 
// érték lehet, síkidomválasztáskor a kis és a nagy betűket is fogadjuk el, 
// ha rossz választ adtunk, akkor az jelezzük, vegyük be a választható idomok 
// közé a szabályos háromszöget!
// 2.3.3.

#include <iostream>
#include <cmath>
#include <cctype>  // tolower

int main() {
    char figure, prop;
    double a = 0.0, b = 0.0;

    std::cout << "Program to calculate the area or perimeter of a rectangle, square or regular triangle.\n";
    std::cout << "Choose a shape - rectangle (r), square (s), triangle (t): ";
    std::cin >> figure;
    figure = std::tolower(figure);

    if (figure == 'r') {
        std::cout << "a = ";
        std::cin >> a;
        std::cout << "b = ";
        std::cin >> b;

        if (a <= 0 || b <= 0) {
            std::cerr << "Error: Side lengths must be positive.\n";
            return 1;
        }

        std::cout << "Calculate area (a) or perimeter (p)? ";
        std::cin >> prop;
        prop = std::tolower(prop);

        if (prop == 'a') {
            std::cout << "The area of the rectangle is: " << a * b << "\n";
        } else if (prop == 'p') {
            std::cout << "The perimeter of the rectangle is: " << 2 * (a + b) << "\n";
        } else {
            std::cerr << "Invalid calculation type. Use 'a' or 'p'.\n";
            return 1;
        }

    } else if (figure == 's') {
        std::cout << "a = ";
        std::cin >> a;

        if (a <= 0) {
            std::cerr << "Error: Side length must be positive.\n";
            return 1;
        }

        std::cout << "Calculate area (a) or perimeter (p)? ";
        std::cin >> prop;
        prop = std::tolower(prop);

        if (prop == 'a') {
            std::cout << "The area of the square is: " << a * a << "\n";
        } else if (prop == 'p') {
            std::cout << "The perimeter of the square is: " << 4 * a << "\n";
        } else {
            std::cerr << "Invalid calculation type. Use 'a' or 'p'.\n";
            return 1;
        }

    } else if (figure == 't') {
        std::cout << "a = ";
        std::cin >> a;

        if (a <= 0) {
            std::cerr << "Error: Side length must be positive.\n";
            return 1;
        }

        std::cout << "Calculate area (a) or perimeter (p)? ";
        std::cin >> prop;
        prop = std::tolower(prop);

        if (prop == 'a') {
            double area = (a * a * std::sqrt(3)) / 4;
            std::cout << "The area of the regular triangle is: " << area << "\n";
        } else if (prop == 'p') {
            std::cout << "The perimeter of the regular triangle is: " << 3 * a << "\n";
        } else {
            std::cerr << "Invalid calculation type. Use 'a' or 'p'.\n";
            return 1;
        }

    } else {
        std::cerr << "Invalid shape selection! Use 'r', 's', or 't'.\n";
        return 1;
    }

    return 0;
}
// 2.4. Számláló ciklus
// 2.4.1. Írjon programot, amely kiírja az egész számokat 0-tól 9-ig! 
// 2.4.1.

#include <iostream>

int main() {
    for (int idxI = 0; idxI < 10; ++idxI) {
        std::cout << "idxI is " << idxI << "\n";
    }
    return 0;
}
// 2.4.2. Módosítsa az előző programot úgy, hogy 40-től 60-ig fordított 
// sorrendben, a páros számokat írja ki! Az intervallum mindkét határát 
// írja ki!
// 2.4.2.

#include <iostream>

int main() {
    for (int idxI = 60; idxI >= 40; idxI -= 2) {
        std::cout << "idxI is " << idxI << "\n";
    }
    return 0;
}
// 2.5. Sebességmérés
// 2.5.1. Egymásba ágyazott ciklusok segítségével határozza meg, hogy hány 
// üres iteráció tesz ki egy másodpercet, ha a ciklusváltozó egész, illetve 
// ha lebegőpontos! Minden ciklus 1000 lépést tegyen meg! Hány egymásba 
// ágyazott ciklus kell, hogy a végrehajtási idő 5-10 másodperc legyen? 
// 2.5.1.

#include <iostream>
#include <chrono>

int main() {
    constexpr int size = 1000;

    // Egész típusú ciklusok
    auto start_int = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                // üres ciklus
            }
        }
    }
    auto end_int = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_int = end_int - start_int;

    std::cout << "Integer loop time: " << duration_int.count() << " seconds\n";

    // Lebegőpontos típusú ciklusok
    auto start_float = std::chrono::high_resolution_clock::now();
    for (float i = 0; i < size; ++i) {
        for (float j = 0; j < size; ++j) {
            for (float k = 0; k < size; ++k) {
                // üres ciklus
            }
        }
    }
    auto end_float = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_float = end_float - start_float;

    std::cout << "Floating-point loop time: " << duration_float.count() << " seconds\n";

    return 0;
}
// 2.5.2. Határozza meg az összeadás, szorzás, osztás, hatványozás 
// időigényét úgy, hogy az előző program legbelsejébe beírja a megfelelő 
// utasítást!
// 2.5.2.

#include <iostream>
#include <chrono>
#include <cmath>

int main() {
    constexpr int size = 1000;
    int a;
    int b = 2364;
    int c = 9754;

    // Összeadás mérése
    auto start_add = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = b + c;
            }
        }
    }
    auto end_add = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_add = end_add - start_add;
    std::cout << "Addition time: " << duration_add.count() << " seconds\n";


    // Szorzás mérése
    auto start_mul = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = b * c;
            }
        }
    }
    auto end_mul = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_mul = end_mul - start_mul;
    std::cout << "Multiplication time: " << duration_mul.count() << " seconds\n";


    // Osztás mérése
    auto start_div = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = b / c;
            }
        }
    }
    auto end_div = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_div = end_div - start_div;
    std::cout << "Division time: " << duration_div.count() << " seconds\n";


    // Hatványozás mérése
    auto start_pow = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < size; ++k) {
                a = std::pow(b, 2);  // vagy pow(b, c); de az drágább
            }
        }
    }
    auto end_pow = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration_pow = end_pow - start_pow;
    std::cout << "Exponentiation time (pow): " << duration_pow.count() << " seconds\n";

    return 0;
}
// 2.6. Adatbekérés

// 2.6.1. Írjon programot, amellyel bekéri egy ember adati közül a 
// következőket: azonosító szám - int, életkor - unsigned int, neme - char, 
// súlya - float, bankszámla egyenlege - double, neve - char[200]! A bekért 
// adatokat írja ki újból a képernyőre! A megadott és a kiírt érték mikor 
// különbözhet? Mutasson rá példát! 
// 2.6.1.

#include <iostream>
#include <string>
#include <limits>

int main() {
    int id;
    unsigned int age;
    char sex;
    float weight;
    double accountBalance;
    std::string name;

    std::cout << "id = ";
    std::cin >> id;

    std::cout << "age = ";
    std::cin >> age;

    // Input buffer ürítése enter után
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "sex = ";
    std::cin >> sex;

    std::cout << "weight = ";
    std::cin >> weight;

    std::cout << "account balance = ";
    std::cin >> accountBalance;

    // Input buffer ürítése enter után, a teljes név bekéréséhez
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "name = ";
    std::getline(std::cin, name);  // szóközöket is kezel

    // Kiírás
    std::cout << "\nYour data:\n";
    std::cout << "id = " << id << "\n";
    std::cout << "age = " << age << "\n";
    std::cout << "sex = " << sex << "\n";
    std::cout << "weight = " << weight << "\n";
    std::cout << "account balance = " << accountBalance << "\n";
    std::cout << "name = " << name << "\n";

    return 0;
}
// 2.6.2. Kérje be majd írassa ki egy autó tulajdonságait! A tulajdonságok a 
// következőek: márka - char[200], végsebesség - float, regisztrációs szám 
// - hexa, tömeg double, típus név - char[300], utas szám - int, műholdas 
// navigáció - char. 
// 2.6.2.


#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string marka;
    float vegsebesseg;
    int rendszam;
    double tomeg;
    std::string tipusnev;
    int utasszam;
    char muszNav;

    std::cout << "Adja meg az autó adatait:\n";

    std::cout << "Márka: ";
    std::getline(std::cin, marka);

    std::cout << "Végsebesség (km/h): ";
    std::cin >> vegsebesseg;

    std::cout << "Regisztrációs szám (hexadecimális számként): 0x";
    std::cin >> std::hex >> rendszam; // hex bemenet

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Tömeg (kg): ";
    std::cin >> tomeg;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Típusnév: ";
    std::getline(std::cin, tipusnev);

    std::cout << "Utasszám: ";
    std::cin >> utasszam;

    std::cout << "Műholdas navigáció van? (y/n): ";
    std::cin >> muszNav;

    // Kiírás
    std::cout << "\nMegadott autó adatai:\n";
    std::cout << "Márka: " << marka << "\n";
    std::cout << "Végsebesség: " << vegsebesseg << " km/h\n";
    std::cout << "Regisztrációs szám (decimálisan): " << std::dec << rendszam << "\n";
    std::cout << "Tömeg: " << tomeg << " kg\n";
    std::cout << "Típusnév: " << tipusnev << "\n";
    std::cout << "Utasszám: " << utasszam << "\n";
    std::cout << "Műholdas navigáció: " << ((muszNav == 'y' || muszNav == 'Y') ? "igen" : "nem") << "\n";

    return 0;
}
// 2.7. Blokkon belüli változók
// 2.7.1. Hozzon létre egy olyan main függvényt, amelyben 3 különböző 
// típusú, 'a' nevű változó szerepel! Az egyes változók típusai: const 
// float, char [200], unsigned long int. Ugyanolyan nevű változókat egy 
// függvényben belül úgy tud létrehozni, hogy a változó definiálások 
// különböző blokkokban vannak. Egy negyedik változóba kérje be, melyik 
// blokkba menjen be a program, írassa ki az ott lévő a változó értékét! 
// 2.7.1.


#include <iostream>
#include <string>

int main() {
    int direction;

    std::cout << "Choose a direction:\n";
    std::cout << "1 - const float\n";
    std::cout << "2 - char[200]\n";
    std::cout << "3 - unsigned long int\n";
    std::cout << "Your choice: ";
    std::cin >> direction;

    if (direction == 1) {
        const float a = 12.345f;
        std::cout << "a (const float) = " << a << std::endl;
    }

    if (direction == 2) {
        char a[200] = "test123";
        std::cout << "a (char[200]) = " << a << std::endl;
    }

    if (direction == 3) {
        unsigned long int a = 98765;
        std::cout << "a (unsigned long int) = " << a << std::endl;
    }

    if (direction < 1 || direction > 3) {
        std::cout << "The direction value is incorrect." << std::endl;
    }

    return 0;
}
// 2.8. Formázott kimenet
// 2.8.1. printf segítségével írja ki a következő sorokat, úgy hogy 
// változókban tárolja az egyes értékeket! A szóközt „_”-al jelöljük. 
// A kiírandó szöveg: _+12.45 _-234.1 +57967.2 +134567 
// 2.8.1.


#include <iostream>
#include <iomanip>

int main() {
    float a = 12.45f;
    float b = -234.1f;
    float c = 57967.2f;
    float d = 134567.0f;

    // %+7.2f → szélesség 7, 2 tizedes, mindig előjel
    std::cout << std::setw(7) << std::showpos << std::fixed << std::setprecision(2) << a << "\n";

    // %7.1f → szélesség 7, 1 tizedes, negatív miatt - ott van
    std::cout << std::setw(7) << std::noshowpos << std::fixed << std::setprecision(1) << b << "\n";

    // %+8.1f → szélesség 8, 1 tizedes, mindig előjel
    std::cout << std::setw(8) << std::showpos << std::fixed << std::setprecision(1) << c << "\n";

    // %+6.0f → szélesség 6, 0 tizedes, mindig előjel
    std::cout << std::setw(6) << std::showpos << std::fixed << std::setprecision(0) << d << "\n";

    return 0;
}
// 2.8.2. Az előző feladathoz hasonlóan írassuk ki a következő sorokat: _ 
// _+235 _-1.291E4 00026 0XAB2 1.64e-003 
// 2.8.2.


#include <iostream>
#include <iomanip>

int main() {
    int a = 235;
    int c = 26;
    int d = 2 * 1 + 11 * 16 + 10 * 16 * 16; // 0xAB2
    float b = -12910.0f;
    float e = 0.00164f;

    // %+6d → előjeles, 6 széles
    std::cout << std::setw(6) << std::showpos << a << std::endl;

    // %12.3E → 12 széles, 3 tizedesjegy, nagy E
    std::cout << std::setw(12) << std::uppercase << std::scientific << std::setprecision(3) << b << std::endl;

    // %05d → 5 karakter, nullával feltöltve
    std::cout << std::setfill('0') << std::setw(5) << std::noshowpos << std::dec << c << std::endl;

    // %#X → hexadecimális nagybetűkkel, 0X prefix
    std::cout << std::uppercase << std::showbase << std::hex << d << std::endl;

    // %.2e → kis e, 2 tizedesjegy
    std::cout << std::defaultfloat << std::setprecision(2) << std::scientific << std::nouppercase << e << std::endl;

    return 0;
}
// 2.9. Hagyományos vagy normál forma
// 2.9.1. Írjon programot, amely öt darab tömbben tárolt float típusú 
// számról kérdezi meg, hogy azt a printf %g-el történő kiírásakor 
// hagyományos (f) vagy normál (e) alakban jeleníti meg! A számot jelenítsük 
// meg először %f-el! Írjuk ki a felhasználónak, hogy tippeljen, jelenítsük 
// meg a választ %g-el, kérdezzük meg, hogy helyes volt-e a tipp! Számoljuk a 
// helyes válaszokat! 
// 2.9.1.


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>  // sprintf
#include <limits>  // std::numeric_limits

int main() {
    const int size = 5;
    double array[] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
    int points = 0;

    std::cout << "How do you think %%g will display the next numbers?\n";
    std::cout << "(f = fixed, e = exponential)\n";

    for (int i = 0; i < size; ++i) {
        // 1. Szám kiírás %f formában (tíz tizedesjeggyel)
        std::cout << "\n" << std::fixed << std::setprecision(10) << array[i] << "\n";

        // 2. Tipp bekérése
        std::cout << "Your guess (f/e): ";
        char guess;
        std::cin >> guess;
        guess = std::tolower(guess);

        // 3. %g formátum előállítása sprintf-fel
        char buffer[50];
        std::sprintf(buffer, "%g", array[i]);

        std::cout << "Actual output with %%g: " << buffer << "\n";

        // 4. Ellenőrzés: van-e 'e' vagy 'E' a bufferben
        bool isExponential = false;
        for (int j = 0; buffer[j] != '\0'; ++j) {
            if (buffer[j] == 'e' || buffer[j] == 'E') {
                isExponential = true;
                break;
            }
        }

        char actual = isExponential ? 'e' : 'f';

        // 5. Tipp ellenőrzése
        std::cout << "Was your selection correct? (y/n): ";
        char confirm;
        std::cin >> confirm;

        if (std::tolower(confirm) == 'y') {
            if (guess == actual) {
                ++points;
            }
        }

        // Bemenet ürítése a következő iteráció előtt
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nYou have " << points << " out of " << size << " correct.\n";

    return 0;
}
// 2.9.2. Alakítsuk át a programot úgy, hogy ne a tipp helyességét kérjük 
// be, hanem magát a tippet! Használjunk sprintf parancsot és használjuk ki 
// azt, hogy normál forma mindig tartalmaz egy 'e' betűt. A program elején 
// kérjük be a tömb nagyságát, a program végén, %-ban adjuk meg a helyes 
// megoldások számát! 
// 2.9.2.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>  // sprintf

int main() {
    int size;
    std::cout << "Enter the number of values: ";
    std::cin >> size;

    std::vector<double> myArray(size);
    std::cout << "Enter " << size << " double values:\n";
    for (int i = 0; i < size; ++i) {
        std::cin >> myArray[i];
    }

    int points = 0;
    std::cout << "How do you think the %g will display the next numbers? Use 'e' for scientific and 'f' for normal form.\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "\n" << std::setw(15) << std::setprecision(10) << std::fixed << myArray[i] << "\n";

        // Formázzuk sprintf-fel
        char buffer[50];
        std::sprintf(buffer, "%g", myArray[i]);

        std::cout << "Your guess? (e / f): ";
        char choice;
        std::cin >> choice;

        // Ellenőrizzük, van-e 'e' a sprintf által generált stringben
        char correctChoice = 'f';
        for (int j = 0; buffer[j] != '\0'; ++j) {
            if (buffer[j] == 'e' || buffer[j] == 'E') {
                correctChoice = 'e';
                break;
            }
        }

        std::cout << "Formatted with %g: " << buffer << "\n";

        if (choice == correctChoice) {
            std::cout << "Correct!\n";
            ++points;
        } else {
            std::cout << "Incorrect!\n";
        }
    }

    double percentage = static_cast<double>(points) / size * 100.0;
    std::cout << "You achieved a(n) " << std::fixed << std::setprecision(0) << percentage << "% result.\n";

    return 0;
}
// 2.9.3. Alakítsuk át a programot úgy, hogy minden iterációban kérje be a 
// %g-ben használt pontosságot is! A válasz ne csak az legyen, hogy 
// hagyományos vagy normál formában történik a kiírás, hanem pontosan meg 
// kell adni számot a megfelelő formában! 
// 2.9.3.

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>  // sprintf
#include <cstring> // strcmp

int main() {
    const int size = 5;
    double myArray[size] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
    int points = 0;

    std::cout << "How do you think the %g will display the next numbers? Type it exactly!\n";

    for (int i = 0; i < size; ++i) {
        std::cout << "\n" << std::setw(15) << std::setprecision(10) << std::fixed << myArray[i] << "\n";
        
        int precision;
        std::cout << "How long should the %g precision be? ";
        std::cin >> precision;

        // Formázott sztring létrehozása a %g alapján
        char buffer[50];
        int strLength = std::sprintf(buffer, "%.*g", precision, myArray[i]);

        std::string tip;
        std::cout << "Your tip: ";
        std::cin >> tip;

        std::string correctAnswer(buffer);

        std::cout << "Formatted output with %g: " << correctAnswer << "\n";

        if (tip == correctAnswer) {
            std::cout << "Correct!\n";
            ++points;
        } else {
            std::cout << "Incorrect!\n";
        }
    }

    double percentage = static_cast<double>(points) / size * 100.0;
    std::cout << "You achieved a(n) " << std::fixed << std::setprecision(0) << percentage << " % result.\n";

    return 0;
}
// 2.10. Szorzótábla

// 2.10.1. Készítsünk 5*5-ös egyedi szorzótáblát, amelyet a karakteres 
// képernyőn jelenítünk meg! Az első sor és oszlop értékeit, amelyek 
// mutatják, hogy mit mivel kell összeszorozni, vonalakkal különítsük el a 
// szorzatoktól! Az első sor és az első oszlop értékeit a billentyűzetről 
// kérjük be! 



#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    const int SIZE = 5;
    double top[SIZE], side[SIZE];

    // Read the values for the top (first row) headers
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value for top[" << i << "]: ";
        cin >> top[i];
    }

    // Read the values for the side (first column) headers
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter value for side[" << i << "]: ";
        cin >> side[i];
    }

    cout << "\nCustom 5 x 5 multiplication table:\n\n";

    // Print the top header row
    // First cell is blank
    cout << setw(10) << " " << "|";
    for (int j = 0; j < SIZE; j++) {
        cout << setw(10) << fixed << setprecision(4) << top[j] << "|";
    }
    cout << "\n";

    // Separator line
    int totalWidth = 10 + 1 + SIZE * (10 + 1);
    for (int k = 0; k < totalWidth; k++) {
        cout << "-";
    }
    cout << "\n";

    // Print each row: side header, then the products
    for (int i = 0; i < SIZE; i++) {
        // Side header
        cout << setw(10) << fixed << setprecision(4) << side[i] << "|";
        // Products
        for (int j = 0; j < SIZE; j++) {
            cout << setw(10) << fixed << setprecision(4)
                 << side[i] * top[j] << "|";
        }
        cout << "\n";
    }

    return 0;
}




// 2.10.2. A szorzótáblához hasonló módon valósítsuk meg az egyedi 
// összeadó táblát! Az első sor és az első oszlop értékeit szöveg 
// fájlból olvassuk be! 


#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>
#include <cstdint>

int main() {
    const int16_t MIN16 = std::numeric_limits<int16_t>::min();  // –32768
    const int16_t MAX16 = std::numeric_limits<int16_t>::max();  // +32767
    const int COLUMN_WIDTH = 12;

    std::ifstream infile("headers.txt");
    if (!infile) {
        std::cerr << "Error: could not open headers.txt\n";
        return 1;
    }

    // Read row- and column- headers
    std::vector<int> rows, cols;
    int x;
    // first line → rows
    for (std::string line; std::getline(infile, line); ) {
        std::istringstream iss(line);
        if (rows.empty()) {
            while (iss >> x) rows.push_back(x);
        } else {
            while (iss >> x) cols.push_back(x);
            break;  // we only expect two lines
        }
    }
    infile.close();

    if (rows.empty() || cols.empty()) {
        std::cerr << "Error: input file must have two lines of integers\n";
        return 1;
    }

    // Print header row
    std::cout << std::setw(COLUMN_WIDTH) << " " << "|";
    for (int r : rows) {
        std::cout << std::setw(COLUMN_WIDTH) << r << "|";
    }
    std::cout << "\n";

    // Separator
    int totalWidth = COLUMN_WIDTH + 1 + int(rows.size()) * (COLUMN_WIDTH + 1);
    for (int i = 0; i < totalWidth; ++i) std::cout << "-";
    std::cout << "\n";

    // Each data row
    for (int c : cols) {
        std::cout << std::setw(COLUMN_WIDTH) << c << "|";
        for (int r : rows) {
            int sum = r + c;
            // Detect 16-bit signed overflow:
            bool overflow = ( (r > 0 && c > 0 && sum < 0)
                           || (r < 0 && c < 0 && sum > 0)
                           || sum < MIN16 || sum > MAX16 );
            if (overflow) {
                std::cout << std::setw(COLUMN_WIDTH) << "x" << "|";
            } else {
                std::cout << std::setw(COLUMN_WIDTH) << sum << "|";
            }
        }
        std::cout << "\n";
    }

    return 0;
}
 // 2.11.1. Írjon programot a másodfokú egyenlet megoldására! Először 
// kérje be az együtthatókat, azután írja ki, hogy hány megoldás van és 
// adja meg a megoldásokat! 



#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double a, b, c;
    
    cout << "Solve quadratic equation a*x^2 + b*x + c = 0\n\n";
    cout << "Enter coefficient a: ";
    cin  >> a;
    cout << "Enter coefficient b: ";
    cin  >> b;
    cout << "Enter coefficient c: ";
    cin  >> c;

    // Handle degenerate case a == 0 → linear or no equation
    if (a == 0.0) {
        if (b == 0.0) {
            if (c == 0.0) {
                cout << "\nInfinite solutions (0 = 0).\n";
            } else {
                cout << "\nNo solution (inconsistent equation).\n";
            }
        } else {
            // bx + c = 0 → x = –c/b
            double x = -c / b;
            cout << "\nLinear equation, one solution:\n";
            cout << "x = " << fixed << setprecision(4) << x << "\n";
        }
        return 0;
    }

    double D = b*b - 4.0*a*c;

    cout << "\nDiscriminant D = " << fixed << setprecision(4) << D << "\n";

    if (D > 0.0) {
        double sqrtD = sqrt(D);
        double x1 = (-b + sqrtD) / (2.0 * a);
        double x2 = (-b - sqrtD) / (2.0 * a);
        cout << "There are 2 real solutions:\n";
        cout << "x1 = " << fixed << setprecision(4) << x1 << "\n";
        cout << "x2 = " << fixed << setprecision(4) << x2 << "\n";
    }
    else if (D == 0.0) {
        double x = -b / (2.0 * a);
        cout << "There is 1 real solution:\n";
        cout << "x = " << fixed << setprecision(4) << x << "\n";
    }
    else {
        cout << "There are no real solutions (D < 0).\n";
    }

    return 0;
}
 
// 2.11.2. Határozza meg a komplex gyököket is! A komplex gyököket is 
// figyelembe véve a másodfokú egyenletnek mindig két megoldása van, de azok 
// egybeeshetnek. 
// 2.11.2.

 
#include <iostream>
#include <complex>
#include <iomanip>

int main() {
    double a, b, c;
    std::cout << "Solve a*x^2 + b*x + c = 0 (complex roots allowed)\n\n";
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "c = "; std::cin >> c;

    // Ensure it's really quadratic
    if (a == 0.0) {
        std::cerr << "Coefficient a must be non-zero for a quadratic equation.\n";
        return 1;
    }

    // Compute discriminant as a complex number
    std::complex<double> D = std::complex<double>(b*b - 4.0*a*c, 0.0);
    auto sqrtD = std::sqrt(D);

    // Two roots
    std::complex<double> x1 = (-b + sqrtD) / (2.0 * a);
    std::complex<double> x2 = (-b - sqrtD) / (2.0 * a);

    // Print with 4 decimal places
    auto print_root = [&](const std::complex<double>& x, const char* name) {
        double re = x.real();
        double im = x.imag();
        std::cout << name << " = "
                  << std::fixed << std::setprecision(4)
                  << re;
        if (im >= 0)
            std::cout << "+" << im << "i\n";
        else
            std::cout << im << "i\n";
    };

    std::cout << "\nThe two solutions are:\n";
    print_root(x1, "x1");
    print_root(x2, "x2");

    return 0;
}
 // 2.12.2. Írjon programot a logikai és bitenkénti operátorok használatának 
// a szemléltetésére! 


#include <iostream>
#include <limits>

int main() {
    int op1, op2;
    char more = 'y';

    std::cout << "Demonstrate logical and bitwise operators on two integers\n\n";

    while (more == 'y' || more == 'Y') {
        // Read first integer
        std::cout << "Enter first integer (op1): ";
        while (!(std::cin >> op1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Read second integer
        std::cout << "Enter second integer (op2): ";
        while (!(std::cin >> op2)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter an integer: ";
        }

        // Bitwise operations
        std::cout << "\nBitwise operations:\n";
        std::cout << op1 << " &  " << op2 << "  = " << (op1 & op2) << "\n";
        std::cout << op1 << " |  " << op2 << "  = " << (op1 | op2) << "\n";
        std::cout << op1 << " ^  " << op2 << "  = " << (op1 ^ op2) << "\n";
        std::cout << "~"  << op1 << "       = " << (~op1) << "\n";
        std::cout << "~"  << op2 << "       = " << (~op2) << "\n";

        // Logical operations
        std::cout << "\nLogical operations (treating 0 as false, non-zero as true):\n";
        std::cout << op1 << " && " << op2 << " = " << ( (op1 && op2) ? 1 : 0 ) << "\n";
        std::cout << op1 << " || " << op2 << " = " << ( (op1 || op2) ? 1 : 0 ) << "\n";
        std::cout << "!"  << op1 << "       = " << ( (!op1) ? 1 : 0 ) << "\n";
        std::cout << "!"  << op2 << "       = " << ( (!op2) ? 1 : 0 ) << "\n";

        // Repeat?
        std::cout << "\nDo you want to try again? (y/n): ";
        std::cin >> more;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n";
    }

    std::cout << "Program terminated.\n";
    return 0;
}

// 2.13.1. Kérjen be egy előjel nélküli karakter típusú változót 
// egészként és írja ki a kettes számrendszerbeli alakját! 
// 2.13.1.

#include <iostream>
#include <bitset>

int main() {
    int input = 0;

    std::cout << "number = ";
    std::cin >> input;

    // Ellenőrizzük, hogy belefér-e az unsigned char tartományába (0–255)
    if (input < 0 || input > 255) {
        std::cerr << "Hibás érték! Csak 0 és 255 közötti számokat fogadunk el.\n";
        return 1;
    }

    unsigned char number = static_cast<unsigned char>(input);
    unsigned char delMask = 0x80;

    std::cout << "Its value in number system 2: ";

    for (int i = 0; i < 8; ++i) {
        unsigned char result = number & delMask;
        std::cout << (result ? 1 : 0);
        delMask >>= 1;
    }

    std::cout << '\n';
    return 0;
}
// 2.13.2. Kérjen be egy számot és az előző programmal írja ki a kettes 
// számrendszerbeli alakját! Kérjen be egy bit pozíciót és állítsa azt a 
// bitet egyesre! Írja ki az új értéket tízes és kettes számrendszerben is! 
// 2.13.2.

#include <iostream>
#include <bitset>
#include <cmath>     // csak akkor kell, ha pow-ot használnánk, de itt nem fogjuk

constexpr int SIZE = 8;

int main() {
    int input;
    std::cout << "Number = ";
    std::cin >> input;

    // Érvényességellenőrzés
    if (input < 0 || input > 255) {
        std::cerr << "Hibás érték! Csak 0 és 255 közötti számokat fogadunk el.\n";
        return 1;
    }

    unsigned char number = static_cast<unsigned char>(input);
    std::bitset<SIZE> bits(number);

    std::cout << "Its value in system 2: " << bits << "\n";

    // Bitpozíció bekérése
    int position;
    std::cout << "Please enter a position (1 = lowest bit): ";
    std::cin >> position;

    if (position < 1 || position > 8) {
        std::cerr << "Érvénytelen pozíció! Csak 1 és 8 között adhatsz meg pozíciót.\n";
        return 1;
    }

    // Beállítjuk a kívánt bitet 1-re (pozíció 1-től 8-ig, bitset indexe 0-tól)
    bits.set(position - 1, true);

    // Új érték meghatározása
    unsigned char newNumber = static_cast<unsigned char>(bits.to_ulong());

    // Új bináris és decimális érték kiírása
    std::cout << "Here comes the new number in system 2:  " << bits << "\n";
    std::cout << "Here comes the new number in system 10: " << static_cast<int>(newNumber) << "\n";

    return 0;
}
// 2.13.3. Folytassa az előző programot úgy, hogy bekér még két bit 
// pozíciót! Az elsőnél törölje a bitet a másodiknál negálja. Minden 
// részeredményt írjon ki a képernyőre! 
// 2.13.3.


#include <iostream>
#include <bitset>
#include <limits>

constexpr int SIZE = 8;

void printBinary(const std::string& label, std::bitset<SIZE> bits) {
    std::cout << label << ": " << bits << " (decimal: " << bits.to_ulong() << ")\n";
}

int main() {
    unsigned int input;
    std::cout << "Enter a number (0-255): ";
    std::cin >> input;

    if (input > 255) {
        std::cerr << "Invalid input. Must be 0–255.\n";
        return 1;
    }

    std::bitset<SIZE> bits(input);
    printBinary("Original", bits);

    // 1. Bekérjük a pozíciót, ahol 1-re állítjuk a bitet (1 = legalsó)
    int setPosition;
    std::cout << "Enter a bit position to SET to 1 (1-8): ";
    std::cin >> setPosition;

    if (setPosition < 1 || setPosition > 8) {
        std::cerr << "Invalid position.\n";
        return 1;
    }

    bits.set(setPosition - 1, true);
    printBinary("After SET", bits);

    // 2. Bekérjük a törlendő és negálandó bitek pozícióját
    int deletePos, negatePos;
    std::cout << "Enter two positions: first to DELETE, second to NEGATE (1-8): ";
    std::cin >> deletePos >> negatePos;

    if (deletePos < 1 || deletePos > 8 || negatePos < 1 || negatePos > 8) {
        std::cerr << "Invalid positions.\n";
        return 1;
    }

    // 3. Bit törlés: balra shifteljük az összes bitet a megadott pozíció felett
    std::bitset<SIZE> deletedBits;
    int j = SIZE - 1;
    for (int i = SIZE - 1; i >= 0; --i) {
        if (i == deletePos - 1) continue;  // kihagyjuk a törlendő bitet
        if (j >= 1) {
            deletedBits[j - 1] = bits[i];
            --j;
        }
    }
    printBinary("After DELETE", deletedBits);

    // 4. Bit negálás
    int negateIndex = negatePos - 1;
    if (negateIndex < 7) {
        deletedBits.flip(negateIndex);
    }
    printBinary("After DELETE + NEGATE", deletedBits);

    return 0;
}
// 2.14. Hatványsor
// 2.14.1. Írjunk programot, amely hatványsor és könyvtári függvény 
// segítségével is kiszámolja ex értékét a következő képlettel: = ! 
// Megfelelően pontos értéket kapunk, ha a sort a negyedik elemig határozzuk 
// meg. Írjuk ki a hatványsor és a valós érték közötti különbséget!
// 2.14.1.


#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double x;
    int length;

    std::cout << "The accuracy of power series calculating e^x\n";
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "Length of the power series = ";
    std::cin >> length;

    double powerSeries = 1.0;
    double factorial = 1.0;

    // Hatványsor számítás: 1 + x/1! + x^2/2! + ... + x^(n-1)/(n-1)!
    for (int i = 1; i < length; ++i) {
        factorial *= i;
        powerSeries += std::pow(x, i) / factorial;
    }

    double accurate = std::exp(x);
    double difference = std::fabs(accurate - powerSeries);

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Power series approximation: " << powerSeries << "\n";
    std::cout << "Library value (exp):        " << accurate << "\n";
    std::cout << "Difference:                 " << difference << "\n";

    return 0;
}
// 2.14.2. Kérjünk be egy pontosságot és határozzuk meg, hogy a sor hány 
// tagját kell figyelembe venni, az adott pontosság eléréséhez! 

#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double value;
    double accuracy;

    std::cout << "The accuracy of power series calculating e^x\n";
    std::cout << "x = ";
    std::cin >> value;

    std::cout << "How small should the accuracy (difference) be? ";
    std::cin >> accuracy;

    double result = 1.0;
    double factorial = 1.0;
    int length = 1;

    double accurateResult = std::exp(value);
    double difference = std::fabs(accurateResult - result);

    while (difference > accuracy) {
        factorial *= length;
        result += std::pow(value, length) / factorial;
        ++length;
        difference = std::fabs(accurateResult - result);
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "Power series value:  " << result << "\n";
    std::cout << "Actual exp(x):       " << accurateResult << "\n";
    std::cout << "Final difference:    " << difference << "\n";
    std::cout << "Terms needed:        " << length << "\n";

    return 0;
}
// 2.14.3. Határozzuk meg a sin(x)-t hatványsor segítségével! 


// Íme a **2.14.3. feladat** teljesen helyes és **C++11-re portolt változata**, amely:

// * A `sin(x)` értékét számolja ki **hatványsor (Taylor-sor)** alapján,
// * A sor képlete:

//   $$
//   \sin(x) = \sum_{n=0}^{\infty} \frac{(-1)^n \cdot x^{2n+1}}{(2n+1)!}
//   $$
// * Rekurzív `factorial` helyett **iteratív, túlcsordulásbiztosabb verziót** használ,
// * Tisztán kezeli a lebegőpontos műveleteket (`double`),
// * Tizedes pontosságot használ kiíráskor,
// * Összehasonlítja az eredményt a `std::sin` könyvtári értékkel is.
 
#include <iostream>
#include <cmath>
#include <iomanip>

// Iteratív faktoriál
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
        result *= i;
    return result;
}

int main() {
    double x;
    int length;

    std::cout << "The accuracy of sinus series calculating sin(x)\n";
    std::cout << "x = ";
    std::cin >> x;

    std::cout << "Length of the sinus series: ";
    std::cin >> length;

    double result = 0.0;

    for (int i = 0; i < length; ++i) {
        int exponent = 2 * i + 1;
        double term = std::pow(-1, i) * std::pow(x, exponent) / factorial(exponent);
        result += term;
    }

    std::cout << std::fixed << std::setprecision(10);
    std::cout << "sin(" << x << ") with series length " << length << ": " << result << "\n";
    std::cout << "std::sin(" << x << "): " << std::sin(x) << "\n";
    std::cout << "Difference: " << std::fabs(result - std::sin(x)) << "\n";

    return 0;
}
// 2.15. Típuskonverzió
// 2.15.1. Írjon programot, amely bekér egy double értéket kiírja az eredeti 
// értéket a float, int, short int, char típussá konvertált változatok 
// nagyságát és értékeit! A változók méretei jobbra legyenek rendezve és 
// az értékek kiírása azonos oszlopban kezdődjön! 

#include <iostream>
#include <iomanip>
#include <limits>

int main() {
    double doubleValue;

    std::cout << std::fixed << std::setprecision(20);
    std::cout << std::setw(20) << "doubleValue = ";
    std::cin >> doubleValue;

    float floatValue = static_cast<float>(doubleValue);
    int intValue = static_cast<int>(floatValue);
    short shortIntValue = static_cast<short>(intValue);
    char charValue = static_cast<char>(shortIntValue);

    std::cout << std::setw(20) << "size of double = " << std::setw(2) << sizeof(doubleValue)
              << "  doubleValue = " << std::setw(25) << doubleValue << "\n";

    std::cout << std::setw(20) << "size of float = " << std::setw(2) << sizeof(floatValue)
              << "  floatValue = " << std::setw(25) << floatValue << "\n";

    std::cout << std::setw(20) << "size of int = " << std::setw(2) << sizeof(intValue)
              << "  intValue = " << std::setw(25) << intValue << "\n";

    std::cout << std::setw(20) << "size of short int = " << std::setw(2) << sizeof(shortIntValue)
              << "  shortIntValue = " << std::setw(25) << shortIntValue << "\n";

    std::cout << std::setw(20) << "size of char = " << std::setw(2) << sizeof(charValue)
              << "  charValue = " << std::setw(25) << static_cast<int>(charValue) << "\n";

    return 0;
}

// 2.15.2. Határozza meg az eredeti és a konvertált értékek közötti 
// különbségeket! 

#include <iostream>
#include <iomanip>

int main() {
    double number;

    std::cout << "Mennyi legyen a szam? ";
    std::cin >> number;

    float floatVal = static_cast<float>(number);
    int intVal = static_cast<int>(number);
    short shortVal = static_cast<short>(number);
    char charVal = static_cast<char>(number);

    std::cout << std::fixed << std::setprecision(10);

    std::cout << "Double - float: " << number - floatVal << "\n";
    std::cout << "Double - int:   " << number - intVal << "\n";
    
    std::cout << std::setprecision(2); // csak a további kettőnél legyen 2 jegy
    std::cout << "Double - short: " << number - shortVal << "\n";
    std::cout << "Double - char:  " << number - static_cast<int>(charVal) << "\n";

    return 0;
}
// 2.16. DeMorgan
// 2.16.1. Írjon programot, amelyben egész változókat használ logikaiként! A 
// változók a következőek: a - van pénzem, b - van kedvem, c - nincs időm, d 
// - nagyon érdekel. Kérje be a változók értékeit és a következők 
// alapján döntse el, hogy megy-e nyaralni: ha van pénze, kedve és ideje, 
// akkor megy, ha az előzőek közül csak egyik igaz, de nagyon érdekli akkor 
// is megy. Írja át a feltételeket DeMorgan azonosságok segítségével! 

#include <iostream>

int main() {
    int gotMoney, gotMood, noTime, veryInterested;

    std::cout << "Type 1 for yes and 0 for no!\n";
    std::cout << "gotMoney = ";
    std::cin >> gotMoney;
    std::cout << "gotMood = ";
    std::cin >> gotMood;
    std::cout << "noTime = ";
    std::cin >> noTime;
    std::cout << "veryInterested = ";
    std::cin >> veryInterested;

    bool hasTime = !noTime;

    // Eredeti logika:
    bool goOriginal =
        (gotMoney && gotMood && hasTime) ||
        ((gotMoney + gotMood + hasTime == 1) && veryInterested);

    // DeMorgan-os forma:
    bool notGo = (!gotMoney || !gotMood || !hasTime) && !(veryInterested && (
        (gotMoney && !gotMood && !hasTime) ||
        (!gotMoney && gotMood && !hasTime) ||
        (!gotMoney && !gotMood && hasTime)
    ));
    bool goDeMorgan = !notGo;

    std::cout << "\n[Original logic] ";
    if (goOriginal)
        std::cout << "I will go on holiday!\n";
    else
        std::cout << "I will not go on holiday!\n";

    std::cout << "[DeMorgan logic] ";
    if (goDeMorgan)
        std::cout << "I will go on holiday!\n";
    else
        std::cout << "I will not go on holiday!\n";

    return 0;
}
// 2.16.2. Kérje be a következő változókat: a - esik az eső, b - jönnek 
// mások is, c - van szabadnapom. Ezen változók alapján határozzuk meg, hogy 
// mikor megy a felhasználó túrázni. A feltételek a következőek: akkor 
// megyek túrázni ha, nem esik az eső és van szabadnapom;
// akkor is túrázom, ha mások nem jönnek, de az eső esik. Írja át a 
// feltételeket De Morgan azonosságok segítségével! 

#include <iostream>

int main() {
    int isRaining, comeOthers, gotFreeTime;

    std::cout << "Type 1 for yes and 0 for no!\n";
    std::cout << "isRaining: ";
    std::cin >> isRaining;
    std::cout << "comeOthers: ";
    std::cin >> comeOthers;
    std::cout << "gotFreeTime: ";
    std::cin >> gotFreeTime;

    // Eredeti logikai forma:
    bool hikeOriginal = (!isRaining && gotFreeTime) || (isRaining && !comeOthers);

    // DeMorgan forma:
    // (!isRaining && gotFreeTime) → !(isRaining || !gotFreeTime)
    // (isRaining && !comeOthers) → !( !isRaining || comeOthers )
    bool hikeDeMorgan = !(isRaining || !gotFreeTime) || !( !isRaining || comeOthers );

    std::cout << "\n[Original logic] ";
    if (hikeOriginal)
        std::cout << "I'm going hiking!\n";
    else
        std::cout << "Perhaps next time.\n";

    std::cout << "[DeMorgan logic] ";
    if (hikeDeMorgan)
        std::cout << "I'm going hiking!\n";
    else
        std::cout << "Perhaps next time.\n";

    return 0;
}
// 2.17.1. Írjon programot, amely a víz hőmérséklete alapján megállapítja 
// annak halmazállapotát! 

#include <iostream>
#include <iomanip>

int main() {
    float temperature;

    std::cout << "Temperature of water (°C): ";
    std::cin >> temperature;

    if (temperature < 0.0f) {
        std::cout << "Solid water (ice)\n";
    } else if (temperature < 100.0f) {
        std::cout << "Liquid water\n";
    } else {
        std::cout << "Gaseous water (steam)\n";
    }

    return 0;
}
// 2.17.2. Alakítsa át a programot, hogy ne Celsius fokot, hanem Farenheit-t 
// kér be. Külön függvény végezze el a konvertálást! 
// 2.17.2.

#include <iostream>
#include <iomanip>

// Függvény: Fahrenheit → Celsius
float fahrenheitToCelsius(float fahrenheit) {
    return (fahrenheit - 32.0f) * 5.0f / 9.0f;
}

int main() {
    float fahrenheit;
    std::cout << "Temperature of water (in Fahrenheit): ";
    std::cin >> fahrenheit;

    float celsius = fahrenheitToCelsius(fahrenheit);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Converted to Celsius: " << celsius << " °C\n";

    if (celsius < 0.0f) {
        std::cout << "The water is solid now.\n";
    } else if (celsius > 100.0f) {
        std::cout << "The water is gaseous now.\n";
    } else {
        std::cout << "The water is liquid now.\n";
    }

    return 0;
}
// 2.18. Római számok
// 2.18.1. Írjon programot, amely megadja, hogy mik a római számjegyek (I, V, 
// L, C, D, M) arab megfelelői! Kérjen be egy római számjegyet, konvertálja 
// nagybetűre, ha szükséges és adja meg a szám értéket! 
// 2.18.1.

 
#include <iostream>
#include <cctype> // for std::toupper

int main() {
    char romanChar;

    std::cout << "Roman to Arabic number converter\n";
    std::cout << "Give me a Roman numeral character (I, V, X, L, C, D, M): ";
    std::cin >> romanChar;

    romanChar = std::toupper(romanChar);  // Kisbetűből nagybetű

    switch (romanChar) {
        case 'I':
            std::cout << "Arabic: 1\n";
            break;
        case 'V':
            std::cout << "Arabic: 5\n";
            break;
        case 'X':
            std::cout << "Arabic: 10\n";
            break;
        case 'L':
            std::cout << "Arabic: 50\n";
            break;
        case 'C':
            std::cout << "Arabic: 100\n";
            break;
        case 'D':
            std::cout << "Arabic: 500\n";
            break;
        case 'M':
            std::cout << "Arabic: 1000\n";
            break;
        default:
            std::cout << "Wrong character!\n";
            break;
    }

    return 0;
}
// 2.18.2. Ne csak egy darab számjegyet, hanem egy több karakterből álló 
// számot alakítson át! 
// 2.18.2.

#include <iostream>
#include <string>
#include <cctype> // for toupper

int romanCharToValue(char ch) {
    switch (ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToArabic(const std::string& roman) {
    int total = 0;
    int prev = 0;

    for (int i = roman.size() - 1; i >= 0; --i) {
        char ch = std::toupper(roman[i]);
        int value = romanCharToValue(ch);

        if (value < prev)
            total -= value;
        else
            total += value;

        prev = value;
    }

    return total;
}

int main() {
    std::string roman;

    std::cout << "Roman number: ";
    std::cin >> roman;

    int result = romanToArabic(roman);
    std::cout << "Arabic value: " << result << "\n";

    return 0;
}
// 2.18.3. Valósítsa meg a visszafele történő konverziót! 
// 2.18.3.


#include <iostream>
#include <string>
#include <vector>

std::string arabicToRoman(int number) {
    std::vector<std::pair<int, std::string>> romanMap = {
        {1000, "M"}, {900, "CM"},
        {500, "D"},  {400, "CD"},
        {100, "C"},  {90, "XC"},
        {50, "L"},   {40, "XL"},
        {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},
        {1, "I"}
    };

    std::string result;

    for (const auto& pair : romanMap) {
        while (number >= pair.first) {
            result += pair.second;
            number -= pair.first;
        }
    }

    return result;
}

int main() {
    int number;

    std::cout << "Arabic number (1–4999): ";
    std::cin >> number;

    if (number < 1 || number > 4999) {
        std::cerr << "Number out of range!\n";
        return 1;
    }

    std::string roman = arabicToRoman(number);
    std::cout << "Roman numeral: " << roman << "\n";

    return 0;
}
// 2.19. Háromszög
// 2.19.1. Rajzoljon ki a karakteres képernyőre egy derékszögű, egyenlő 
// szárú háromszöget csillagokból dupla for ciklus segítségével! 
// 2.19.1.


#include <iostream>

int main() {
    int size = 15;

    for (int i = 1; i <= size; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
// 2.19.2. Fordítsa el a háromszöget úgy, hogy a másik befogó kerüljön  alulra! 
// 2.19.2.

#include <iostream>

int main() {
    int size = 6;

    for (int i = 0; i < size; ++i) {
        for (int j = 1; j <= size; ++j) {
            if (j <= size - i - 1)
                std::cout << ' ';
            else
                std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}
// 2.20. Négyzet animáció
// 2.20.1. Készítsen a karakteres képernyőn videót egy leeső négyzetről! A 
// négyzet 3*3 csillagból álljon! Miután megjelenített egy képet, várjon 
// rövid ideig, törölje a képernyőt és jelenítse meg a következő képet 
// egy sorral lejjebb! Feltesszük, hogy a karakteres képernyő 80*25-ös. 
// 2.20.1.


#include <iostream>
#include <chrono>
#include <thread>

void clearScreen() {
    // Platformfüggetlen képernyőürítés (egyszerű, nem tökéletes)
    std::cout << std::string(50, '\n');
}

void drawSquareAt(int y) {
    clearScreen();

    // Üres sorok, amíg a négyzet "le nem ér"
    for (int i = 0; i < y; ++i) {
        std::cout << '\n';
    }

    // 3x3 csillagblokk
    for (int i = 0; i < 3; ++i) {
        std::cout << " ***\n";
    }
}

int main() {
    const int screenHeight = 25;
    const int squareHeight = 3;
    const int maxY = screenHeight - squareHeight;

    for (int y = 0; y <= maxY; ++y) {
        drawSquareAt(y);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }

    return 0;
}
// 2.20.2. Módosítsa úgy a programot, hogy amint a négyzet eltűnik alul, 
// felül jelenjen meg újból! 
// 2.20.2.

#include <iostream>
#include <thread>
#include <chrono>

void clearScreen() {
    // Linux, macOS esetén:
    std::system("clear");
    // Windows esetén cseréld erre: system("cls");
}

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void drawSquareAt(int y, int screenHeight = 25) {
    clearScreen();

    // Üres sorok a pozícióig
    for (int i = 0; i < y; ++i)
        std::cout << "\n";

    // Kirajzolás (maximum 3 sor)
    for (int i = 0; i < 3 && (y + i) < screenHeight; ++i)
        std::cout << "***\n";
}

int main() {
    const int screenHeight = 25;
    const int squareHeight = 3;

    int y = 0;

    while (true) {
        drawSquareAt(y, screenHeight);
        wait(1);

        y++;
        if (y > screenHeight - squareHeight)
            y = 0;  // visszaugrik felülre
    }

    return 0;
}
// 2.20.3. Módosítsa úgy a programot, hogy négyzet helyett háromszög 
// jelenjen meg, ami alulról pattanjon vissza! 
// 2.20.3.

#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

void clearScreen() {
    std::system("clear"); // Windows esetén: std::system("cls");
}

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void drawTriangleAt(int y) {
    // Előtte üres sorok
    for (int i = 0; i < y; ++i)
        std::cout << "\n";

    // Háromszög rajzolása (3 soros, középre zárt)
    for (int row = 0; row < 3; ++row) {
        // szóközök a csillagok előtt
        for (int s = 0; s < 2 - row; ++s)
            std::cout << ' ';
        // csillagok (2 * row + 1 darab)
        for (int star = 0; star < 2 * row + 1; ++star)
            std::cout << '*';
        std::cout << "\n";
    }
}

int main() {
    int position = 0;
    bool goingDown = true;
    const int screenHeight = 25;
    const int triangleHeight = 3;
    const int maxY = screenHeight - triangleHeight;

    while (true) {
        clearScreen();
        drawTriangleAt(position);
        wait(1);

        // irányváltás logika
        if (goingDown) {
            if (position >= maxY)
                goingDown = false;
            else
                position++;
        } else {
            if (position <= 0)
                goingDown = true;
            else
                position--;
        }
    }

    return 0;
}
// 2.20.4. Négyzet helyett téglalap mozogjon vízszintesen a szélekről visszapattanva! 
// 2.20.4.


#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

void clearScreen() {
    std::system("clear"); // Windows esetén: std::system("cls");
}

void wait(int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void drawRectangleAt(int x, int width = 5, int height = 3) {
    std::string space(x, ' ');
    std::string stars(width, '*');
    for (int i = 0; i < height; ++i)
        std::cout << space << stars << '\n';
}

int main() {
    const int screenWidth = 80;
    const int rectWidth = 5;
    const int maxX = screenWidth - rectWidth;
    int x = 0;
    bool movingRight = true;

    while (true) {
        clearScreen();
        drawRectangleAt(x);

        wait(1);

        if (movingRight) {
            if (x >= maxX)
                movingRight = false;
            else
                x++;
        } else {
            if (x <= 0)
                movingRight = true;
            else
                x--;
        }
    }

    return 0;
}
// 2.21. Legnagyobb közös osztó
// 2.21.1. Írjon programot, amely kiszámolja két szám legnagyobb közös 
// osztóját a következő algoritmus segítségével! ciklus amíg a két szám 
// nem egyenlő a nagyobb szám értékét csökkentsük a kisebb számmal 
// 2.21.1.

#include <iostream>

int main() {
    int x, y;

    std::cout << "Give me the first number: ";
    std::cin >> x;

    std::cout << "Give me the second number: ";
    std::cin >> y;

    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }

    std::cout << "The greatest common divisor: " << x << std::endl;

    return 0;
}

// 2.21.2. Módosítsa úgy a programot, hogy az három szám legnagyobb közös 
// osztóját számolja ki! 
// 2.21.2.


#include <iostream>

int biggest_denominator(int x, int y) {
    while (x != y) {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

int main() {
    int x, y, z;

    std::cout << "Give me the first number: ";
    std::cin >> x;

    std::cout << "Give me the second number: ";
    std::cin >> y;

    std::cout << "Give me the third number: ";
    std::cin >> z;

    // GCD(x, y, z) = GCD(GCD(x, y), z)
    int gcd_xy = biggest_denominator(x, y);
    int gcd_xyz = biggest_denominator(gcd_xy, z);

    std::cout << "The greatest common divisor: " << gcd_xyz << std::endl;

    return 0;
}
// 2.22. main paraméterek
// 2.22.1. Írjon programot, amely kiírja a program paramétereit fordított 
// sorrendben! 
// 2.22.1.


#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = argc - 1; i >= 0; --i) {
        std::cout << "The " << i << ". parameter is: " << argv[i] << std::endl;
    }
    return 0;
}
// 2.22.2. Írja át úgy a programot, hogy elől tesztelős ciklust használ és 
// a program nevét nem írja ki! 
// 2.22.2.


#include <iostream>

int main(int argc, char* argv[]) {
    int i = argc - 1;

    while (i >= 1) { // program neve (argv[0]) kihagyva
        std::cout << "The " << i << ". parameter is: " << argv[i] << std::endl;
        --i;
    }

    return 0;
}


// 2.23. continue, break
// 2.23.1. Írjon programot, amely osztást végez el egy hátul tesztelős 
// ciklusban! Használjon végtelen ciklust, amelyet majd break paranccsal fog 
// megszakítani! Kérje be a két változót! Ha az osztandó abszolút értéke 
// nagyobb, mint 100, akkor hiba üzenet után hajtsa végre a következő 
// iterációt! Ha az osztó értéke 0, akkor szakítsa meg a ciklust! Szintén 
// szakítsa meg a ciklust, ha már három osztást elvégzett! 
// 2.23.1.
 
#include <iostream>
#include <cmath>

int main() {
    int count = 0;
    float x, y;

    while (true) {
        std::cout << "x = ";
        std::cin >> x;
        std::cout << "y = ";
        std::cin >> y;

        if (std::fabs(x) > 100.0f) {
            std::cout << "x is too big!\n\n";
            continue;
        }

        if (y == 0.0f) {
            std::cout << "y equals 0!\n";
            break;
        }

        std::cout << x << " / " << y << " = " << (x / y) << "\n\n";

        count++;
        if (count == 3) {
            break;
        }
    }

    return 0;
}
// 2.24. Deriválás
// 2.24.1. Írjon függvényt és hozzá tartozó programot, amely a 3x3-2x2+6x-1 
// függvénynek megadja az 1., 2. vagy 3. deriváltjának az értékét egy adott 
// pontban! A függvény paraméterei: hányadik deriváltról van szó, milyen 
// pontban tekintjük a deriváltat. A függvény visszatérési értéke: a 
// derivált értéke. 
// 2.24.1.


#include <iostream>
#include <iomanip>

float deriv(int whichDerivate, float where) {
    float result;
    switch (whichDerivate) {
        case 1:
            result = 9 * where * where - 4 * where + 6;
            break;
        case 2:
            result = 18 * where - 4;
            break;
        case 3:
            result = 18;
            break;
        default:
            result = 0;
            std::cerr << "Invalid derivative order (" << whichDerivate << "). Only 1, 2, or 3 allowed.\n";
            break;
    }
    return result;
}

int main() {
    float where;

    std::cout << "Where do you want to calculate the derivative? ";
    std::cin >> where;

    for (int i = 1; i <= 4; ++i) {
        float value = deriv(i, where);
        std::cout << "The " << i << ". derivative of 3x^3 - 2x^2 + 6x - 1 at x = "
                  << std::fixed << std::setprecision(2) << where
                  << " is: " << value << '\n';
    }

    return 0;
}

// 2.24.2. A sin(x) függvénynek határozza meg az 1., 2. vagy 3. deriváltjának 
// az értékét egy adott pontban! Használja fel, hogy sin'(x) = cos(x), cos'(x) 
// = -sin(x). 
// 2.24.2.


// Itt a **2.24.2. feladat** modern és helyes **C++11-re portolt változata**, amely:

// ---

// ### ✅ Feladat:

// * A `sin(x)` függvény **n-edik deriváltját** számolja ki egy adott pontban.
// * A deriválások ciklikusan ismétlődnek:

//   $$
//   \begin{align*}
//   f^{(0)}(x) &= \sin(x) \\
//   f^{(1)}(x) &= \cos(x) \\
//   f^{(2)}(x) &= -\sin(x) \\
//   f^{(3)}(x) &= -\cos(x) \\
//   f^{(4)}(x) &= \sin(x) \quad\text{(és így tovább)}
//   \end{align*}
//   $$

// ---

// ### ✅ C++11 megoldás:

// ```cpp
#include <iostream>
#include <cmath>
#include <iomanip>

float deriv(int whichDerivate, float posX) {
    switch (whichDerivate % 4) {
        case 0: return std::sin(posX);
        case 1: return std::cos(posX);
        case 2: return -std::sin(posX);
        case 3: return -std::cos(posX);
        default: return 0; // Ez sosem történik meg
    }
}

int main() {
    float posX;
    int times;

    std::cout << "Where do you want to calculate the derivative of sin(x) (in radians): ";
    std::cin >> posX;

    std::cout << "How many derivatives do you want? ";
    std::cin >> times;

    std::cout << std::fixed << std::setprecision(6);

    for (int i = 1; i <= times; ++i) {
        float result = deriv(i, posX);
        std::cout << "The " << i << ". derivative of sin(x) at x = "
                  << posX << " is: " << result << std::endl;
    }

    return 0;
}
// 2.24.3. Tetszőleges negyed-fokú polinomnak határozza meg a deriváltját 
// adott pontban! Legyen a függvénynek egy harmadik paramétere, ahol jelezzük, 
// ha hiba történt, vagyis ha az első paraméter értéke helytelen, vagyis 
// négynél nagyobb! 
// 2.24.3.

#include <iostream>
#include <cmath>
#include <iomanip>

float deriv(int order, float x, float a4, float a3, float a2, float a1, float a0, bool& error) {
    error = false;

    switch (order) {
        case 1:
            return 4 * a4 * std::pow(x, 3) + 3 * a3 * std::pow(x, 2) + 2 * a2 * x + a1;
        case 2:
            return 12 * a4 * std::pow(x, 2) + 6 * a3 * x + 2 * a2;
        case 3:
            return 24 * a4 * x + 6 * a3;
        case 4:
            return 24 * a4;
        default:
            error = true;
            return 0.0f;
    }
}

int main() {
    float a4, a3, a2, a1, a0, x;
    int order;

    std::cout << "Enter the coefficients of the polynomial:\n";
    std::cout << "x^4: "; std::cin >> a4;
    std::cout << "x^3: "; std::cin >> a3;
    std::cout << "x^2: "; std::cin >> a2;
    std::cout << "x^1: "; std::cin >> a1;
    std::cout << "constant: "; std::cin >> a0;

    std::cout << "\nYou entered: ";
    bool printed = false;
    if (a4) { std::cout << a4 << "x^4 "; printed = true; }
    if (a3) { std::cout << (printed ? "+ " : "") << a3 << "x^3 "; printed = true; }
    if (a2) { std::cout << (printed ? "+ " : "") << a2 << "x^2 "; printed = true; }
    if (a1) { std::cout << (printed ? "+ " : "") << a1 << "x "; printed = true; }
    if (a0) { std::cout << (printed ? "+ " : "") << a0; }
    if (!printed) { std::cout << "0"; }
    std::cout << "\n";

    std::cout << "\nWhich derivative (1–4)? ";
    std::cin >> order;

    std::cout << "Where do you want to evaluate it (x)? ";
    std::cin >> x;

    bool error = false;
    float result = deriv(order, x, a4, a3, a2, a1, a0, error);

    if (error) {
        std::cerr << "Error: only derivatives 1 to 4 are supported.\n";
    } else {
        std::cout << "The " << order << ". derivative at x = "
                  << std::fixed << std::setprecision(2) << x
                  << " is: " << std::setprecision(6) << result << "\n";
    }

    return 0;
}
// 2.25. Lépésenkénti összegzés
// 2.25.1. Írjon programot, amely a konzolról kér be egész számokat egy 
// ciklus segítségével és egy függvény segítségével számolja ki azok 
// összegét! Ezt a függvényt minden szám bekérése után hívja, ami ezután 
// visszaadja az eddigi számok összegét. Használjon statikus változót a 
// részösszeg tárolására! 
// 2.25.1.


#include <iostream>

int sum(int data) {
    static int result = 0;
    result += data;
    return result;
}

int main() {
    int num, total = 0;
    char more = 'y';

    do {
        std::cout << "Provide the next number: ";
        std::cin >> num;

        total = sum(num);

        std::cout << "Are there more numbers? (y/n): ";
        std::cin >> more;
        std::cin.ignore(10000, '\n');  // input buffer ürítése
    } while (more == 'y' || more == 'Y');

    std::cout << "The total is " << total << "." << std::endl;

    return 0;
}

// 2.25.2. Írjon olyan függvényt az előző programhoz, amely lenullázza az 
// aktuális összeget! 

// 2.25.2. 

#include <iostream>

class Accumulator {
    static int total;
public:
    static int add(int value) {
        total += value;
        return total;
    }

    static int get() {
        return total;
    }

    static void reset() {
        total = 0;
    }
};

int Accumulator::total = 0;

int main() {
    int num;
    char more = 'y';

    do {
        std::cout << "Provide the next number: ";
        std::cin >> num;
        std::cout << "Current total: " << Accumulator::add(num) << "\n";

        std::cout << "Do you want to cancel total (c), continue (y), or exit (n)? ";
        std::cin >> more;
        std::cin.ignore(10000, '\n');

        if (more == 'c') {
            Accumulator::reset();
            std::cout << "Total reset to 0.\n";
        }

    } while (more == 'y' || more == 'c');

    std::cout << "Final total: " << Accumulator::get() << "\n";

    return 0;
}
// 2.25.3. Módosítsa úgy az előző programot, hogy nem használ statikus 
// változót, hanem paraméterként adja át az eddigi részösszeget! 
// 2.25.3.



#include <iostream>

int sum(int data, int subTotal) {
    subTotal += data;
    return subTotal;
}

int main() {
    int num, total, subTotal = 0;
    char more = 'y';

    do {
        std::cout << "Provide the next number: ";
        std::cin >> num;

        subTotal = sum(num, subTotal);

        std::cout << "Are there more numbers? (y/n): ";
        std::cin >> more;
        std::cin.ignore(10000, '\n'); // clear input buffer

    } while (more == 'y' || more == 'Y');

    total = subTotal;

    std::cout << "The total is " << total << ".\n";

    return 0;
}
// 2.26. Alias változók
// 2.26.1. Írjon programot, amelyben egy kocka felületét és térfogatát 
// számolja ki! Úgy írja fel a képletet, hogy két ugyanolyan nevű változó 
// ne szerepeljen benne, hanem használjon alias változókat mutatók 
// segítségével. 
// 2.26.1.


#include <iostream>

int main() {
    int side;
    int *side1 = &side, *side2 = &side, *side3 = &side;
    int surface, volume;

    std::cout << "The side of the cube is: ";
    std::cin >> side;

    surface = 6 * (*side1) * (*side2);  // 6 * a * a
    volume = (*side1) * (*side2) * (*side3);  // a * a * a

    std::cout << "The volume of the cube is: " << volume << std::endl;
    std::cout << "The surface of the cube is: " << surface << std::endl;

    return 0;
}
// 2.26.2. Demonstrálja, hogy a * és a & ellentétes hatású műveletek! 

// 2.26.2. 


// A kifejezés:

// ```c
// printf("The volume of the cube is: %d\n", *&*&volume);
// ```

// valóban **demonstrálja, hogy a `*` (dereferencia) és a `&` (címképzés) egymás inverzei**, azaz "ellentétes hatású műveletek".

// ---

// ### 🔍 Magyarázat lépésenként

// Tegyük fel:

// ```c++
// int volume = 125;
// ```

// A kifejezés:

// ```c++
// *&*&volume
// ```

// így értelmezhető:

// 1. `&volume` → a `volume` változó címe (pl. `0x7ffeefbff5a4`)
// 2. `*&volume` → először `&volume`, majd `*` visszaadja a `volume` értékét, tehát `125`
// 3. `*&*&volume` → ugyanaz, mint `volume`, hiszen minden `*` és `&` pár kioltja egymást.

// ---

// ### ✅ Tehát ez teljesen helyes példa arra, hogy:

// ```cpp
// *&x == x
// ```

// bármilyen változóra `x`.

// ---

// ### Példa C++11 verzióban:

// ```cpp
#include <iostream>
using namespace std;

int main() {
    int volume = 125;
    cout << "The volume of the cube is: " << *&*&volume << endl;
    return 0;
}
// ```

// ---

// Ez a kimenetet adja:

// ```
// The volume of the cube is: 125
// ```

// 💡 **Összefoglalás**: A `&` és a `*` egymás ellentétei – egy változó címét veszed, majd az azon a címen levő értéket olvasod ki.


 // 2.26.3. Írjon az előzőhöz hasonló programot gömbre vonatkozóan! 

// 2.26.3.


#include <iostream>
#include <iomanip>
#include <cmath>  // M_PI is available in C++

int main() {
    float radius;
    float* radius1 = &radius;
    float* radius2 = &radius;
    float* radius3 = &radius;
    float surface, volume;

    std::cout << "The radius of the ball is: ";
    std::cin >> radius;

    surface = 4.0f * M_PI * (*radius1) * (*radius2);  // Surface = 4πr²
    volume = (4.0f / 3.0f) * M_PI * (*radius1) * (*radius2) * (*radius3);  // Volume = 4/3πr³

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "The surface of the ball is: " << surface << std::endl;
    std::cout << "The volume of the ball is: " << volume << std::endl;

    return 0;
}
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
// 2.29.1. Írjon programot, amelyben bekéri, hogy rövid egész vagy hosszú 
// lebegőpontos típussal akar dolgozni. Hozzon létre két dinamikus változót 
// a megfelelő típusból! Kérje be a változók értékeit és az első 
// változó értékét növelje meg a másodikéval! 

// 2.29.1.

#include <iostream>
#include <memory>    // opcionális: std::unique_ptr
using namespace std;

int main() {
    int choice;
    cout << "Choose operand type:\n"
         << "  1) short int\n"
         << "  2) long double\n"
         << "Your choice: ";
    cin >> choice;

    if (choice == 1) {
        // Dinamikus short int változók
        short int* si1 = new short int;
        short int* si2 = new short int;

        cout << "Enter si1: ";
        cin >> *si1;
        cout << "Enter si2: ";
        cin >> *si2;

        *si1 += *si2;
        cout << "The increased value is: " << *si1 << "\n";

        delete si1;
        delete si2;
    }
    else if (choice == 2) {
        // Dinamikus long double változók
        long double* ld1 = new long double;
        long double* ld2 = new long double;

        cout << "Enter ld1: ";
        cin >> *ld1;
        cout << "Enter ld2: ";
        cin >> *ld2;

        *ld1 += *ld2;
        cout << "The increased value is: " << *ld1 << "\n";

        delete ld1;
        delete ld2;
    }
    else {
        cerr << "Invalid choice.\n";
        return 1;
    }

    return 0;
}
// 2.30. Struktúra kezelés
// 2.30.1. Készítsen struktúrát, amely minden egyszerű adattípusból 
// tartalmaz egyet valamint egy egészre mutató mutatót! Kérje be a struktúra 
// adattagjait a konzolról, majd írja ki azokat! 
// 2.30.1.


#include <iostream>
#include <memory>   // std::unique_ptr

struct Var {
    char        varChar;
    short       varShortInt;
    int         varInt;
    float       varFloat;
    double      varDouble;
    long double varLongDouble;
    int*        varPInt;
};

int main() {
    Var myVar;

    std::cout << "varChar: ";
    std::cin >> myVar.varChar;

    std::cout << "varShortInt: ";
    std::cin >> myVar.varShortInt;

    std::cout << "varInt: ";
    std::cin >> myVar.varInt;

    std::cout << "varFloat: ";
    std::cin >> myVar.varFloat;

    std::cout << "varDouble: ";
    std::cin >> myVar.varDouble;

    std::cout << "varLongDouble: ";
    std::cin >> myVar.varLongDouble;

    // A mutatóhoz bekérünk egy egész értéket, és dinamikusan lefoglaljuk
    int temp;
    std::cout << "Enter integer for varPInt (we'll allocate and store it): ";
    std::cin >> temp;
    myVar.varPInt = new int(temp);

    // Kiírás
    std::cout << "\n--- myVar contents ---\n";
    std::cout << "varChar        = " << myVar.varChar        << "\n";
    std::cout << "varShortInt    = " << myVar.varShortInt    << "\n";
    std::cout << "varInt         = " << myVar.varInt         << "\n";
    std::cout << "varFloat       = " << myVar.varFloat       << "\n";
    std::cout << "varDouble      = " << myVar.varDouble      << "\n";
    std::cout << "varLongDouble  = " << myVar.varLongDouble  << "\n";
    std::cout << "varPInt (addr) = " << static_cast<void*>(myVar.varPInt)
              << "  *varPInt = " << *myVar.varPInt      << "\n";

    // Felszabadítás
    delete myVar.varPInt;
    myVar.varPInt = nullptr;

    return 0;
}
// 2.30.2. Módosítsa az előző programot úgy, hogy létrehoz új típusnevet a 
// struktúrának és ezt használja a továbbiakban! Külön függvényben 
// valósítsa meg a struktúra bekérő és kiíró részt! Hozzon létre egy 
// dinamikus struktúrát, amit tegyen egyenlővé a bekért struktúrával! 
// Módosítsa a dinamikus struktúrán keresztül az egész mutató által 
// mutatott értéket!
// 2.30.2.

#include <iostream>
#include <memory>   // std::unique_ptr
#include <iomanip>  // fixed, setprecision

using namespace std;

// 1) Új típusnév a struktúrának
struct Var {
    char        varChar;
    short       varShortInt;
    int         varInt;
    float       varFloat;
    double      varDouble;
    long double varLongDouble;
    int*        varPInt;
};
using VarType = Var;

// 2) Bekérő függvény
void readVarType(VarType* v) {
    cout << "varChar: ";
    cin >> v->varChar;

    cout << "varShortInt: ";
    cin >> v->varShortInt;

    cout << "varInt: ";
    cin >> v->varInt;

    cout << "varFloat: ";
    cin >> v->varFloat;

    cout << "varDouble: ";
    cin >> v->varDouble;

    cout << "varLongDouble: ";
    cin >> v->varLongDouble;

    // A mutató álljon rá az int mezőre
    v->varPInt = &v->varInt;
}

// 3) Kiíró függvény
void printVarType(const VarType& v) {
    cout << "\n--- VarType contents ---\n";
    cout << "varChar        = " << v.varChar        << "\n";
    cout << "varShortInt    = " << v.varShortInt    << "\n";
    cout << "varInt         = " << v.varInt         << "\n";
    cout << "varFloat       = " << fixed << setprecision(6) << v.varFloat       << "\n";
    cout << "varDouble      = " << v.varDouble      << "\n";
    cout << "varLongDouble  = " << v.varLongDouble  << "\n";
    cout << "varPInt (addr) = " << static_cast<void*>(v.varPInt)
         << " *varPInt      = " << *v.varPInt      << "\n";
}

int main() {
    // Statikus változó
    VarType myVar;
    readVarType(&myVar);

    // Kiírjuk az eredeti struktúrát
    printVarType(myVar);

    // Dinamikusan létrehozott másolat
    unique_ptr<VarType> copy(new VarType(myVar));

    // A dinamikus példány kiírása
    printVarType(*copy);

    // A mutatón keresztül módosítjuk a varInt-et
    *copy->varPInt = 666;

    // Visszaellenőrizzük az eredeti struktúrán
    printVarType(myVar);

    return 0;
}
// 2.31. Esküvő
// 2.31.1. Készítsen programot, amely tartalmazza a következő 
// adatszerkezeteket: ember típus: név, életkor, azonosító;
// gyűrű típus: karát, érték, kövek száma;
// esküvő típus: férj, feleség, eljegyzési gyűrű, esküvői gyűrű, 
// vendégek (dinamikus tömb), vendégek száma. Inicializáljon egy esküvő 
// típusú változót, írja ki a változó értékét szépen tördelve úgy, 
// hogy minden struktúra kiíráshoz külön függvényt hoz létre! 
// 2.31.1.

#include <iostream>
#include <string>
#include <vector>

struct Person {
    std::string name;
    int age;
    int ID;
};

struct Ring {
    int carat;
    double price;
    int numberOfStones;
};

struct Wedding {
    Person man;
    Person wife;
    Ring engagementRing;
    Ring weddingRing;
    std::vector<Person> guests;
};

// Kiíró függvények
void printPerson(const Person& p) {
    std::cout << "Person { "
              << "name: \"" << p.name << "\", "
              << "age: " << p.age << ", "
              << "ID: " << p.ID
              << " }";
}

void printRing(const Ring& r) {
    std::cout << "Ring { "
              << "carat: " << r.carat << ", "
              << "price: " << r.price << ", "
              << "stones: " << r.numberOfStones
              << " }";
}

void printWedding(const Wedding& w) {
    std::cout << "Wedding {\n";
    std::cout << "  Man: ";    printPerson(w.man);    std::cout << "\n";
    std::cout << "  Wife: ";   printPerson(w.wife);   std::cout << "\n";
    std::cout << "  Engagement Ring: "; printRing(w.engagementRing); std::cout << "\n";
    std::cout << "  Wedding Ring:    "; printRing(w.weddingRing);    std::cout << "\n";
    std::cout << "  Guests (" << w.guests.size() << "):\n";
    for (const auto& guest : w.guests) {
        std::cout << "    - "; printPerson(guest); std::cout << "\n";
    }
    std::cout << "}\n";
}

int main() {
    // Vendégek (dinamikus vektor)
    std::vector<Person> friends = {
        { "Jani",  28, 12345 },
        { "Emese", 29, 66666 },
        { "Zoli",  32, 222222 }
    };

    // Esküvő inicializálása
    Wedding brotherWedding {
        { "Arpi",  32, 23332 },    // férj
        { "Panna", 29, 22222 },    // feleség
        { 16,     60000.0, 0    }, // eljegyzési gyűrű
        { 24,    200000.0, 3    }, // esküvői gyűrű
        friends                   // vendégek
    };

    // Kiírás
    printWedding(brotherWedding);

    return 0;
}
// 2.32. Ventilátor
// 2.32.1. Írjon programot, amelyben létrehoz egy ventilátor típust: gyártó 
// (statikus tömb), termékszám, leírás (dinamikus tömb), ár! Írjon 
// függvényt, amely bekéri az adattagok értékét és a rekordot 
// visszatérési értékként adja vissza! Szintén írjon függvényt a 
// struktúra kiírásához!
// 2.32.1.



#include <iostream>
#include <string>
#include <limits>    // ide kell a numeric_limits
#include <iomanip>   // ide kell a fixed és setprecision

struct Fan {
    std::string manufacturer;
    int productNumber;
    std::string description;
    float price;
};

Fan readFan() {
    Fan rec;
    std::cout << "Provide the data of the fan!\n";

    std::cout << "manufacturer: ";
    std::getline(std::cin, rec.manufacturer);

    std::cout << "product number: ";
    std::cin >> rec.productNumber;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "description: ";
    std::getline(std::cin, rec.description);

    std::cout << "price: ";
    std::cin >> rec.price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return rec;
}

void printFan(const Fan& rec) {
    std::cout << "\nFan data\n";
    std::cout << "manufacturer:   " << rec.manufacturer  << "\n";
    std::cout << "product number: " << rec.productNumber << "\n";
    std::cout << "description:    " << rec.description   << "\n";
    std::cout << "price:          "
              << std::fixed << std::setprecision(2)
              << rec.price << " HUF\n";
}

int main() {
    Fan myFan = readFan();
    printFan(myFan);
    return 0;
}
// 2.32.2. Módosítsa úgy a programot, hogy a ventilátor változó értékét 
// tegye egyenlővé egy másik változóval, módosítsa az eredeti változóban 
// a gyártót és a leírást! Írassa ki újból mindkét struktúrát! Milyen 
// furcsaságot tapasztal? Hogy lehet azt korrigálni? 
// 2.32.2.


#include <iostream>
#include <string>
#include <limits>    // for std::numeric_limits
#include <iomanip>   // for std::fixed, std::setprecision

struct Fan {
    std::string manufacturer;
    int         productNumber;
    std::string description;
    float       price;
};

Fan readFan() {
    Fan rec;
    std::cout << "Provide the data of the fan!\n";

    std::cout << "manufacturer: ";
    std::getline(std::cin, rec.manufacturer);

    std::cout << "product number: ";
    std::cin >> rec.productNumber;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "description: ";
    std::getline(std::cin, rec.description);

    std::cout << "price: ";
    std::cin >> rec.price;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return rec;
}

void printFan(const Fan& rec) {
    std::cout << "\nFan data\n"
              << "manufacturer:   " << rec.manufacturer  << "\n"
              << "product number: " << rec.productNumber << "\n"
              << "description:    " << rec.description   << "\n"
              << "price:          "
              << std::fixed << std::setprecision(2)
              << rec.price << " HUF\n";
}

int main() {
    Fan fan1 = readFan();
    Fan fan2 = fan1;  // deep copy of std::string fields

    // Modify the original
    fan1.manufacturer = "NewManufacturer";
    fan1.description  = "A completely new description";

    std::cout << "\n== Fan 1 ==\n";
    printFan(fan1);

    std::cout << "\n== Fan 2 ==\n";
    printFan(fan2);

    return 0;
}
// 2.33. Többszörösen összetett típus
// 2.33.1. Írjon programot, amelyben szemlélteti a karakteres képernyőn a 
// struktúrák elhelyezkedését a memóriában! Hozzon létre egy osztály 
// típusú struktúrát: hallgatók száma, hallgatók Neptun kódjai (statikus 
// sztring tömb), hallgatók pontszámai (statikus lebegőpontos tömb)! Írjon 
// függvényt, amely megjelenti a paraméterként átadott struktúra 
// adattagjainak a címeit és értékeit (a tömb típusú mezőknek csak az 
// első elemét kell megjeleníteni)! Írja ki azt is, hogy milyen más módon 
// tud az adott címre hivatkozni! Ezt az információt is paraméterként adja 
// át a kiíró függvénynek! Hozzon létre kételemű tömböt osztály 
// típusú struktúrákból! Inicializálja a tömböt és hívja meg mindkét 
// elemre a kiíró függvényt! 
// 2.33.1.

#include <iostream>
#include <array>
#include <iomanip>

struct Course {
    int sNum;
    std::array<std::string, 100> sCode;
    std::array<float,       100> sPoints;
};

void printCourse(const Course& c, const std::array<std::array<std::string,3>,4>& comments) {
    // címek
    std::cout << std::left << std::setw(12) << "Address:"
              << std::setw(20) << &c
              << std::setw(20) << &c.sCode
              << &c.sPoints << "\n";

    // értékek (első elem)
    std::cout << std::setw(12) << "Value:"
              << std::setw(20) << c.sNum
              << std::setw(20) << c.sCode[0]
              << c.sPoints[0] << "\n";

    // kommentek
    for (int i = 0; i < 4; ++i) {
        std::cout << std::setw(12) << ""
                  << std::setw(20) << comments[i][0]
                  << std::setw(20) << comments[i][1]
                  << comments[i][2] << "\n";
    }
}

int main() {
    // inicializálás
    Course courses[2];
    courses[0].sNum = 3;
    courses[0].sCode = { "AA34","BE3E","CLY56" };
    courses[0].sPoints = { 16.4f,23.2f,40.0f };

    courses[1].sNum = 2;
    courses[1].sCode = { "NMA444","SE63" };
    courses[1].sPoints = { 13.2f,50.0f };

    std::array<std::array<std::string,3>,4> comments = {{
        { "course[0]",   "",              ""               },
        { "course[0].sNum","course[0].sCode","course[0].sPoints" },
        { "",            "course[0].sCode[0]","course[0].sPoints[0]" },
        { "",            "",              "course[0].sCode[0][0]" }
    }};

    printCourse(courses[0], comments);

    std::cout << "\n";

    // átírjuk a kommenteket index 1-re
    for (auto& row : comments)
        for (auto& cell : row)
            for (auto& ch : cell)
                if (ch=='0') ch='1';

    printCourse(courses[1], comments);

    return 0;
}
// 2.34.  Bitmezők
// 2.34.1. Írjon programot egyén adatainak a tárolásához! Az ember típus 
// mezői a név (statikus tömb), nem, nagykorú-e, csillagjegye, vallása (5 
// nagy vallás vagy egyéb), élő személy-e, vércsoport, RH csoport! 
// Használjon megfelelő hosszú bitmezőket! Írjon bekérő és kiíró 
// függvényt, a kiíró függvénynél ne számokat, hanem azok jelentéseit 
// írja ki! Határozza meg a struktúra méretét! 
// 2.34.1.

#include <iostream>
#include <string>
#include <array>
#include <iomanip>

struct Person {
    // Name as fixed-size C-string
    char name[100];

    // Bitfields
    unsigned sex       : 1;  // 0=female,1=male
    unsigned grownUp   : 1;  // 0=no,1=yes
    unsigned zodiac    : 4;  // 0–11 covers 12 signs
    unsigned religion  : 3;  // 0–5 covers 6 choices
    unsigned bloodType : 2;  // 0=O,1=A,2=B,3=AB
    unsigned RH        : 1;  // 0='-',1='+'
};

void readPerson(Person& p) {
    int tmp;

    std::cout << "name: ";
    std::cin >> p.name;

    std::cout << "sex (0=female,1=male): ";
    std::cin >> tmp;  p.sex = tmp;

    std::cout << "grown up? (0=no,1=yes): ";
    std::cin >> tmp;  p.grownUp = tmp;

    std::cout
      << "zodiac (0=Aries,1=Taurus,2=Gemini,3=Cancer,\n"
      << "        4=Leo,5=Virgo,6=Libra,7=Scorpio,\n"
      << "        8=Sagittarius,9=Capricorn,10=Aquarius,11=Pisces): ";
    std::cin >> tmp;  p.zodiac = tmp;

    std::cout
      << "religion (0=Judaism,1=Christian,2=Islam,\n"
      << "          3=Hinduism,4=Buddhism,5=other): ";
    std::cin >> tmp;  p.religion = tmp;

    std::cout << "blood type (0=O,1=A,2=B,3=AB): ";
    std::cin >> tmp;  p.bloodType = tmp;

    std::cout << "RH (0='-',1='+'): ";
    std::cin >> tmp;  p.RH = tmp;
}

void printPerson(const Person& p) {
    static const std::array<std::string,12> zodiacs = {
      "Aries","Taurus","Gemini","Cancer",
      "Leo","Virgo","Libra","Scorpio",
      "Sagittarius","Capricorn","Aquarius","Pisces"
    };
    static const std::array<std::string,6> religions = {
      "Judaism","Christian","Islam","Hinduism","Buddhism","other"
    };
    static const std::array<std::string,4> bloods = {
      "O","A","B","AB"
    };

    std::cout << "\nPerson {\n";
    std::cout << "  name:       " << p.name       << "\n";
    std::cout << "  sex:        " << (p.sex ? "male" : "female") << "\n";
    std::cout << "  grownUp:    " << (p.grownUp ? "yes" : "no")      << "\n";
    std::cout << "  zodiac:     " << zodiacs[p.zodiac]                << "\n";
    std::cout << "  religion:   " << religions[p.religion]            << "\n";
    std::cout << "  bloodType:  " << bloods[p.bloodType]             << "\n";
    std::cout << "  RH:         " << (p.RH ? "+" : "-")               << "\n";
    std::cout << "};\n";

    std::cout << "Sizeof(Person) = "
              << sizeof(Person) << " bytes\n";
}

int main() {
    Person me;
    readPerson(me);
    printPerson(me);
    return 0;
}
// 2.34.2. Módosítsa úgy a struktúrát, hogy bitmezők helyett egész 
// változókat használ! Mennyivel nő a struktúra mérete? 
// 2.34.2.


#include <iostream>
#include <string>
#include <array>
#include <limits>    // <-- ide kell
#include <iomanip>   // ha fixed/setprecision kellene

struct Person {
    std::string name;
    unsigned int sex;
    unsigned int grownUp;
    unsigned int zodiac;
    unsigned int religion;
    unsigned int bloodType;
    unsigned int RH;
};

void readPerson(Person& p) {
    std::cout << "name: ";
    std::getline(std::cin, p.name);

    std::cout << "sex (0=female,1=male): ";
    std::cin >> p.sex;

    std::cout << "grownUp (0=no,1=yes): ";
    std::cin >> p.grownUp;

    std::cout << "zodiac (0=Aries ... 11=Pisces): ";
    std::cin >> p.zodiac;

    std::cout << "religion (0=Judaism ... 5=other): ";
    std::cin >> p.religion;

    std::cout << "bloodType (0=O,1=A,2=B,3=AB): ";
    std::cin >> p.bloodType;

    std::cout << "RH (0='-',1='+'): ";
    std::cin >> p.RH;

    // Töröljük a \n-t, hogy a következő getline jól menjen
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printPerson(const Person& p) {
    static const std::array<std::string,12> ZODIAC = {
      "Aries","Taurus","Gemini","Cancer","Leo","Virgo",
      "Libra","Scorpio","Sagittarius","Capricorn",
      "Aquarius","Pisces"
    };
    static const std::array<std::string,6> RELIGION = {
      "Judaism","Christian","Islam","Hinduism","Buddhism","other"
    };
    static const std::array<std::string,4> BLOOD = { "O","A","B","AB" };

    std::cout << "\nPerson {\n"
              << "  name:       " << p.name       << "\n"
              << "  sex:        " << (p.sex ? "male" : "female") << "\n"
              << "  grownUp:    " << (p.grownUp ? "yes" : "no")     << "\n"
              << "  zodiac:     " << ZODIAC[p.zodiac]                << "\n"
              << "  religion:   " << RELIGION[p.religion]            << "\n"
              << "  bloodType:  " << BLOOD[p.bloodType]             << "\n"
              << "  RH:         " << (p.RH ? "+" : "-")              << "\n"
              << "}\n"
              << "sizeof(Person) = " << sizeof(Person) << " bytes\n";
}

int main() {
    Person me;
    readPerson(me);
    printPerson(me);
    return 0;
}
// 2.35. Szóbeli vizsga
// 2.35.1. Írjon programot, amelyben bekéri egy szóbeli vizsga minősítését! 
// A minősítés lehet: szörnyű, rossz, gyenge, jó, kiváló. Használjon 
// felsorolás típust! Írjon függvényt a minősítés szöveges kiírására! 
// Kérje be az ismétlő vizsga eredményét, határozza meg, hogy javított-e az 
// illető! 
// 2.35.1.


#include <iostream>
#include <string>

enum class Result { Awful = 0, Bad, Weak, Good, Excellent };

void printResult(Result r) {
    switch (r) {
        case Result::Awful:     std::cout << "awful";     break;
        case Result::Bad:       std::cout << "bad";       break;
        case Result::Weak:      std::cout << "weak";      break;
        case Result::Good:      std::cout << "good";      break;
        case Result::Excellent: std::cout << "excellent"; break;
    }
}

int main() {
    std::cout << "Enter your exam result:\n"
              << "  0=awful, 1=bad, 2=weak, 3=good, 4=excellent\n> ";
    int i1;
    std::cin >> i1;
    Result exam1 = static_cast<Result>(i1);

    std::cout << "Your first result is: ";
    printResult(exam1);
    std::cout << "\n\n";

    std::cout << "Enter your retake exam result:\n"
              << "  0=awful, 1=bad, 2=weak, 3=good, 4=excellent\n> ";
    int i2;
    std::cin >> i2;
    Result exam2 = static_cast<Result>(i2);

    std::cout << "Your retake result is: ";
    printResult(exam2);
    std::cout << "\n\n";

    if (exam2 > exam1) {
        std::cout << "Very good, you improved!\n";
    } else if (exam2 == exam1) {
        std::cout << "At least you tried!\n";
    } else {
        std::cout << "You must be very unlucky!\n";
    }

    return 0;
}
// 2.35.2. Oldja meg az eredeti feladatot #define-ok segítségével! Vezesse be a 
// közepes minősítést! Miért jobb felsorolás típust használni define helyett? 

// 2.35.2. 


#include <iostream>
#include <string>

// 1) #define-okkal
#define AWFUL     0
#define BAD       1
#define WEAK      2
#define MEDIUM    3
#define GOOD      4
#define EXCELLENT 5

void printResult(int r) {
    switch (r) {
        case AWFUL:     std::cout << "awful";     break;
        case BAD:       std::cout << "bad";       break;
        case WEAK:      std::cout << "weak";      break;
        case MEDIUM:    std::cout << "medium";    break;
        case GOOD:      std::cout << "good";      break;
        case EXCELLENT: std::cout << "excellent"; break;
        default:        std::cout << "unknown";  break;
    }
}

int main() {
    int exam1, exam2;

    std::cout << "Enter your exam result (0=awful,1=bad,2=weak,3=medium,4=good,5=excellent): ";
    std::cin >> exam1;

    std::cout << "First result: ";
    printResult(exam1);
    std::cout << "\n\n";

    std::cout << "Enter your retake exam result: ";
    std::cin >> exam2;

    std::cout << "Retake result: ";
    printResult(exam2);
    std::cout << "\n\n";

    if (exam2 > exam1) {
        std::cout << "Very good, you improved!\n";
    }
    else if (exam2 == exam1) {
        std::cout << "At least you tried!\n";
    }
    else {
        std::cout << "You must be very unlucky!\n";
    }

    return 0;
}
// 2.36.1. Írjon programot, amely beállítja egy fájl „csak olvasható” 
// tulajdonságát! Kérje be egy szöveges fájl nevét! Állítsa be a fájl 
// csak olvasható tulajdonságát, majd próbáljon meg a fájl végéhez fűzni 
// egy szöveget C-ből hívott DOS parancs segítségével (DOS parancs: echo 
// text >>fileName)! Futtassa a DOS parancsot C-ből: system(char*) 
// segítségével! Törölje a csak olvasható tulajdonságot és próbáljon 
// ismét a fájl végéhez fűzni egy szöveget! 
// 2.36.1.

#include <iostream>
#include <string>
#include <sys/stat.h>
#include <cstdlib>
#include <cerrno>

int main() {
    std::string filename;
    std::cout << "Enter text file name: ";
    std::cin >> filename;

    // 1) Kapcsoljuk csak olvashatóra (0444)
    if (chmod(filename.c_str(), S_IRUSR | S_IRGRP | S_IROTH) != 0) {
        std::perror("chmod to read-only failed");
        return 1;
    }
    std::cout << "File set to read-only.\n";

    // 2) Próbáljunk meg fűzni: echo "Read-only append" >> filename
    {
        std::string cmd = "echo \"Read-only append\" >> " + filename;
        int ret = std::system(cmd.c_str());
        std::cout << "Attempt to append in read-only mode returned: " << ret << "\n";
    }

    // 3) Visszaállítjuk read-write (0644)
    if (chmod(filename.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != 0) {
        std::perror("chmod to read-write failed");
        return 1;
    }
    std::cout << "File set to read-write.\n";

    // 4) Újra próbáljuk a fűzést
    {
        std::string cmd = "echo \"Writable append\" >> " + filename;
        int ret = std::system(cmd.c_str());
        std::cout << "Attempt to append in read-write mode returned: " << ret << "\n";
    }

    return 0;
}
// 2.36. Csak olvasható fájl
// 2.36.2. Írja meg a tuti törlés programot! A program először törli a csak 
// olvasható tulajdonságot és utána DOS parancs segítségével törli a fájlt. 
// 2.36.2.


#include <iostream>
#include <string>
#include <cstdlib>  // system()

int main() {
    std::string fileName;

    std::cout << "File name: ";
    std::cin >> fileName;

    // Töröljük az írásvédelmet (chmod +w)
    std::string chmodCmd = "chmod +w \"" + fileName + "\"";
    int chmodResult = system(chmodCmd.c_str());

    if (chmodResult != 0) {
        std::cerr << "Error: failed to set write permission (chmod).\n";
        return 1;
    } else {
        std::cout << "Write permission added (chmod +w).\n";
    }

    // Töröljük a fájlt
    std::string rmCmd = "rm \"" + fileName + "\"";
    int rmResult = system(rmCmd.c_str());

    if (rmResult == 0) {
        std::cout << "File deleted successfully using rm.\n";
    } else {
        std::cerr << "Failed to delete file using rm.\n";
        return 2;
    }

    return 0;
}
// 2.37. Átnevezés
// 2.37.1. Feladat: Írjon programot fájlok átnevezésére! A régi és az új 
// fájlnév a program paraméterében legyen adott! Ha valamelyik paraméter 
// hiányzik, akkor írja ki a helyes használatot! Ha hiba történik átnevezés 
// közben, akkor írja ki a megfelelő hibaüzenetet a hibakód alapján! 
// 2.37.1.

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cerrno>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage:\n  " << argv[0] << " <oldName> <newName>\n";
        return 1;
    }

    const char* oldName = argv[1];
    const char* newName = argv[2];

    if (std::rename(oldName, newName) != 0) {
        switch (errno) {
            case EEXIST:
                std::cerr << "Error: '" << newName << "' already exists!\n";
                break;
            case ENOENT:
                std::cerr << "Error: '" << oldName << "' does not exist!\n";
                break;
            case EINVAL:
                std::cerr << "Error: Invalid characters in '" << newName << "'.\n";
                break;
            case EACCES:
                std::cerr << "Error: Permission denied.\n";
                break;
            default:
                std::cerr << "Unknown error (" << strerror(errno) << ").\n";
                break;
        }
        return 2;
    }

    std::cout << "Rename successful: '" << oldName << "' → '" << newName << "'\n";
    return 0;
}
// 2.38. Szövegfájl
// 2.38.1. Írjon programot, amely bekéri a következő információkat: 
// minimális érték, maximális érték fájl név, adatok száma! Generáljon 
// adott számú véletlen számot a megfelelő határok között és mentse el 
// azokat egy szövegfájlba külön sorokba! 
// 2.38.1.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    std::string fileName;
    int min, max, count;

    std::cout << "This program will save random numbers into a text file.\n";
    std::cout << "File name: ";
    std::cin >> fileName;
    std::cout << "Minimum number: ";
    std::cin >> min;
    std::cout << "Maximum number: ";
    std::cin >> max;
    std::cout << "Number of values to generate: ";
    std::cin >> count;

    if (min > max) {
        std::cerr << "Error: min cannot be greater than max.\n";
        return 1;
    }

    std::ofstream outFile(fileName);
    if (!outFile) {
        std::cerr << "Error: cannot open file for writing.\n";
        return 1;
    }

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < count; ++i) {
        int value = std::rand() % (max - min + 1) + min;
        outFile << value << '\n';
    }

    outFile.close();
    std::cout << "Random numbers saved successfully to '" << fileName << "'.\n";

    return 0;
}
// 2.38.2. Módosítsa úgy a programot, hogy az első sorba írja ki az adatok 
// számát! Szóközökkel válassza el az egyes értékeket és minden számot 
// fix hosszan írjon ki! 100 számonként szúrjon be egy üres sort! 
// 2.38.2.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

int main() {
    std::ofstream tf;
    int min, max, num;
    std::string fileName;

    std::cout << "This program will save a certain amount of random numbers into a file.\n";

    std::cout << "File name: ";
    std::cin >> fileName;

    std::cout << "Min number: ";
    std::cin >> min;

    std::cout << "Max number: ";
    std::cin >> max;

    std::cout << "Number of data: ";
    std::cin >> num;

    tf.open(fileName);
    if (!tf) {
        std::cerr << "File open to write has failed!\n";
        return 1;
    }

    // seed the random generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    // write the number of values in the first line
    tf << num << '\n';

    const int width = 6;
    int count = 0;

    for (int i = 0; i < num; ++i) {
        int data = std::rand() % (max + 1 - min) + min;
        tf << std::setw(width) << data << ' ';
        ++count;

        if (count == 100) {
            tf << '\n';
            count = 0;
        }
    }

    tf.close();
    std::cout << "File written successfully.\n";

    return 0;
}
// 2.39. Hamupipőke
// 2.39.1. Írjon programot, amely egy már meglévő, véletlen számokat 
// tartalmazó fájlban lévő számokat szétválogatja párosság alapján! A 
// páros és páratlan számokat tárolja külön fájlokban! Írjon függvényt, 
// amely kiszámolja az egy fájlban lévő számok átlagát! Alkalmazza a 
// függvényt a két fájlra és határozza meg a két fájlban lévő számok 
// mennyiségének az arányát! 
// 2.39.1.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

double average(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Cannot open file: " << fileName << endl;
        return 0;
    }

    int value, count = 0;
    double sum = 0;

    while (file >> value) {
        sum += value;
        ++count;
    }

    file.close();
    return count ? (sum / count) : 0;
}

int main() {
    string origFileName, evenFileName = "even.txt", oddFileName = "odd.txt";
    int evenCounter = 0, oddCounter = 0, value;

    cout << "This program will divide numbers based on parity.\n";
    cout << "Enter the name of the input file: ";
    cin >> origFileName;

    ifstream input(origFileName);
    if (!input.is_open()) {
        cerr << "Failed to open input file!\n";
        return 1;
    }

    ofstream evenFile(evenFileName);
    ofstream oddFile(oddFileName);

    while (input >> value) {
        if (value % 2 == 0) {
            ++evenCounter;
            evenFile << value << '\n';
        } else {
            ++oddCounter;
            oddFile << value << '\n';
        }
    }

    input.close();
    evenFile.close();
    oddFile.close();

    cout << "There were " << evenCounter << " even and "
         << oddCounter << " odd numbers.\n";

    if (oddCounter > 0)
        cout << "Their ratio is: " << fixed << setprecision(6)
             << static_cast<double>(evenCounter) / oddCounter << '\n';
    else
        cout << "No odd numbers to compare ratio.\n";

    double evenAvg = average(evenFileName);
    double oddAvg = average(oddFileName);

    cout << "Average of even numbers: " << setprecision(9) << evenAvg << '\n';
    cout << "Average of odd numbers: " << setprecision(9) << oddAvg << '\n';

    return 0;
}
// 2.40. XML
// 2.40.1. Írjon programot, amely XML-ben ment el rekordokat! A kocsi típus 
// azonosítót és árat, a személy típus nevet, életkort, a kocsik számát, 
// és kocsi tömböt tartalmaz. Hozzon létre és inicializáljon egy 3 hosszú 
// személy tömböt és mentse el azokat XML fájlba! Az XML fájl legyen szépen 
// tördelve! Írjon halfTag és fullTag függvényeket! Az előbbi csak 
// „<tagName>” vagy „</tagName>” -t ír ki, az útóbbi „<tagName> Text 
// </tagName>”-t ír ki. Példa: <Person> <Name>Jani</Name> <Age>22</Age> 
// <Count>3</ Count> <Car> <ID>0</ID> <price>50.000000</price> </Car> <Car> … 
// 2.40.1.


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

struct Car {
    int ID;
    double price;
};

struct Person {
    string name;
    int age;
    int carNumber;
    vector<Car> myCars;
};

void printHalfTag(ofstream& file, int depth, const string& tag) {
    file << string(depth, '\t') << "<" << tag << ">\n";
}

void printFullTag(ofstream& file, int depth, const string& tag, const string& text) {
    file << string(depth, '\t') << "<" << tag << ">" << text << "</" << tag << ">\n";
}

void printPerson(ofstream& file, const Person& buddy) {
    printHalfTag(file, 0, "Person");

    printFullTag(file, 1, "Name", buddy.name);
    printFullTag(file, 1, "Age", to_string(buddy.age));
    printFullTag(file, 1, "Count", to_string(buddy.carNumber));

    for (const Car& car : buddy.myCars) {
        printHalfTag(file, 1, "Car");
        printFullTag(file, 2, "ID", to_string(car.ID));
        ostringstream priceStream;
        priceStream << fixed << setprecision(6) << car.price;
        printFullTag(file, 2, "price", priceStream.str());
        printHalfTag(file, 1, "/Car");
    }

    printHalfTag(file, 0, "/Person");
}

int main() {
    const int buddyNumber = 3;

    vector<Car> cars1 = { {0, 50}, {2, 12.369}, {21, 0.569} };
    vector<Car> cars2 = { {6, 21}, {1, 15.4} };
    vector<Car> cars3 = { {3, 5.7} };

    vector<Person> buddies = {
        {"Jani", 22, static_cast<int>(cars1.size()), cars1},
        {"Evi", 36, static_cast<int>(cars2.size()), cars2},
        {"Zotya", 25, static_cast<int>(cars3.size()), cars3}
    };

    ofstream file("car.xml");
    if (!file) {
        cerr << "Error opening file for writing!\n";
        return 1;
    }

    for (const Person& p : buddies) {
        printPerson(file, p);
    }

    file.close();
    cout << "XML written to car.xml\n";
    return 0;
}

// 2.40.2. Módosítsa úgy az XML fájlt, hogy Car tag-k egy Cars tag-on belül 
// legyenek! Ahol lehet, az adatok a tagok tulajdonságaiban szerepeljenek! 
// Például: <name value="Jani"/> 
// 2.40.2.


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Car {
    int ID;
    double price;
};

struct Person {
    string name;
    int age;
    vector<Car> myCars;
};

void indent(ofstream& file, int depth) {
    for (int i = 0; i < depth; ++i) {
        file << "\t";
    }
}

void printSelfClosingTag(ofstream& file, int depth, const string& tag, const string& attrName, const string& value) {
    indent(file, depth);
    file << "<" << tag << " " << attrName << "=\"" << value << "\"/>\n";
}

void printStartTag(ofstream& file, int depth, const string& tag) {
    indent(file, depth);
    file << "<" << tag << ">\n";
}

void printEndTag(ofstream& file, int depth, const string& tag) {
    indent(file, depth);
    file << "</" << tag << ">\n";
}

void printPerson(ofstream& file, const Person& buddy) {
    ostringstream oss;

    printStartTag(file, 0, "Person");

    printSelfClosingTag(file, 1, "Name", "value", buddy.name);
    oss << buddy.age;
    printSelfClosingTag(file, 1, "Age", "value", oss.str());
    oss.str(""); oss.clear();
    oss << buddy.myCars.size();
    printSelfClosingTag(file, 1, "Count", "value", oss.str());

    printStartTag(file, 1, "Cars");
    for (const auto& car : buddy.myCars) {
        printStartTag(file, 2, "Car");

        oss.str(""); oss.clear();
        oss << car.ID;
        printSelfClosingTag(file, 3, "ID", "value", oss.str());

        oss.str(""); oss.clear();
        oss << fixed << setprecision(6) << car.price;
        printSelfClosingTag(file, 3, "Price", "value", oss.str());

        printEndTag(file, 2, "Car");
    }
    printEndTag(file, 1, "Cars");

    printEndTag(file, 0, "Person");
}

int main() {
    vector<Person> buddies = {
        {"Jani", 22, { {0, 50}, {2, 12.369}, {21, 0.569} }},
        {"Evi", 36, { {6, 21}, {1, 15.4} }},
        {"Zotya", 25, { {3, 5.7} }}
    };

    ofstream file("car.xml");
    if (!file) {
        cerr << "Error opening output file.\n";
        return 1;
    }

    for (const auto& person : buddies) {
        printPerson(file, person);
    }

    file.close();
    cout << "XML file created in car.xml.\n";
    return 0;
}

// 2.40.3. Készítsen beolvasó programot! Jelezze ki az XML fájl szintaktikai 
// hibáit! Például hibás tag, nyitó tag párja hiányzik vagy fordítva, két 
// tag pár keresztben van. 

// 2.40.3. 

#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

bool isOpeningTag(const string& tag) {
    return tag.length() > 2 && tag[0] == '<' && tag[1] != '/' && tag.back() == '>';
}

bool isClosingTag(const string& tag) {
    return tag.length() > 3 && tag[0] == '<' && tag[1] == '/' && tag.back() == '>';
}

string extractTagName(const string& tag) {
    size_t start = tag[1] == '/' ? 2 : 1;
    size_t end = tag.find('>', start);
    return tag.substr(start, end - start);
}

int main() {
    ifstream file("file.xml");
    if (!file.is_open()) {
        cerr << "Error: file.xml not found.\n";
        return 1;
    }

    string line, word;
    stack<pair<string, int>> tagStack;
    int lineNumber = 0;
    bool errorFound = false;

    while (getline(file, line)) {
        ++lineNumber;
        istringstream iss(line);
        while (iss >> word) {
            if (isOpeningTag(word)) {
                string tagName = extractTagName(word);
                tagStack.push({tagName, lineNumber});
            } else if (isClosingTag(word)) {
                string tagName = extractTagName(word);
                if (tagStack.empty()) {
                    cout << "Error at line " << lineNumber << ": Unexpected closing tag </" << tagName << ">\n";
                    errorFound = true;
                } else {
                    auto top = tagStack.top();
                    tagStack.pop();
                    if (top.first != tagName) {
                        cout << "Error at line " << lineNumber << ": Expected </" << top.first << "> but found </" << tagName << ">\n";
                        errorFound = true;
                    }
                }
            }
        }
    }

    while (!tagStack.empty()) {
        auto top = tagStack.top();
        tagStack.pop();
        cout << "Error: No closing tag found for <" << top.first << "> opened at line " << top.second << "\n";
        errorFound = true;
    }

    if (!errorFound) {
        cout << "No errors detected!\n";
    }

    return 0;
}
// 2.41. Stopper
// 2.41.1. Készítsünk stopperórát, amely a program indításától eltelt 
// időt írja ki folyamatosan! A program 11 másodperc után álljon meg! 
// 2.41.1.

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();
    double elapsedSeconds = 0.0;

    while (elapsedSeconds < 11.0) {
        auto now = steady_clock::now();
        elapsedSeconds = duration_cast<duration<double>>(now - start).count();

        std::cout << std::fixed << std::setprecision(3)
                  << "\rElapsed time: " << elapsedSeconds << " s" << std::flush;

        std::this_thread::sleep_for(milliseconds(100)); // kis késleltetés
    }

    std::cout << "\nStopwatch finished (11 seconds).\n";
    return 0;
}
// 2.41.2. Módosítsa a programot úgy, hogy csak minden egész másodpercben 
// írja ki az eltelt időt! 
// 2.41.2.

#include <iostream>
#include <chrono>
#include <thread>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();
    int lastPrintedSecond = -1;

    while (true) {
        auto now = steady_clock::now();
        int elapsedSeconds = duration_cast<seconds>(now - start).count();

        if (elapsedSeconds != lastPrintedSecond) {
            std::cout << elapsedSeconds << " seconds elapsed\n";
            lastPrintedSecond = elapsedSeconds;
        }

        if (elapsedSeconds >= 11) break;

        std::this_thread::sleep_for(milliseconds(50));
    }

    return 0;
}
// 2.42. Időpont formázása
// 2.42.1. Írjon programot, amely 10 másodpercen keresztül folytonosan kiírja 
// az aktuális időt ezredmásodperc pontossággal! Használja az _ftime és 
// ctime függvényeket! 
// 2.42.1.


#include <iostream>
#include <chrono>
#include <thread>
#include <ctime>
#include <iomanip>

int main() {
    using namespace std::chrono;

    auto start = steady_clock::now();

    while (duration_cast<seconds>(steady_clock::now() - start).count() < 10) {
        auto now = system_clock::now();
        auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

        std::time_t t = system_clock::to_time_t(now);
        std::tm* localTime = std::localtime(&t);

        std::cout << std::put_time(localTime, "%H:%M:%S") << "."
                  << std::setfill('0') << std::setw(3) << ms.count() << std::endl;

        std::this_thread::sleep_for(milliseconds(100));  // frissítés minden 100ms
    }

    return 0;
}
// 2.43. Tippelés
// 2.43.1. Írjon időtippelő programot! A program állítson elő egy véletlen 
// számot 1 és 5 között és ezt írja ki a képernyőre! Ennyi időt kell majd 
// várni a felhasználónak. Ezután kérjen be két sztringet úgy, hogy méri a 
// bekérések között eltelt időt! Írja ki, hogy ténylegesen mennyi idő telt 
// el a két bekérés között! Ha a bemenet a „quit” sztring, akkor lépjen 
// ki a programból! 
// 2.43.1.


#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <iomanip>



int main() {
    using namespace std;
    using namespace std::chrono;

    srand(static_cast<unsigned>(time(0)));

    string input;
    cout << "Press 'a' and enter to start the clock!" << endl;
    cout << "Do the same to stop it!" << endl;
    cout << "Type 'quit' to end program!" << endl;

    while (input != "quit") {
        int wait = rand() % 5 + 1; // 1 to 5
        cout << "\nWait for " << wait << " seconds!" << endl;

        cout << "Begin: ";
        cin >> input;
        if (input == "quit") break;

        auto start = steady_clock::now();

        cout << "End: ";
        cin >> input;
        auto end = steady_clock::now();

        if (input == "quit") break;

        duration<double> elapsed = end - start;
        cout << "You have waited " << fixed << setprecision(2)
             << elapsed.count() << " seconds instead of " << wait << ".\n";
    }

    return 0;
}
// 2.44. Milyen nap?
// 2.44.1. Írjon programot, amely véletlenszerűen meghatároz egy évet, 
// hónapot, napot és utána tippelni kell, hogy az a hét illetve év napjai 
// közül a hányadik! Adja meg hogy helyesek voltak-e a tippek! 
// 2.44.1.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>

int main() {
    int year, month, day, guessWeekDay, guessYearDay;
    std::tm tmBuffer = {};

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    year = std::rand() % 40 + 1970;
    month = std::rand() % 12 + 1;
    day = std::rand() % 30 + 1;

    tmBuffer.tm_year = year - 1900;  // tm_year: years since 1900
    tmBuffer.tm_mon = month - 1;     // tm_mon: 0-11
    tmBuffer.tm_mday = day;
    tmBuffer.tm_hour = 0;
    tmBuffer.tm_min = 0;
    tmBuffer.tm_sec = 0;
    tmBuffer.tm_isdst = -1;

    std::cout << "What is the day of the week on " << month << "/" << day << " " << year << "?\n";
    std::cout << "0 - Sunday, 1 - Monday, ..., 6 - Saturday\nYour guess: ";
    std::cin >> guessWeekDay;

    std::mktime(&tmBuffer);  // fills in tm_wday and tm_yday

    char buffer[30];
    std::strftime(buffer, sizeof(buffer), "%A", &tmBuffer);

    if (tmBuffer.tm_wday == guessWeekDay) {
        std::cout << "You are right! " << month << "/" << day << " " << year << " is really " << buffer << ".\n";
    } else {
        std::cout << "You are wrong. " << month << "/" << day << " " << year << " is " << buffer << ".\n";
    }

    std::cout << "\nWhat is the day of the year on the same date? ";
    std::cin >> guessYearDay;

    if (tmBuffer.tm_yday == guessYearDay) {
        std::cout << "You are right! " << month << "/" << day << " " << year
                  << " is the " << tmBuffer.tm_yday << "th day of the year.\n";
    } else {
        std::cout << "You are wrong. " << month << "/" << day << " " << year
                  << " is the " << tmBuffer.tm_yday << "th day of the year.\n";
    }

    return 0;
}
// 2.45. Hérón képlet
// 2.45.1. Írjon függvényt, amely a Hérón képlet segítségével kiszámolja 
// a háromszög területét! Dobjon float típusú kivételt, ha valamelyik oldal 
// változó negatív és dobjon const char* típusú kivételt, ha nem teljesül 
// a háromszög egyenlőtlenség! A kivételeket kezelje a main függvényben! 
// 2.45.1.


#include <iostream>
#include <cmath>

using namespace std;

float heron(float a, float b, float c) {
    if (a <= 0) throw a;
    if (b <= 0) throw b;
    if (c <= 0) throw c;
    if (a >= b + c || b >= a + c || c >= a + b)
        throw "No triangle can be constructed from the sides";

    float s = (a + b + c) / 2;
    float result = sqrt(s * (s - a) * (s - b) * (s - c));
    return result;
}

int main() {
    cout << "The program will calculate the area of a triangle." << endl;
    float area;

    try {
        area = heron(3, 2.54, 9);  // this should throw an exception
        cout << "Triangle area: " << area << endl;
    } catch (float para) {
        cout << "Triangle side can not be 0 or less, it is " << para << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    } catch (...) {
        cout << "Unknown error" << endl;
    }

    return 0;
}
// 2.46. Háromszög

// 2.46.1. Készítsen derékszögű háromszög osztályt, amelyben az adattagok 
// az oldalak! Írja meg a set és get függvényeket az adattagokra! Írja meg az 
// area, perimeter, check (ellenőrzi, hogy tényleg derékszögű-e a 
// háromszög) és display (kiírja az oldalak hosszát) függvényeket! 

// 2.46.1.


#include <iostream>
#include <cmath>
#include <iomanip> // std::boolalpha

using namespace std;

class RightAngleTriangle {
private:
    float a;
    float b;
    float c;

public:
    // Setters
    void setA(float para) { a = para; }
    void setB(float para) { b = para; }
    void setC(float para) { c = para; }

    // Getters
    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    // Methods
    bool check() const;
    float area() const;
    float perimeter() const;
    void display() const;
};

bool RightAngleTriangle::check() const {
    // Use a tolerance for floating-point comparison
    float epsilon = 1e-6;
    return fabs(a * a + b * b - c * c) < epsilon;
}

float RightAngleTriangle::area() const {
    return 0.5f * a * b;
}

float RightAngleTriangle::perimeter() const {
    return a + b + c;
}

void RightAngleTriangle::display() const {
    cout << boolalpha;
    cout << "The triangle is valid: " << check() << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    RightAngleTriangle myTriangle;
    myTriangle.setA(3);
    myTriangle.setB(4);
    myTriangle.setC(5);
    
    myTriangle.display();

    if (myTriangle.check()) {
        cout << "Area: " << myTriangle.area() << endl;
        cout << "Perimeter: " << myTriangle.perimeter() << endl;
    }

    return 0;
}
// 2.46.2. Készítsen hasonló osztályt egyenlő szárú háromszögre! 
// 2.46.2.


#include <iostream>
#include <cmath>
#include <iomanip> // boolalpha

using namespace std;

class IsoscelesTriangle {
private:
    float a, b, c;

public:
    // Setters
    void setA(float val) { a = val; }
    void setB(float val) { b = val; }
    void setC(float val) { c = val; }

    // Getters
    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    // Methods
    bool check() const;
    float area() const;
    float perimeter() const;
    void display() const;
};

bool IsoscelesTriangle::check() const {
    return (a == b || b == c || a == c);
}

float IsoscelesTriangle::area() const {
    // Heron-képlet (általános háromszögre is jó)
    float s = (a + b + c) / 2;
    float areaSquared = s * (s - a) * (s - b) * (s - c);
    return areaSquared > 0 ? sqrt(areaSquared) : 0;
}

float IsoscelesTriangle::perimeter() const {
    return a + b + c;
}

void IsoscelesTriangle::display() const {
    cout << boolalpha;
    cout << "The triangle is valid (isosceles): " << check() << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    IsoscelesTriangle myTriangle;
    myTriangle.setA(3);
    myTriangle.setB(3);
    myTriangle.setC(5);

    myTriangle.display();

    if (myTriangle.check()) {
        cout << "Area: " << myTriangle.area() << endl;
        cout << "Perimeter: " << myTriangle.perimeter() << endl;
    }

    return 0;
}
// 2.46.3. Készítsen hasonló osztályt szabályos háromszögre! 
// 2.46.3.


#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class EquilateralTriangle {
private:
    float a, b, c;

public:
    void setA(float val) { a = val; }
    void setB(float val) { b = val; }
    void setC(float val) { c = val; }

    float getA() const { return a; }
    float getB() const { return b; }
    float getC() const { return c; }

    bool check() const;
    float area() const;
    float perimeter() const;
    void display() const;
};

bool EquilateralTriangle::check() const {
    return (a == b && b == c);
}

float EquilateralTriangle::area() const {
    // Heron-képlet szabályos háromszögre is alkalmazható
    float s = (a + b + c) / 2;
    float areaSquared = s * (s - a) * (s - b) * (s - c);
    return areaSquared > 0 ? sqrt(areaSquared) : 0;
}

float EquilateralTriangle::perimeter() const {
    return a + b + c;
}

void EquilateralTriangle::display() const {
    cout << boolalpha;
    bool valid = check();
    cout << "The triangle is valid (equilateral): " << valid << endl;
    cout << "Sides: a = " << a << ", b = " << b << ", c = " << c << endl;
}

int main() {
    EquilateralTriangle myTriangle;
    myTriangle.setA(5);
    myTriangle.setB(5);
    myTriangle.setC(5);

    myTriangle.display();

    if (myTriangle.check()) {
        cout << "Area: " << myTriangle.area() << endl;
        cout << "Perimeter: " << myTriangle.perimeter() << endl;
    }

    return 0;
}
// 2.47. Statikus adattag
// 2.47.1. Készítsen osztályt, amelynek segítségével fájlba tud írni 
// sorokat! A fájlnevet tudjuk beállítani objektumonként és statikus adattag 
// számolja a program által eddig kiírt sorok számát! Lehessen ezt az 
// adattagot lenullázni és lekérdezni! 
// 2.47.1.

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Counter {
    char fileName[500];
    ofstream file;

public:
    static int lineCount;

    void init(const char* para);
    void close() { file.close(); }

    void write(const char* line);

    static int getLineCount() { return lineCount; }
    static void resetLineCount() { lineCount = 0; }
};

// statikus tag inicializálása
int Counter::lineCount = 0;

void Counter::init(const char* para) {
    strcpy(fileName, para);
    file.open(fileName);
    if (!file) {
        cerr << "Failed to open file: " << fileName << endl;
    }
}

void Counter::write(const char* line) {
    if (file.is_open()) {
        file << line << endl;
        lineCount++;
    } else {
        cerr << "File not open for writing: " << fileName << endl;
    }
}

int main() {
    Counter obj1, obj2;

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    obj1.init("file1.txt");
    obj1.write("The first line");
    obj1.write("And the second line");

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    obj2.init("file2.txt");
    obj2.write("New line");

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    Counter::resetLineCount();
    obj1.write("Strange line");

    cout << "The number of lines written till now: " << Counter::getLineCount() << endl;

    obj1.close();
    obj2.close();

    return 0;
}

// 2.47.2. Módosítsa az előző programot úgy, hogy számolja a szavak és 
// karakterek számát is! 
// 2.47.2.

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>

class Counter {
    char fileName[500];
    std::ofstream file;

public:
    static int lineCount;
    static int wordCount;
    static int charCount;

    void init(const char* para) {
        std::strcpy(fileName, para);
        file.open(fileName);
    }

    void close() {
        if (file.is_open()) file.close();
    }

    void write(const char* line) {
        if (!file.is_open()) return;

        int i = 0;
        bool inWord = false;

        while (line[i] != '\0') {
            file << line[i];
            charCount++;

            if (std::isspace(line[i])) {
                if (inWord) {
                    wordCount++;
                    inWord = false;
                }
            } else {
                inWord = true;
            }

            ++i;
        }

        if (inWord) {
            wordCount++;
        }

        file << std::endl;
        lineCount++;
    }
};

// statikus változók definíciója
int Counter::lineCount = 0;
int Counter::wordCount = 0;
int Counter::charCount = 0;

int main() {
    Counter obj1, obj2;

    std::cout << "Initial line count: " << Counter::lineCount << std::endl;

    obj1.init("file1.txt");
    obj1.write("The first line");
    obj1.write("and the second");

    std::cout << "After writing to file1.txt:" << std::endl;
    std::cout << "  Lines: " << Counter::lineCount << std::endl;
    std::cout << "  Words: " << Counter::wordCount << std::endl;
    std::cout << "  Characters: " << Counter::charCount << std::endl;

    obj2.init("file2.txt");
    obj2.write("New line");

    std::cout << "After writing to file2.txt:" << std::endl;
    std::cout << "  Lines: " << Counter::lineCount << std::endl;
    std::cout << "  Words: " << Counter::wordCount << std::endl;
    std::cout << "  Characters: " << Counter::charCount << std::endl;

    obj1.write("Strange line");

    std::cout << "Final statistics:" << std::endl;
    std::cout << "  Lines: " << Counter::lineCount << std::endl;
    std::cout << "  Words: " << Counter::wordCount << std::endl;
    std::cout << "  Characters: " << Counter::charCount << std::endl;

    obj1.close();
    obj2.close();

    return 0;
}
// 2.48.1. Írjon komplex szám osztályt! Használjon privát adattagokat! Írja 
// meg az add, sub, mul, div metódusokat! Az említett metódusok írják ki a 
// műveletek eredményét a képernyőre! 
// 2.48.1.


#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real, im;

    Complex multiply(const Complex&) const;

public:
    void setReal(float para) { real = para; }
    void setIm(float para) { im = para; }

    float getReal() const { return real; }
    float getIm() const { return im; }

    void display() const;

    void sum(const Complex&) const;
    void sub(const Complex&) const;
    void mul(const Complex&) const;
    void div(const Complex&) const;
};

// Display the complex number in standard form
void Complex::display() const {
    cout << real;
    if (im >= 0)
        cout << "+";
    cout << im << "i";
}

void Complex::sum(const Complex& para) const {
    float resultReal = real + para.real;
    float resultIm = im + para.im;
    cout << resultReal << (resultIm >= 0 ? "+" : "") << resultIm << "i";
}

void Complex::sub(const Complex& para) const {
    float resultReal = real - para.real;
    float resultIm = im - para.im;
    cout << resultReal << (resultIm >= 0 ? "+" : "") << resultIm << "i";
}

void Complex::mul(const Complex& para) const {
    float resultReal = real * para.real - im * para.im;
    float resultIm = im * para.real + real * para.im;
    cout << resultReal << (resultIm >= 0 ? "+" : "") << resultIm << "i";
}

Complex Complex::multiply(const Complex& para) const {
    float resultReal = real * para.real - im * para.im;
    float resultIm = im * para.real + real * para.im;

    Complex result;
    result.real = resultReal;
    result.im = resultIm;
    return result;
}

void Complex::div(const Complex& para) const {
    if (para.real == 0 && para.im == 0) {
        cout << "Error: division by zero.";
        return;
    }

    float denom = para.real * para.real + para.im * para.im;
    Complex recip;
    recip.real = para.real / denom;
    recip.im = -para.im / denom;

    Complex result = this->multiply(recip);
    cout << result.getReal() << (result.getIm() >= 0 ? "+" : "") << result.getIm() << "i";
}

// Main function to demonstrate operations
int main() {
    Complex a, b;
    a.setReal(1);
    a.setIm(2);

    b.setReal(3);
    b.setIm(4);

    a.display(); cout << " + "; b.display(); cout << " = ";
    a.sum(b); cout << endl;

    a.display(); cout << " - "; b.display(); cout << " = ";
    a.sub(b); cout << endl;

    a.display(); cout << " * "; b.display(); cout << " = ";
    a.mul(b); cout << endl;

    a.display(); cout << " / "; b.display(); cout << " = ";
    a.div(b); cout << endl;

    return 0;
}
// 2.48. Komplex számok
// 2.48.2. Módosítsa úgy a programot, hogy a metódusok ne végezzenek 
// kiírást, hanem adják vissza az eredményt objektumként! Valósítsa meg 
// kiíró operátort a komplex osztályra! 
// 2.48.2.


#include <iostream>

class Complex {
    float real, im;

    Complex multiply(const Complex& other) const {
        return Complex(
            real * other.real - im * other.im,
            real * other.im + im * other.real
        );
    }

public:
    Complex() : real(0), im(0) {}
    Complex(float r, float i) : real(r), im(i) {}

    void setReal(float val) { real = val; }
    void setIm(float val) { im = val; }

    float getReal() const { return real; }
    float getIm() const { return im; }

    Complex sum(const Complex& other) const {
        return Complex(real + other.real, im + other.im);
    }

    Complex sub(const Complex& other) const {
        return Complex(real - other.real, im - other.im);
    }

    Complex mul(const Complex& other) const {
        return Complex(
            real * other.real - im * other.im,
            real * other.im + im * other.real
        );
    }

    Complex div(const Complex& other) const {
        float denom = other.real * other.real + other.im * other.im;
        if (denom == 0.0f) {
            std::cerr << "Error: division by zero." << std::endl;
            return Complex();
        }
        Complex reciprocal(other.real / denom, -other.im / denom);
        return multiply(reciprocal);
    }

    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        os << "(" << obj.real << " + " << obj.im << "i)";
        return os;
    }
};

int main() {
    Complex a, b;
    a.setReal(1);
    a.setIm(2);
    b.setReal(3);
    b.setIm(4);

    std::cout << a << " + " << b << " = " << a.sum(b) << std::endl;
    std::cout << a << " - " << b << " = " << a.sub(b) << std::endl;
    std::cout << a << " * " << b << " = " << a.mul(b) << std::endl;
    std::cout << a << " / " << b << " = " << a.div(b) << std::endl;

    return 0;
}
// 2.48.3. Valósítsa meg az aritmetikai függvényeket operátorok 
// segítségével! 
// 2.48.3.


#include <iostream>
#include <iomanip>

class Complex {
    float real, im;

    Complex multiply(const Complex& other) const {
        Complex result;
        result.real = real * other.real - im * other.im;
        result.im = im * other.real + real * other.im;
        return result;
    }

public:
    Complex() : real(0), im(0) {}
    Complex(float r, float i) : real(r), im(i) {}

    void setReal(float val) { real = val; }
    void setIm(float val) { im = val; }

    float getReal() const { return real; }
    float getIm() const { return im; }

    void display() const {
        std::cout << real << " + " << im << "i";
    }

    Complex sum(const Complex& other) const {
        return Complex(real + other.real, im + other.im);
    }

    Complex sub(const Complex& other) const {
        return Complex(real - other.real, im - other.im);
    }

    Complex mul(const Complex& other) const {
        return Complex(real * other.real - im * other.im,
                       real * other.im + im * other.real);
    }

    Complex div(const Complex& other) const {
        Complex result;
        float denom = other.real * other.real + other.im * other.im;
        if (denom == 0.0f) {
            std::cerr << "Error: division by zero.\n";
            return result;
        }
        Complex recip(other.real / denom, -other.im / denom);
        return this->multiply(recip);
    }

    // Operator overloads
    Complex operator+(const Complex& other) const { return sum(other); }
    Complex operator-(const Complex& other) const { return sub(other); }
    Complex operator*(const Complex& other) const { return mul(other); }
    Complex operator/(const Complex& other) const { return div(other); }

    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        os << "(" << obj.real << " + " << obj.im << "i)";
        return os;
    }
};

int main() {
    Complex a(1, 2);
    Complex b(3, 4);

    std::cout << std::fixed << std::setprecision(2);

    std::cout << a << " + " << b << " = " << (a + b) << "\n";
    std::cout << a << " - " << b << " = " << (a - b) << "\n";
    std::cout << a << " * " << b << " = " << (a * b) << "\n";
    std::cout << a << " / " << b << " = " << (a / b) << "\n";

    return 0;
}
// 2.49. Telefonszámla
// 2.49.1. Írjon programot egy telefontársaság számára, ami az egyes 
// előfizetők telefonszámláit szeretné kiszámolni! Az előfizetők adatai az 
// „in.txt” nevű fájlban tárolja! A program készítsen felsorolást minden 
// előfizető számára, amelynek tartalmaznia kell a teljes beszélgetési 
// időt, és a fizetendő összeget! Ezután a program számolja ki, melyik 
// előfizető telefonált összesen a legtöbb ideig, ez milyen hosszú idő, 
// kinek kell a legtöbbet fizetni, és mennyit! Használjon dinamikus tömböket! 
// Feltételezzük, hogy a bemeneti fájl az előírásoknak megfelelő. Az input 
// formátuma: Első sor: az előfizetők száma Második sor: két tízes 
// számrendszerbeli szám, a csúcsidőben való telefonálás tarifája, és a 
// csúcsidőn kívüli telefonálás tarifája. A többi sor az előfizetők 
// adatait tárolja: az előfizető neve (keresztnév, vezetéknév), majd két 
// tízes számrendszerbeli szám: mennyi időt telefonált az illető 
// csúcsidőben, illetve csúcsidőn kívül. Mind a keresztnév, mind a 
// vezetéknév maximum 10 karakterből áll. Példa bemenet: 2 3 1 csúcsidőn 
// kívül Bela Kovacs 731 123 123 percet csúcsidőn kívül Mihaly Toth 300 35 
// Kimenet: Bela Kovacs: Mihaly Toth: 2316 Ft 935 Ft 854 minute 335 minute Highest 
// fee: 2316 Ft Bela Kovacs Longest speaking: 854 Ft Bela Kovacs
// 2.49.1.
 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

struct Subscriber {
    std::string firstName;
    std::string lastName;
    int inRushMinutes;
    int outRushMinutes;
    int totalMinutes;
    int fee;
};

void readSubscribers(std::ifstream& file, int count, std::vector<Subscriber>& subs) {
    for (int i = 0; i < count; ++i) {
        Subscriber s;
        file >> s.firstName >> s.lastName >> s.inRushMinutes >> s.outRushMinutes;
        subs.push_back(s);
    }
}

void calculateFeesAndPrint(const std::vector<Subscriber>& subs, int rushTariff, int offTariff) {
    int maxFee = 0;
    int maxMinutes = 0;

    std::vector<const Subscriber*> maxFeeSubs;
    std::vector<const Subscriber*> maxMinSubs;

    for (const auto& s : subs) {
        int total = s.inRushMinutes + s.outRushMinutes;
        int fee = s.inRushMinutes * rushTariff + s.outRushMinutes * offTariff;

        std::cout << std::setw(20) << s.firstName + " " + s.lastName << ": "
                  << std::setw(6) << fee << " Ft, "
                  << std::setw(4) << total << " minute\n";

        if (fee > maxFee) {
            maxFee = fee;
            maxFeeSubs.clear();
            maxFeeSubs.push_back(&s);
        } else if (fee == maxFee) {
            maxFeeSubs.push_back(&s);
        }

        if (total > maxMinutes) {
            maxMinutes = total;
            maxMinSubs.clear();
            maxMinSubs.push_back(&s);
        } else if (total == maxMinutes) {
            maxMinSubs.push_back(&s);
        }
    }

    std::cout << "\nHighest fee: " << maxFee << " Ft\n";
    for (const auto* s : maxFeeSubs)
        std::cout << "\t" << s->firstName << " " << s->lastName << "\n";

    std::cout << "\nLongest speaking: " << maxMinutes << " minute\n";
    for (const auto* s : maxMinSubs)
        std::cout << "\t" << s->firstName << " " << s->lastName << "\n";
}

int main() {
    std::ifstream file("in.txt");
    if (!file) {
        std::cerr << "Failed to open file 'in.txt'\n";
        return 1;
    }

    int count, rushTariff, offTariff;
    file >> count >> rushTariff >> offTariff;

    std::vector<Subscriber> subscribers;
    readSubscribers(file, count, subscribers);
    file.close();

    calculateFeesAndPrint(subscribers, rushTariff, offTariff);

    return 0;
}
// 2.50. Halmazok metszete
// 2.50.1. Írjon programot, amely két halmaz metszetét generálja! Mindkét 
// halmaz egész számokat tartalmaz. A program olvassa be az input fájlt! 
// Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám 
// eleme-e az első halmaznak, a második halmaznak, illetve ezek metszetének! 
// Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy 
// az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon 
// dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz 
// mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz 
// mérete Negyedik sor: a második halmaz elemei A számok egy-egy szóköz 
// karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 
// Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is not 
// element of intersection of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} 
// Intersection of A and B = {41, 54, 80} B is not subset of A A is subset of B 
// 2.50.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void readSet(std::ifstream& file, std::vector<int>& set) {
    int size;
    file >> size;
    set.resize(size);
    for (int i = 0; i < size; ++i) {
        file >> set[i];
    }
}

void printSet(const std::string& name, const std::vector<int>& set) {
    std::cout << name << " = {";
    for (size_t i = 0; i < set.size(); ++i) {
        std::cout << set[i];
        if (i != set.size() - 1)
            std::cout << ", ";
    }
    std::cout << "}\n";
}

bool elementOf(int num, const std::vector<int>& set) {
    return std::find(set.begin(), set.end(), num) != set.end();
}

std::vector<int> intersection(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> result;
    for (int val : A) {
        if (elementOf(val, B) && !elementOf(val, result))
            result.push_back(val);
    }
    return result;
}

bool isSubset(const std::vector<int>& A, const std::vector<int>& B) {
    for (int val : A) {
        if (!elementOf(val, B))
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::string inputFile = (argc > 1) ? argv[1] : "sets.txt";
    std::ifstream file(inputFile);

    if (!file) {
        std::cerr << "Error: could not open file: " << inputFile << "\n";
        return 1;
    }

    std::vector<int> A, B;
    readSet(file, A);
    readSet(file, B);
    file.close();

    std::vector<int> I = intersection(A, B);

    int num;
    std::cout << "Type a number: ";
    std::cin >> num;

    std::cout << num << (elementOf(num, A) ? " is" : " is not") << " element of A\n";
    std::cout << num << (elementOf(num, B) ? " is" : " is not") << " element of B\n";
    std::cout << num << (elementOf(num, I) ? " is" : " is not") << " element of intersection of A and B\n";

    printSet("A", A);
    printSet("B", B);
    printSet("Intersection of A and B", I);

    std::cout << (isSubset(B, A) ? "B is" : "B is not") << " subset of A\n";
    std::cout << (isSubset(A, B) ? "A is" : "A is not") << " subset of B\n";

    return 0;
}
// 2.51. Halmazok uniója
// 2.51.1. Írjon programot, amely két halmaz unióját generálja! Mindkét 
// halmaz egész számokat tartalmaz! A program olvassa be az input fájlt. 
// Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám 
// eleme-e az első halmaznak, a második halmaznak, illetve ezek uniójának! 
// Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy 
// az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon 
// dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz 
// mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz 
// mérete Negyedik sor: a második halmaz elemei A számok egy-egy space 
// karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 
// Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is 
// element of union of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} Union of 
// A and B = {41, 21, 54, 76, 80} B is not subset of A A is subset of B 
// 2.51.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

void readSet(std::ifstream& file, std::vector<int>& set) {
    int size, value;
    file >> size;
    for (int i = 0; i < size; ++i) {
        file >> value;
        set.push_back(value);
    }
}

void printSet(const std::string& name, const std::vector<int>& set) {
    std::cout << name << " = {";
    for (size_t i = 0; i < set.size(); ++i) {
        std::cout << set[i];
        if (i != set.size() - 1) std::cout << ", ";
    }
    std::cout << "}\n";
}

bool contains(int value, const std::vector<int>& set) {
    return std::find(set.begin(), set.end(), value) != set.end();
}

std::vector<int> unionSet(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> result = A;
    for (int val : B) {
        if (!contains(val, result)) {
            result.push_back(val);
        }
    }
    return result;
}

bool isSubset(const std::vector<int>& sub, const std::vector<int>& full) {
    for (int val : sub) {
        if (!contains(val, full)) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::string filename = (argc > 1) ? argv[1] : "sets.txt";
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Failed to open file: " << filename << "\n";
        return 1;
    }

    std::vector<int> A, B;
    readSet(file, A);
    readSet(file, B);
    file.close();

    std::vector<int> U = unionSet(A, B);

    int number;
    std::cout << "Type a number: ";
    std::cin >> number;

    std::cout << number << (contains(number, A) ? " is" : " is not") << " element of A\n";
    std::cout << number << (contains(number, B) ? " is" : " is not") << " element of B\n";
    std::cout << number << (contains(number, U) ? " is" : " is not") << " element of union of A and B\n";

    printSet("A", A);
    printSet("B", B);
    printSet("Union of A and B", U);

    std::cout << (isSubset(B, A) ? "B is" : "B is not") << " subset of A\n";
    std::cout << (isSubset(A, B) ? "A is" : "A is not") << " subset of B\n";

    return 0;
}
// 2.52. Halmazok különbsége
// 2.52.1. Írjon programot, amely két halmaz különbségét generálja! 
// Mindkét halmaz egész számokat tartalmaz. A program olvassa be az input 
// fájlt! Kérjen be egy számot a billentyűzetről, és döntse el, hogy a 
// szám eleme-e az első halmaznak, a második halmaznak, az A\B vagy a B\A 
// halmaznak! Írassa ki a képernyőre az előbbi négy halmazt! Végül írassa 
// ki, hogy az első halmaz részhalmaza-e a másodiknak, illetve fordítva! 
// Használjon dinamikus tömböket! Az input fájl formátuma: Első sor: az 
// első halmaz mérete Második sor: az első halmaz elemei Harmadik sor: a 
// második halmaz mérete Negyedik sor: a második halmaz elemei A számok 
// egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 
// 41 21 54 76 80 Kimenet: Type a number: 76 76 is not element of A 76 is element 
// of B 76 is not element of A \ B 76 is element of B \ A A = {80, 54, 41} B = 
// {41, 21, 54, 76, 80} Set difference A\B = {} Set difference B\A = {21, 76} B is 
// not subset of A A is subset of B 
// 2.52.1.


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void ReadSet(std::ifstream& in, std::vector<int>& set) {
    int size;
    in >> size;
    set.resize(size);
    for (int i = 0; i < size; ++i) {
        in >> set[i];
    }
}

void PrintSet(const std::string& name, const std::vector<int>& set) {
    std::cout << name << " = {";
    for (size_t i = 0; i < set.size(); ++i) {
        std::cout << set[i];
        if (i != set.size() - 1) std::cout << ", ";
    }
    std::cout << "}\n";
}

bool Element(int e, const std::vector<int>& set) {
    return std::find(set.begin(), set.end(), e) != set.end();
}

std::vector<int> SetDifference(const std::vector<int>& A, const std::vector<int>& B) {
    std::vector<int> result;
    for (int a : A) {
        if (!Element(a, B)) {
            result.push_back(a);
        }
    }
    return result;
}

bool IsSubset(const std::vector<int>& A, const std::vector<int>& B) {
    for (int a : A) {
        if (!Element(a, B)) return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    std::ifstream file(argc > 1 ? argv[1] : "sets.txt");
    if (!file) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::vector<int> A, B;
    ReadSet(file, A);
    ReadSet(file, B);
    file.close();

    std::vector<int> AminusB = SetDifference(A, B);
    std::vector<int> BminusA = SetDifference(B, A);

    int num;
    std::cout << "Type a number: ";
    std::cin >> num;

    std::cout << num << (Element(num, A) ? " is" : " is not") << " element of A\n";
    std::cout << num << (Element(num, B) ? " is" : " is not") << " element of B\n";
    std::cout << num << (Element(num, AminusB) ? " is" : " is not") << " element of A \\ B\n";
    std::cout << num << (Element(num, BminusA) ? " is" : " is not") << " element of B \\ A\n";

    PrintSet("A", A);
    PrintSet("B", B);
    PrintSet("Set difference A\\B", AminusB);
    PrintSet("Set difference B\\A", BminusA);

    std::cout << (IsSubset(B, A) ? "B is subset of A\n" : "B is not subset of A\n");
    std::cout << (IsSubset(A, B) ? "A is subset of B\n" : "A is not subset of B\n");

    return 0;
}
// 2.53. Binomiális tétel
// 2.53.1. Írjon programot, amely beolvas egy n értéket a billentyűzetről, 
// majd a binomiális tétel jobb oldalának kifejtett alakját kiírja a 
// képernyőre! n ne legyen nagyobb 10-nél! A binomiális tétel szerint: (a + 
// b)n = ahol n pozitív egész szám, és (a + b)n = Példa bemenet: n=3 Kimenet: 
// ( a + b )^3 = a^3 + 3ba^2 + 3b^2a + b^3 
// 2.53.1.


#include <iostream>
#include <cstdlib>

using ULint = unsigned long int;

ULint BinomialCoefficient(int n, int k) {
    ULint bc = 1;
    for (int i = 1; i <= k; ++i) {
        bc *= n--;
        bc /= i;
    }
    return bc;
}

void PrintPow(char ch, int p) {
    if (p == 0) return;
    if (p == 1) std::cout << ch;
    else std::cout << ch << "^" << p;
}

void PrintBinom(int n) {
    std::cout << "(a + b)^" << n << " = ";
    for (int i = 0; i <= n; ++i) {
        ULint coeff = BinomialCoefficient(n, i);

        // Ne írjuk ki az 1-est
        if (coeff > 1) std::cout << coeff;

        PrintPow('b', i);
        PrintPow('a', n - i);

        if (i < n) std::cout << " + ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    int n;

    if (argc > 1) {
        n = std::atoi(argv[1]);
    } else {
        std::cout << "Degree (max 10): ";
        std::cin >> n;
    }

    if (n < 0 || n > 10) {
        std::cerr << "Error: n must be between 0 and 10.\n";
        return 1;
    }

    PrintBinom(n);
    return 0;
}
// 2.54. Hazárdjáték
// 2.54.1. Írjon hazárdjátékot! A szabályok a következők: A játék 
// kezdetekor a játékosnak 1000 Ft-ja van. A program generál egy véletlen 
// számot, a játékosnak pedig meg kell adnia egy tippet, és egy tétet. Ha 
// eltalálja a számot, megkapja a tét összegét, ha nem, elveszíti. Ezután a 
// program megkérdezi: „Try again? (y/n)”, a játékosnak pedig egy „y” 
// vagy egy „n” karakterrel kell válaszolnia. Ha újból próbálkozik, akkor 
// a program új számot generál. A játék addig folytatódik, amíg a 
// játékosnak van pénze, vagy amíg nem szeretné befejezni a játékot. 3 
// különböző szint van: a „könnyű”, amelyben a program 1 és 5 közötti 
// számot generál, a „közepes”, amelyben 1 és 10 közötti számot 
// generál, és a „nehéz”, amelyben 1 és 15 közötti számot generál. A 
// szintet a játék megkezdése előtt választja ki a játékos, egy egyszerű 
// menü segítségével. A játék végén a program írja ki a képernyőre, 
// mennyit nyert vagy veszített a játékos. Példa játék: Choose the 
// difficulty! Easy:...........1 Medium:.........2 Hard:...........3 2 You have 
// 1000 HUF now. Take your stake: 10 What's your tip (1..10)? 5 You've hit the 
// number! You have 1010 HUF! Try again? (y/n) y Take your stake: 1000 What's your 
// tip (1..10)? 1 The number was 7 You have 10 HUF! Try again? (y/n) n 
// Congratulations! You get 10 HUF! 

// 2.54.1.

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

const int MIN_TIP = 1;
const int EASY_MAX = 5;
const int MEDIUM_MAX = 10;
const int HARD_MAX = 15;
const int START_MONEY = 1000;

int getStake() {
    int stake;
    do {
        std::cout << "Take your stake: ";
        std::cin >> stake;
        if (stake <= 0)
            std::cout << "The stake must be greater than zero!\n";
    } while (stake <= 0);
    return stake;
}

int getTip(int min, int max) {
    int tip;
    do {
        std::cout << "What's your tip (" << min << ".." << max << ")? ";
        std::cin >> tip;
        if (tip < min || tip > max)
            std::cout << "The tip must be between " << min << " and " << max << "!\n";
    } while (tip < min || tip > max);
    return tip;
}

int getMax() {
    int difficulty;
    do {
        std::cout << "Choose the difficulty!\n\n";
        std::cout << "\tEasy:...........1\n";
        std::cout << "\tMedium:.........2\n";
        std::cout << "\tHard:...........3\n\n";
        std::cin >> difficulty;
        if (difficulty < 1 || difficulty > 3)
            std::cout << "Wrong number!\n";
    } while (difficulty < 1 || difficulty > 3);

    switch (difficulty) {
        case 1: return EASY_MAX;
        case 2: return MEDIUM_MAX;
        case 3: return HARD_MAX;
    }
    return 0; // Should never reach here
}

int getRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    int money = START_MONEY;
    int maxRange = getMax();
    std::cout << "You have " << money << " HUF now.\n";

    std::string again;

    do {
        std::cout << "\n\n";
        int stake = getStake();
        if (stake > money) {
            std::cout << "You don't have enough money! Try again.\n";
            continue;
        }

        int num = getRandom(MIN_TIP, maxRange);
        int tip = getTip(MIN_TIP, maxRange);

        if (tip == num) {
            money += stake;
            std::cout << "You've hit the number!\nYou have " << money << " HUF!\n";
        } else {
            std::cout << "The number was " << num << "\n";
            money -= stake;
            std::cout << "You have " << money << " HUF!\n";
        }

        if (money > 0) {
            std::cout << "Try again? (y/n): ";
            std::cin >> again;
        }

    } while ((money > 0) && (again[0] == 'y' || again[0] == 'Y'));

    if (money > 0)
        std::cout << "Congratulations!\nYou get " << money << " HUF!\n";
    else
        std::cout << "I'm sorry, you lost everything.\n";

    return 0;
}
// 2.55. Dátumellenőrzés
// 2.55.1. Írjon programot, amely beolvas egy dátumot egy fájlból, 
// szintaktikai és szemantikai ellenőrzést végez rajta és kiírja az 
// esetleges hibákat! Szintaktikai ellenőrzés: A dátum 3 számot tartalmaz, 
// mindegyik szám után egy pont szerepel. A számok csak számjegyet 
// tartalmazhatnak! Például a „2007.” megfelelő, de a következők nem: 
// „2A07.”, „2007”. Szemantikai ellenőrzés: Akkor hajtódik végre, ha a 
// szintaktikai ellenőrzés nem jelzett hibát. A hónap értéke 1 és 12 közt, 
// a napé 1 és 31 közt változhat. Ha az értékek valamelyike hibás, ezt a 
// program írja ki a képernyőre. Az input fájl formátuma: Év. Hónap. Nap. 
// Példa bemenet: 2007. 12. 31. Kimenet: 2007. 12. 31. 
// ******************************* I found 0 errors Példa bemenet: 2007 1u2. 31 
// Kimenet: 2007 1u2. 31 Error: A "." have to follow the number, not "7"! Error: 
// the Month cannot contain u character! Error: A "." have to follow the number, 
// not "1"! ******************************* I found 3 errors Példa bemenet: 2007. 
// 13. 0. Kimenet: 2007. 13. 0. Error: There are only 12 months! Error: There are 
// at most 31, at least 1 days in a month! ******************************* I found 
// 1 errors 
// 2.55.1.



#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cctype>

#define DEFAULT_INPUTFILE "date.txt"
#define DOT '.'
#define MAX_LENGTH 10

struct TDate {
    std::string Year;
    std::string Month;
    std::string Day;
};

void InitDate(TDate& date) {
    date.Year.clear();
    date.Month.clear();
    date.Day.clear();
}

void ReadDate(std::ifstream& file, TDate& date) {
    file >> date.Year >> date.Month >> date.Day;
}

void PrintDate(const TDate& date) {
    std::cout << date.Year << " " << date.Month << " " << date.Day << "\n";
}

int CheckNumAndDots(const std::string& str, const std::string& label) {
    int errors = 0;
    int len = str.length();

    for (int i = 0; i < len - 1; ++i) {
        if (!std::isdigit(str[i])) {
            std::cout << "Error: the " << label << " cannot contain " << str[i] << " character!\n";
            ++errors;
        }
    }

    if (str[len - 1] != DOT) {
        std::cout << "Error: A \"" << DOT << "\" has to follow the number, not \"" << str[len - 1] << "\"!\n";
        ++errors;
    }

    return errors;
}

int CheckNums(const TDate& date) {
    int errors = 0;

    int month = std::atoi(date.Month.c_str());
    int day = std::atoi(date.Day.c_str());

    if (month < 1 || month > 12) {
        std::cout << "Error: There are only 12 months!\n";
        ++errors;
    }

    if (day < 1 || day > 31) {
        std::cout << "Error: There are at most 31, at least 1 days in a month!\n";
        ++errors;
    }

    return errors;
}

void CheckDate(const TDate& date) {
    int errors = 0;
    errors += CheckNumAndDots(date.Year, "Year");
    errors += CheckNumAndDots(date.Month, "Month");
    errors += CheckNumAndDots(date.Day, "Day");

    if (errors == 0) {
        errors += CheckNums(date);
    }

    std::cout << "*******************************\n";
    std::cout << "I found " << errors << " error(s)\n";
}

int main(int argc, char* argv[]) {
    TDate date;
    InitDate(date);

    std::ifstream file(argc > 1 ? argv[1] : DEFAULT_INPUTFILE);
    if (!file) {
        std::perror("Error opening file");
        return 1;
    }

    ReadDate(file, date);
    file.close();

    PrintDate(date);
    CheckDate(date);

    return 0;
}
// 2.55.2. Írja át az előző programot úgy, hogy csak szemantikai ellenőrzés 
// legyen, de abból szigorúbb! Az év 1000 és 3000 közti érték lehet. A 
// hónap 1 és 12 közti érték lehet. A nap értéke 1 és 31 között lehet 
// januárban, márciusban, májusban, júliusban, augusztusban, októberben és 
// decemberben. A nap értéke 1 és 30 közti értéket vehet fel áprilisban, 
// júniusban, szeptemberben és novemberben. Ha az év szökőév, februárban a 
// nap értéke 1 és 29 közt lehet, ha nem, akkor 1 és 28 között. Szökőév 
// minden 4-gyel osztható év, de a 100-zal oszthatóak nem. A 400-zal osztható 
// évek mindig szökőévek. Például 1992, 1996, 2000, 1600 szökőév, de 
// 1800, 1900 nem az. A program elsőként az évet és a hónapot ellenőrizze, 
// majd ha ezek megfelelőek, akkor a napot is! Írja ki a képernyőre a 
// felfedezett hibákat! 
// 2.55.2.


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#define DEFAULT_INPUTFILE "date.txt"
#define YEAR_MIN 1000
#define YEAR_MAX 3000
#define MONTH_MAX 12
#define DAY_MAX 31

const std::string Months_Strings[12] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

enum Months { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };

struct TDate {
    int Year;
    int Month;
    int Day;
};

bool LeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int CheckYear(int y) {
    int errors = 0;
    if (y < YEAR_MIN) {
        std::cout << "Error: " << y << " is too low for the year!\n";
        errors++;
    }
    if (y > YEAR_MAX) {
        std::cout << "Error: " << y << " is too high for the year!\n";
        errors++;
    }
    return errors;
}

int CheckMonth(int m) {
    int errors = 0;
    if (m < 1) {
        std::cout << "Error: " << m << " is too low for the month!\n";
        errors++;
    }
    if (m > MONTH_MAX) {
        std::cout << "Error: " << m << " is too high for the month!\n";
        errors++;
    }
    return errors;
}

int CheckDay(const TDate& date) {
    int errors = 0;
    switch (date.Month) {
        case jan: case mar: case may: case jul: case aug: case oct: case dec:
            if (date.Day < 1 || date.Day > 31) {
                std::cout << "Error: In " << Months_Strings[date.Month - 1] << " there are 31 days!\n";
                errors++;
            }
            break;
        case apr: case jun: case sep: case nov:
            if (date.Day < 1 || date.Day > 30) {
                std::cout << "Error: In " << Months_Strings[date.Month - 1] << " there are 30 days!\n";
                errors++;
            }
            break;
        case feb:
            if (LeapYear(date.Year)) {
                if (date.Day < 1 || date.Day > 29) {
                    std::cout << "Error: In " << date.Year << " " << Months_Strings[date.Month - 1] << " there are 29 days!\n";
                    errors++;
                }
            } else {
                if (date.Day < 1 || date.Day > 28) {
                    std::cout << "Error: In " << date.Year << " " << Months_Strings[date.Month - 1] << " there are 28 days!\n";
                    errors++;
                }
            }
            break;
        default:
            std::cout << "Invalid month!\n";
            errors++;
    }
    return errors;
}

void ReadDate(std::ifstream& file, TDate& date) {
    char dot;
    file >> date.Year >> dot >> date.Month >> dot >> date.Day;
}

void PrintDate(const TDate& date) {
    std::cout << "Year: " << date.Year << "\n";
    if (date.Month >= 1 && date.Month <= 12)
        std::cout << "Month: " << Months_Strings[date.Month - 1] << "\n";
    else
        std::cout << "Month: Invalid\n";
    std::cout << "Day: " << date.Day << "\n";
}

void CheckDate(const TDate& date) {
    int errors = 0;
    errors += CheckYear(date.Year);
    errors += CheckMonth(date.Month);
    if (errors == 0) {
        errors += CheckDay(date);
    }
    std::cout << "*******************************\n";
    std::cout << "I found " << errors << " error(s)\n";
}

int main(int argc, char* argv[]) {
    std::ifstream file(argc > 1 ? argv[1] : DEFAULT_INPUTFILE);
    if (!file) {
        std::perror("Error opening file");
        return 1;
    }

    TDate date;
    ReadDate(file, date);
    file.close();

    PrintDate(date);
    CheckDate(date);

    return 0;
}
// 2.56. Pascal háromszög
// 2.56.1. Írjon programot, amely kiírja a képernyőre a Pascal háromszög 
// első 10 sorát! Két szám között 4 szóköz karakter legyen! Az r-edik sor 
// i-edik tagját számolja a következőképlettel: r! / ( i! * ( r - i )! ) 
// Kimenet: 1 1 1 1 1 1 1 9 1 1 8 7 1 6 1 5 4 2 3 6 1 3 4 1 5 1 6 1 7 1 8 1 9 1 1 
// 2.56.1.


#include <iostream>
#include <iomanip>
#include <cstdlib>

const int DEFAULT_ROWNUM = 10;
const int SPACE_WIDTH = 4;

int BinomialCoefficient(int n, int k) {
    int bc = 1;
    if (k == 0 || k == n) return 1;
    for (int i = 1; i <= k; ++i) {
        bc *= n--;
        bc /= i;
    }
    return bc;
}

int GetRowWidth(int n) {
    return n * 3 + (n - 1) * SPACE_WIDTH;
}

void PascalsTriangle(int rows) {
    int triangleWidth = GetRowWidth(rows);
    for (int r = 0; r < rows; ++r) {
        int rowWidth = GetRowWidth(r + 1);
        int spaces = (triangleWidth - rowWidth) / 2;
        std::cout << std::string(spaces, ' ');

        for (int i = 0; i <= r; ++i) {
            std::cout << std::setw(3) << BinomialCoefficient(r, i);
            std::cout << std::string(SPACE_WIDTH, ' ');
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    int rows = (argc > 1) ? std::atoi(argv[1]) : DEFAULT_ROWNUM;
    PascalsTriangle(rows);
    return 0;
}
// 2.57. Lottó
// 2.57.1. Írjon lottó-generáló programot! A program generáljon 1 és 90 
// között 5 különböző pozitív egész számot! Egy fájl tippeket tartalmaz. 
// Olvassa be a tippeket a fájlból, majd hasonlítsa össze őket a generált 
// számokkal! Írja ki a képernyőre a generált nyerőszámokat, és azt, hogy 
// hány embernek van 1-es, 2-es, 3as, 4-es, illetve 5-ös találata a lottón! Az 
// input fájl formátuma: Első sor: a tippek száma Minden további sor 5 tippet 
// tartalmaz, szóköz karakterekkel elválasztva. Példa bemenet: 6 5 64 23 80 42 
// 4 34 44 62 72 75 43 3 64 80 53 52 21 56 10 1 37 87 9 53 75 10 64 69 78 Kimenet: 
// Generated numbers: 55, 64, 68, 75, 50 There is 1 1 hit There are 2 2 hits There 
// is 0 3 hit There is 0 4 hit There is 0 5 hit 
// 2.57.1.

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>

const std::string DEFAULT_INPUTFILE = "tipp1.txt";

void getNumbers(std::vector<int>& numbers) {
    numbers.clear();
    while (numbers.size() < 5) {
        int num = rand() % 90 + 1;
        if (std::find(numbers.begin(), numbers.end(), num) == numbers.end()) {
            numbers.push_back(num);
        }
    }
    std::sort(numbers.begin(), numbers.end());
}

void printNumbers(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[i];
        if (i < numbers.size() - 1)
            std::cout << ", ";
    }
    std::cout << "\n";
}

void initHits(std::vector<int>& hits) {
    hits.assign(5, 0);
}

void check(std::ifstream& file, const std::vector<int>& draw, std::vector<int>& hits) {
    int count;
    file >> count;

    for (int i = 0; i < count; ++i) {
        std::set<int> tip;
        for (int j = 0; j < 5; ++j) {
            int num;
            file >> num;
            tip.insert(num);
        }

        int match = 0;
        for (int num : draw) {
            if (tip.count(num)) {
                ++match;
            }
        }

        if (match > 0 && match <= 5) {
            hits[match - 1]++;
        }
    }
}

void printHits(const std::vector<int>& hits) {
    for (size_t i = 0; i < hits.size(); ++i) {
        std::cout << "There ";
        if (hits[i] == 1)
            std::cout << "is ";
        else
            std::cout << "are ";
        std::cout << hits[i] << " " << (i + 1) << " hit";
        if (hits[i] != 1) std::cout << "s";
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    std::ifstream file(argc > 1 ? argv[1] : DEFAULT_INPUTFILE);
    if (!file) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::vector<int> numbers;
    std::vector<int> hits(5);

    getNumbers(numbers);
    initHits(hits);

    std::cout << "Generated numbers: ";
    printNumbers(numbers);

    check(file, numbers, hits);
    printHits(hits);

    file.close();
    return 0;
}
// 2.58. Hanoi tornyai
// 2.58.1. A Hanoi tornyai játék 3 rudat tartalmaz (start, segéd, cél). Az 
// első rúdon N db korong van egymás fölött, amelyek különböző 
// méretűek. A korongok fentről lefelé növekvő sorrendben következnek, 
// legnagyobb van legalul, a legkisebb legfelül, ahogyan az ábrán látható. A 
// feladat a következő: a korongokat át kell rakni a start rúdról a célra, a 
// segédrúd segítségével. Az átrakás szabálya, hogy nagyobb korongot 
// kisebbre nem rakhatunk rá. Írjon programot ennek a feladatnak a 
// szimulálására! A program argumentumként megkapja N értékét. Kezdetben 
// minden korong a start rúdon van. Minden lépésben kérdezze meg, melyik 
// rúdról melyikre tegyük át a legfelső korongot! Ha ez nem ellenkezik a 
// szabályokkal, helyezzük át a korongot! Minden mozgatás után írja ki a 
// képernyőre a korongok helyzetét, a példában látható módon! Ha a 
// felhasználó 0-t gépel, vagy minden korong a cél rúdon van, a program 
// véget ér. Használjon dinamikus tömböket és struktúrákat a korongok 
// helyének tárolására! 2.4. ábra: Hanoi tornyai szemléltetése Példa 
// bemenet: ************************************* Source: 3, 2, 1 Auxiliary: 0 
// Destination: 0 From: aux To: src Incorrect step! 
// ************************************* Source: 3, 2, 1 Auxiliary: 0 Destination: 
// 0 From: src To: aux ************************************* Source: 3, 2 
// Auxiliary: 1 Destination: 0 From: src To: dst 
// ************************************* Source: 3 Auxiliary: 1 Destination: 2 
// From: aux To: dst ************************************* Source: 3 Auxiliary: 0 
// Destination: 2, 1 From: 0 The disks are not on the destination! 
// ************************************* Source: 3 Auxiliary: 0 Destination: 2, 1 
// 2.58.1.


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>

const int DEFAULT_RINGNUM = 3;

struct Tower {
    std::vector<int> disks;
    std::string name;
    int maxHeight;

    Tower(int height, bool full, const std::string& towerName)
        : disks(full ? height : 0), name(towerName), maxHeight(height) {
        if (full) {
            for (int i = height; i >= 1; --i)
                disks[height - i] = i;
        }
    }

    void print() const {
        std::cout << name << ": ";
        if (disks.empty()) {
            std::cout << "0\n";
            return;
        }
        for (size_t i = 0; i < disks.size(); ++i) {
            std::cout << disks[i];
            if (i < disks.size() - 1) std::cout << ", ";
        }
        std::cout << "\n";
    }

    int top() const {
        return disks.empty() ? 0 : disks.back();
    }

    void push(int val) {
        disks.push_back(val);
    }

    int pop() {
        int val = disks.back();
        disks.pop_back();
        return val;
    }

    bool isComplete() const {
        if (disks.size() != static_cast<size_t>(maxHeight)) return false;
        for (int i = maxHeight; i >= 1; --i)
            if (disks[maxHeight - i] != i)
                return false;
        return true;
    }
};

int getIndex(const std::string& name) {
    if (name == "src") return 0;
    if (name == "aux") return 1;
    if (name == "dst") return 2;
    return -1;
}

bool isMoveValid(int from, int to, const std::vector<Tower>& towers) {
    if (from < 0 || to < 0 || from == to) return false;
    if (towers[from].disks.empty()) return false;
    if (!towers[to].disks.empty() && towers[from].top() > towers[to].top()) return false;
    return true;
}

int main(int argc, char* argv[]) {
    int maxRings = argc > 1 ? std::atoi(argv[1]) : DEFAULT_RINGNUM;

    std::vector<Tower> towers;
    towers.emplace_back(maxRings, true, "Source");
    towers.emplace_back(maxRings, false, "Auxiliary");
    towers.emplace_back(maxRings, false, "Destination");

    std::string from, to;
    bool giveUp = false;

    do {
        std::cout << "\n\n*************************************\n\n";
        for (const auto& t : towers) t.print();

        std::cout << "From: ";
        std::cin >> from;
        if (from != "0") {
            std::cout << "To: ";
            std::cin >> to;
        }

        giveUp = (from == "0" || to == "0");

        if (!giveUp) {
            int f = getIndex(from);
            int t = getIndex(to);
            if (isMoveValid(f, t, towers)) {
                int disk = towers[f].pop();
                towers[t].push(disk);
            } else {
                std::cout << "Incorrect step!\n";
            }
        }

    } while (!giveUp && !towers[2].isComplete());

    std::cout << "\n\n*************************************\n\n";
    for (const auto& t : towers) t.print();

    if (giveUp)
        std::cout << "The disks are not on the destination!\n";
    else
        std::cout << "The disks are on their place!\n";

    return 0;
}
// 2.59. Törtek összeadása
// 2.59.1. Egy fájl több törtet tartalmaz. Írjon programot, amely beolvassa a 
// törteket, és összeadja őket! Minden összeadás után számolja ki az 
// aktuális összeg számlálójának és nevezőjének legnagyobb közös 
// osztóját az Euklideszi algoritmus segít- ségével, és ha lehet, akkor 
// egyszerűsítse a törtet, majd folytassa az összeadást! Minden műveletet 
// írjon ki a képernyőre a példában látható módon! Az Euklideszi 
// algoritmus megadja két szám legnagyobb közös osztóját. procedure 
// Euclidean(A, B) M = B while M is not zero { B = M M = A mod B A = B } Az input 
// fájl formátuma: Első sor: a törtek száma A többi sorban két pozitív 
// egész található, az első a számláló, a második a nevező értéke. A 
// két érték szóköz karakterrel van elválasztva. Példa bemenet: 3 2 3 4 5 6 
// 11 Kimenet: 2 4 ------ + ------ = 3 5 -----15 6 ------ + ------ = -----165 4 
// ------ + ------ = 3 1656 ------ = -----55 
// 2.59.1.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int gcd(int a, int b) {
    while (b != 0) {
        int m = b;
        b = a % b;
        a = m;
    }
    return a;
}

void ReadAndAdd(std::istream& in) {
    int count;
    in >> count;

    int numer = 0, denom = 0;

    for (int i = 0; i < count; ++i) {
        int num, den;
        in >> num >> den;

        if (denom == 0) {
            // Első tört
            numer = num;
            denom = den;
        } else {
            int new_numer = numer * den + num * denom;
            int new_denom = denom * den;
            int d = gcd(new_numer, new_denom);

            if (d > 1) {
                std::cout << std::setw(4) << numer << " " << std::setw(4) << num << " "
                          << std::setw(4) << new_numer << " " << std::setw(4) << (new_numer / d) << "\n";
                std::cout << "------ + ------ = ------ = ------\n";
                std::cout << std::setw(4) << denom << " " << std::setw(4) << den << " "
                          << std::setw(4) << new_denom << " " << std::setw(4) << (new_denom / d) << "\n\n";
            } else {
                std::cout << std::setw(4) << numer << " " << std::setw(4) << num << " "
                          << std::setw(4) << new_numer << "\n";
                std::cout << "------ + ------ = ------\n";
                std::cout << std::setw(4) << denom << " " << std::setw(4) << den << " "
                          << std::setw(4) << new_denom << "\n\n";
            }

            numer = new_numer / d;
            denom = new_denom / d;
        }
    }

    std::cout << "Final result:\n";
    std::cout << std::setw(4) << numer << "\n";
    std::cout << "-----\n";
    std::cout << std::setw(4) << denom << "\n";
}

int main(int argc, char* argv[]) {
    const std::string default_filename = "nums.txt";
    std::ifstream file(argc > 1 ? argv[1] : default_filename);
    
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open input file.\n";
        return 1;
    }

    ReadAndAdd(file);
    file.close();
    return 0;
}
// 2.60. Nevezetes számok 
// Számelmélettel már az ókori Görögországban is sokat foglalkoztak, 
// például sok nevezetes tulajdonságú számot próbáltak meghatározni.
// 2.60.1. Írjon programot, amely megszámolja, hogy 1 és 10000 között mennyi 
// tökéletes szám van! Tökéletes számnak tekintjük azokat a számokat, 
// amelyekre igaz, hogy megegyeznek az osztóik összegével. Az osztók közé az 
// 1-et is hozzávesszük, de magát a számot nem. Például tökéletes szám a 
// 6, mert 1 + 2 + 3 = 6. 
// 2.60.2. Írjon programot, amely megszámolja, hogy 1 és 100 között mennyi 
// hiányos szám található! Hiányos szám az, amely nagyobb az osztóinak 
// összegénél, önmagát nem számítjuk az osztói közé. Például a 21 
// hiányos szám, mert 1 + 3 + 7 < 21. 
// 2.60.3. Írjon programot, amely megszámolja, hogy 1 és 1000 között mennyi 
// bővelkedő szám található! Bővelkedő szám az, amely kisebb az osztóinak 
// összegénél, önmagát szintén nem számítjuk az osztói közé. Például 
// a 12 bővelkedő szám, mert 1 + 2 + 3 + 4 + 6 > 12.
// 2.60.4. Módosítsa az előző feladatot úgy, hogy azon 1 és 1000 között 
// található bővelkedő számokat adja meg, amelyek 2-vel vagy 3-al 
// oszthatóak!
// 2.60.1-2.60.4.


#include <iostream>

constexpr int N1 = 10000;
constexpr int N2 = 100;
constexpr int N3 = 1000;

// Visszaadja a szám valódi osztóinak összegét (a szám nélkül)
int osztokOsszege(int szam) {
    if (szam == 1) return 0;

    int osszeg = 1;  // 1-et mindenre hozzáadjuk
    for (int oszto = 2; oszto * oszto <= szam; ++oszto) {
        if (szam % oszto == 0) {
            osszeg += oszto;
            if (oszto != szam / oszto)
                osszeg += szam / oszto;
        }
    }
    return osszeg;
}

int main() {
    int tokeletes = 0;
    int hianyos = 0;
    int bovelkedo = 0;
    int bovelkedo2 = 0;

    // 2.60.1. Tökéletes számok 1 és 10000 között
    for (int i = 1; i <= N1; ++i) {
        if (osztokOsszege(i) == i) {
            ++tokeletes;
        }
    }

    // 2.60.2. Hiányos számok 1 és 100 között
    for (int i = 1; i <= N2; ++i) {
        if (osztokOsszege(i) < i) {
            ++hianyos;
        }
    }

    // 2.60.3–2.60.4. Bővelkedő számok 1 és 1000 között, szűrés 2/3-mal oszthatókra
    for (int i = 1; i <= N3; ++i) {
        if (osztokOsszege(i) > i) {
            ++bovelkedo;
            if (i % 2 == 0 || i % 3 == 0) {
                ++bovelkedo2;
            }
        }
    }

    // Eredmények kiírása
    std::cout << "Tökéletes számok 1 és " << N1 << " között: " << tokeletes << "\n";
    std::cout << "Hiányos számok 1 és " << N2 << " között: " << hianyos << "\n";
    std::cout << "Bővelkedő számok 1 és " << N3 << " között: " << bovelkedo << "\n";
    std::cout << "2-vel vagy 3-mal osztható bővelkedő számok 1 és " << N3 << " között: "
              << bovelkedo2 << "\n";

    return 0;
}
