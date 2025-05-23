
2.19.2. Fordítsa el a háromszöget úgy, hogy a másik befogó kerüljön alulra! 2.20. Négyzet animáció
2.19.2.
#include <stdio.h> int main() { int idxI, idxJ, size = 6;
for (idxI = 0;
idxI < size;
++idxI) { for (idxJ = 1;
idxJ <= size;
++idxJ) { if (idxJ < size -idxI) printf("");
else printf("*");
} printf("\n");
} return 0;
} 
