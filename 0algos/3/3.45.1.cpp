3.45.1.
#include <stdio.h>
#include <stdlib.h> #define N 10 int main() { int i;
int osszeg = 0;
int jegy;
for (i = 0;
i < N;
i++) { printf("%d. jegy: ", i + 1);
scanf("%d", &jegy);
osszeg += jegy;
} printf("A jegyek szamtani atlaga: %g\n", (double)osszeg / N);
return EXIT_SUCCESS;
} 
3.45.1. Írjon programot Aladárnak, amely beolvas 10 jegyet, majd kiszámolja azok számtani átlagát! 
