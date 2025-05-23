
2.20.1.
#include <stdio.h> int main() { character big int idxA, idxB, idxC, size=600;
int idxI, idxJ, idxK, drop=22, consoleSize=25;
} for (idxI=0;
idxI<drop;
idxI++) { for (idxJ=0;
idxJ<consoleSize;
idxJ++) { printf("\n");
} for (idxK=0;
idxK<idxI;
idxK++) { printf("\n");
} printf(" ***\n");
printf(" ***\n");
printf(" ***\n");
for (idxK=0;
idxK<consoleSize-idxI-3;
idxK++) { printf("\n");
} _flushall();
for(idxA = 0;
idxA <= size;
idxA++) { for(idxB = 1;
idxB <= size;
idxB++) { for(idxC = 1;
idxC <= size;
idxC++) { } } } } return 0;

2.20.1. Készítsen a karakteres képernyőn videót egy leeső négyzetről! A négyzet 3*3 csillagból álljon! Miután megjelenített egy képet, várjon rövid ideig, törölje a képernyőt és jelenítse meg a következő képet egy sorral lejjebb! Feltesszük, hogy a karakteres képernyő 80*25-ös. 
