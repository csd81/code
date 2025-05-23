2.5.2. Határozza meg az összeadás, szorzás, osztás, hatványozás 
időigényét úgy, hogy az előző program legbelsejébe beírja a megfelelő 
utasítást! 2.6. Adatbekérés
2.5.2.
#include <stdio.h> int main() { int idxA, idxB, idxC, size=1000;
int a, b = 2364, c = 9754;
for (idxA = 0;
idxA < size;
idxA++) { for (idxB = 1;
idxB < size;
idxB++) { for (idxC = 1;
idxC < size;
idxC++) { a = b + c;
} } } return 0;
} 

