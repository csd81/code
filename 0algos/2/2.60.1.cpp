2.60.1-2.60.4.
#include <stdio.h>
#include <stdlib.h> int osztokOsszege(int szam) { if (szam == 1) { return 0;
} int oszto = 2;
int osszeg = 1;
while (oszto * oszto < szam) { if (szam % oszto == 0) { osszeg += oszto;
osszeg += szam / oszto;
} oszto++;
} return osszeg;
} #define N1 10000 #define N2 100 #define N3 1000 int main() { int i;
int tokeletes = 0;
int hianyos = 0;
int bovelkedo = 0;
int bovelkedo2 = 0;
for (i = 1;
i <= N1;
i++) { if (osztokOsszege(i) == i) { tokeletes++;
} } for (i = 1;
i <= N2;
i++) { if (osztokOsszege(i) < i) { hianyos++;
} } for (i = 1;
i <= N3;
i++) { if (osztokOsszege(i) > i) { bovelkedo++;
if (i % 6 == 0) { bovelkedo2++;
} } } printf("Tokeletes szamok 1 es %d kozott: %d\n", N1, tokeletes);
printf("Hianyos szamok 1 es %d kozott: %d\n", N2, hianyos);
printf("Bovelkedo szamok 1 es %d kozott: %d\n", N3, bovelkedo);
printf("2-vel es 3-al oszthato bovelkedo szamok 1 es %d kozott: %d\n", N3, 
bovelkedo2);
return EXIT_SUCCESS;
} 
2.60.1. Írjon programot, amely megszámolja, hogy 1 és 10000 között mennyi 
tökéletes szám van! Tökéletes számnak tekintjük azokat a számokat, 
amelyekre igaz, hogy megegyeznek az osztóik összegével. Az osztók közé az 
1-et is hozzávesszük, de magát a számot nem. Például tökéletes szám a 
6, mert 1 + 2 + 3 = 6. 
2.60.2. Írjon programot, amely megszámolja, hogy 1 és 100 között mennyi 
hiányos szám található! Hiányos szám az, amely nagyobb az osztóinak 
összegénél, önmagát nem számítjuk az osztói közé. Például a 21 
hiányos szám, mert 1 + 3 + 7 < 21. 
2.60.3. Írjon programot, amely megszámolja, hogy 1 és 1000 között mennyi 
bővelkedő szám található! Bővelkedő szám az, amely kisebb az osztóinak 
összegénél, önmagát szintén nem számítjuk az osztói közé. Például 
a 12 bővelkedő szám, mert 1 + 2 + 3 + 4 + 6 > 12.
2.60.4. Módosítsa az előző feladatot úgy, hogy azon 1 és 1000 között 
található bővelkedő számokat adja meg, amelyek 2-vel vagy 3-al 
oszthatóak! 3. Tömbök és mátrixok feladatai 3.1. Egy sztring címei
