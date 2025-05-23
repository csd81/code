3.48.1.
#include <stdio.h>
#include <stdlib.h> #define N 100 int main() { double magassag[N];
int i;
for (i = 0;
i < N;
i++) { magassag[i] = (rand() % 1000) / 10.0;
} int minIndex = 0;
int maxIndex = 0;
for (i = 0;
i < N;
i++) { if (magassag[minIndex] > magassag[i]) { minIndex = i;
} if (magassag[maxIndex] < magassag[i]) { maxIndex = i;
} } printf("A legmagasabb pont: %g, helye: %d\n", magassag[maxIndex], maxIndex);
printf("A legalacsonyabb pont: %g, helye: %d\n", magassag[minIndex], minIndex);
return EXIT_SUCCESS;
} 
3.48.1. Írjon programot, amely a tömbben tárolt domborzati adatokból meghatározza, hogy mekkora volt a legmagasabb, illetve legalacsonyabb magasság, ahol a marsjáró járt, valamint hogy hol voltak ezek a pontok! 
