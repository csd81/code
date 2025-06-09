/*
3.48.2. Közeledik a marsbeli tél, ezért a marsjáró földi vezetői attól 
félnek, hogy azelőtt leáll, mielőtt elküldené a legújabb 
összegyűjtött méréseket. Ezért beállítják, hogy minden egyes mérés 
után küldje el a Földre az aktuális magasságát. Írjon programot, amibe a 
kezelő személy begépeli az aktuális kapott magasság értéket és minden 
új adat után kiszámolja, hogy eddig mekkora volt a legmagasabb és 
legalacsonyabb pont és hol voltak azok! 

3.48.3. Bővítse ki az előző programot úgy, hogy azt is nyilván tartsa a 
legmeredekebb lejtő és emelkedő meredekségét, valamint pozícióját! 
Megjegyzés: két mérési adat közötti különbség egy derékszögű 
háromszög egyik befogóját határozza meg, a másik befogó 100 méter. 

3.48.4. Bővítse ki az előző programot úgy, hogy a leghosszabb sík 
terület hosszát, valamint kezdő és vég pontjának pozícióját keresse 
meg! Sík területnek számít az, ahol a terep pontjai összefüggően azonos 
magasságúak. 
*/
//3.48.2.-3.48.4.

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

constexpr int N = 100;

double magassagLekerdez() {
    static int i = 0;
    double res;
    if (i >= 0 && i <= 3) res = 4;
    else if (i >= 4 && i <= 10) res = 3;
    else if (i >= 40 && i <= 60) res = 7;
    else if (i >= 70 && i <= 100) res = 2;
    else res = (std::rand() % 1000) / 10.0;
    ++i;
    return res;
}

struct Siksag {
    int kezdet = 0;
    int veg = 0;
    int hossz = 1;
};

int main() {
    std::vector<double> magassagok(N);
    int minIndex = 0, maxIndex = 0;
    int emelkedoIndex = 0;
    double minMagassag, maxMagassag;
    double maxKulonbseg = 0;
    double elozo = 0.0;

    Siksag maxSiksag;
    Siksag aktSiksag;
    aktSiksag.hossz = 0;

    for (int i = 0; i < N; ++i) {
        double magassag = magassagLekerdez();
        magassagok[i] = magassag;

        if (i == 0) {
            minMagassag = maxMagassag = elozo = magassag;
            continue;
        }

        // legmeredekebb lejtő vagy emelkedő
        double kulonbseg = std::abs(magassag - elozo);
        if (kulonbseg > maxKulonbseg) {
            maxKulonbseg = kulonbseg;
            emelkedoIndex = i;
        }

        // max és min pont
        if (magassag > maxMagassag) {
            maxMagassag = magassag;
            maxIndex = i;
        }
        if (magassag < minMagassag) {
            minMagassag = magassag;
            minIndex = i;
        }

        // sík szakasz
        if (std::abs(magassag - elozo) < 1e-6) {
            if (aktSiksag.hossz == 0) {
                aktSiksag.kezdet = i - 1;
                aktSiksag.veg = i;
                aktSiksag.hossz = 2;
            } else {
                aktSiksag.veg = i;
                aktSiksag.hossz++;
            }
        } else {
            if (aktSiksag.hossz > maxSiksag.hossz) {
                maxSiksag = aktSiksag;
            }
            aktSiksag.hossz = 0;
        }

        elozo = magassag;
    }

    if (aktSiksag.hossz > maxSiksag.hossz) {
        maxSiksag = aktSiksag;
    }

    // szög kiszámítása fokban (a = szintkülönbség, b = 100 m)
    double maxFok = std::atan(maxKulonbseg / 100.0) * 180.0 / M_PI;

    // eredmények kiíratása
    std::cout << "A legmagasabb pont: " << maxMagassag << ", helye: " << maxIndex << '\n';
    std::cout << "A legalacsonyabb pont: " << minMagassag << ", helye: " << minIndex << '\n';
    std::cout << "A legmeredekebb emelkedo vagy lejtő: " << maxFok << " fok, helye: " << emelkedoIndex << '\n';
    std::cout << "A leghosszabb sík terület:\n";
    std::cout << "\tKezdete: " << maxSiksag.kezdet << '\n';
    std::cout << "\tVege: " << maxSiksag.veg << '\n';
    std::cout << "\tHossza: " << maxSiksag.hossz << '\n';

    return 0;
}

