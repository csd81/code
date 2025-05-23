2.56.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_ROWNUM 10 #define SZOKOZS 4 int 
BinomialCoefficient(int n, int k) { int bc = n;
int i;
if (k == 0) return 1;
for (i = n - 1 ;
i > (n - k);
i--) { bc *= i;
} for (i = 2;
i <= k;
i++) bc /= i;
return bc;
} int GetWidth(int n) { return n * 3 + (n - 1) * SZOKOZS;
} void PascalsTriangle(int rows) { int i, sp, r, j;
int width = GetWidth(rows);
for (r = 0;
r < rows;
r++) { for (sp = 0;
sp < (width / 2) - (GetWidth(r) / 2);
sp++) printf("");
for (i = 0;
i <= r;
i++) { printf("%3d", BinomialCoefficient(r, i));
for (j = 0;
j < SZOKOZS;
j++) printf("");
} } } printf("\n");
int main(int argc, char * argv[]) { int rows = argc > 1 ? atoi(argv[1]) : 
DEFAULT_ROWNUM;
PascalsTriangle(rows);
return 0;
} 
2.56.1. Írjon programot, amely kiírja a képernyőre a Pascal háromszög 
első 10 sorát! Két szám között 4 szóköz karakter legyen! Az r-edik sor 
i-edik tagját számolja a következőképlettel: r! / ( i! * ( r - i )! ) 
Kimenet: 1 1 1 1 1 1 1 9 1 1 8 7 1 6 1 5 4 2 3 6 1 3 4 1 5 1 6 1 7 1 8 1 9 1 1 
2.57. Lottó
