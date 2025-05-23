3.5.1
#include <stdio.h>
#include <math.h> int main() { float tomb[5];
int idxI;
} for (idxI=0;
idxI<5;
idxI++) { tomb[idxI]=sqrt(idxI);
} for (idxI=0;
idxI<5;
idxI++) { printf("%f, ", tomb[idxI]);
} return 0;

3.5.1. Írjon programot, amelyben egy 5 hosszú statikus float tömb minden 
elemébe a hozzátartozó index gyökét írja be! Használjon for ciklust az 
egyes elemek eléréséhez és az eredmény kiírásához! Az egyes értékek 
vesszővel legyenek elválasztva! 
