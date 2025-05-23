2.53.1.
#include <stdio.h>
#include <stdlib.h> typedef unsigned long int ULint;
ULint BinomialCoefficient(int n, int k) { ULint bc = n;
int i;
if (k == 0) return 1;
for (i = n - 1 ;
i > (n - k);
i--) { bc *= i;
// printf("%d %ld\n", i, bc);
} for (i = 2;
i <= k;
i++) bc /= i;
return bc;
} void PrintPow(char ch, int p) { if (p == 0) return;
if (p == 1) printf("%c", ch);
else printf("%c^%d", ch, p);
} void PrintBinom(int a) { int i;
int b;
printf("( a + b )^%d = ", a);
for (i = 0;
i <= a;
i++) { b = BinomialCoefficient(a, i);
if (b > 1) printf("%d", b);
PrintPow('b', i);
PrintPow('a', a - i);
if (i < a) printf(" + ");
} } printf("\n");
int main(int argc, char * argv[] ) { int a;
if (argc > 1) a = atoi(argv[1]);
else { printf(„Degree: „);
scanf("%d", &a);
} printf("\n");
PrintBinom(a);
printf("\n");
return 0;
} 
2.53.1. Írjon programot, amely beolvas egy n értéket a billentyűzetről, majd a binomiális tétel jobb oldalának kifejtett alakját kiírja a képernyőre! n ne legyen nagyobb 10-nél! A binomiális tétel szerint: (a + b)n = ahol n pozitív egész szám, és (a + b)n = Példa bemenet: n=3 Kimenet: ( a + b )^3 = a^3 + 3ba^2 + 3b^2a + b^3 2.54. Hazárdjáték

