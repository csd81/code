/* 
3.48. Marsjáró 

A Mars Explorer 3000-es marsjáró robot utazása során 100 méterenként feljegyzi, hogy a 
bolygón való leszállóhelyéhez viszonyítva milyen magasan / mélyen jár, 
így egy domborzati keresztmetszetet továbbít a földi irányító 
központba. Szeretnénk részletesen megvizsgálni a bejárt terepet. A 
vizsgálatra számítógépet használunk. A domborzati magasságokat egy 
tömbben tároljuk.


3.48.1. Írjon programot, amely a tömbben tárolt domborzati adatokból 
meghatározza, hogy mekkora volt a legmagasabb, illetve legalacsonyabb 
magasság, ahol a marsjáró járt, valamint hogy hol voltak ezek a pontok! 
*/ 

// 3.48.1.

#include <iostream>
#include <vector>
#include <cstdlib>  // rand()
#include <ctime>    // time()

constexpr int N = 100;

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // véletlenszám inicializálása

    std::vector<double> magassag(N);
    
    // Véletlenszerű magasságok generálása
    for (int i = 0; i < N; ++i) {
        magassag[i] = (std::rand() % 1000) / 10.0; // 0.0 - 99.9 közötti értékek
    }

    // Min/max keresés
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < N; ++i) {
        if (magassag[i] < magassag[minIndex]) {
            minIndex = i;
        }
        if (magassag[i] > magassag[maxIndex]) {
            maxIndex = i;
        }
    }

    std::cout << "A legmagasabb pont: " << magassag[maxIndex]
              << ", helye: " << maxIndex << '\n';
    std::cout << "A legalacsonyabb pont: " << magassag[minIndex]
              << ", helye: " << minIndex << '\n';

    return 0;
}

