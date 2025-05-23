3.48.2.-3.48.4.
#include <stdio.h>
#include <stdlib.h>
#include <math.h> #define N 100 double magassagLekerdez() { static int i = 0;
double res;
if (i >= 0 && i <= 3) res = 4;
else if (i >= 4 && i <= 10) res = 3;
else if (i >= 40 && i <= 60) res = 7;
else if (i >= 70 && i <= 100) res = 2;
else res = (rand() % 1000) / 10.0;
i++;
return res;
} typedef struct Siksag { int kezdet;
int veg;
int hossz;
} Siksag;
int main() { int i;
int minIndex = 0;
int maxIndex = 0;
int emelkedoIndex;
Siksag maxSiksag;
Siksag aktSiksag;
double minMagassag;
double maxMagassag;
double maxKulonbseg = 0;
double magassag;
double elozo;
maxSiksag.hossz = 1;
maxSiksag.veg = 0;
for (i = 0;
i < N;
i++) { magassag = magassagLekerdez();
if (i == 0) { minMagassag = magassag;
maxMagassag = magassag;
elozo = magassag;
} else { if (abs(elozo - magassag) > maxKulonbseg) { maxKulonbseg = abs(elozo - magassag);
emelkedoIndex = i;
} if (minMagassag > magassag) { minIndex = i;
minMagassag = magassag;
} if (maxMagassag < magassag) { maxIndex = i;
maxMagassag = magassag;
} if (elozo == magassag) { if (aktSiksag.hossz == 0) { aktSiksag.hossz = 2;
aktSiksag.kezdet = i - 1;
aktSiksag.veg = i;
} else { aktSiksag.veg = i;
aktSiksag.hossz++;
} } else { if (aktSiksag.veg == i - 1) { if (maxSiksag.hossz < aktSiksag.hossz) { maxSiksag = aktSiksag;
} aktSiksag.hossz = 0;
} } } elozo = magassag;
} if (maxSiksag.hossz < aktSiksag.hossz && aktSiksag.hossz > 1) { maxSiksag = aktSiksag;
} double maxFok = atan(maxKulonbseg / 100.0) / (M_PI / 180.0);
printf("A legmagasabb pont: %g, helye: %d\n", maxMagassag, maxIndex);
printf("A legalacsonyabb pont: %g, helye: %d\n", minMagassag, minIndex);
printf("A legmeredekebb emelkedo: %g fok, helye: %d\n", maxFok, emelkedoIndex);
printf("A leghosszabb siksag adatai:\n\tkezdete: %d\n\tvege: %d\n\thossza: %d\n", maxSiksag.kezdet, maxSiksag.veg, maxSiksag.hossz);
return EXIT_SUCCESS;
} 
3.48.2. Közeledik a marsbeli tél, ezért a marsjáró földi vezetői attól félnek, hogy azelőtt leáll, mielőtt elküldené a legújabb összegyűjtött méréseket. Ezért beállítják, hogy minden egyes mérés után küldje el a Földre az aktuális magasságát. Írjon programot, amibe a kezelő személy begépeli az aktuális kapott magasság értéket és minden új adat után kiszámolja, hogy eddig mekkora volt a legmagasabb és legalacsonyabb pont és hol voltak azok! 
3.48.3. Bővítse ki az előző programot úgy, hogy azt is nyilván tartsa a legmeredekebb lejtő és emelkedő meredekségét, valamint pozícióját! Megjegyzés: két mérési adat közötti különbség egy derékszögű háromszög egyik befogóját határozza meg, a másik befogó 100 méter. 
3.48.4. Bővítse ki az előző programot úgy, hogy a leghosszabb sík terület hosszát, valamint kezdő és vég pontjának pozícióját keresse meg! Sík területnek számít az, ahol a terep pontjai összefüggően azonos magasságúak. 3.49. Ritka vektor
