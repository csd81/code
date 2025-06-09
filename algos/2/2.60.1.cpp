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
