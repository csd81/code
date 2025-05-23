3.47.1. Egy 30 fős osztályban minden tanulóról tudjuk, hogy informatikából mennyi a jegyeinek az átlaga. Írjon programot, amely billentyűzetről beolvassa a 30 átlagot, majd kiírja a képernyőre, hogy volt-e bukás idén! Az bukik meg, akinek az átlaga kevesebb, mint 1.5. 
3.47.1.
#include <stdio.h>
#include <stdlib.h> #define N 30 int main() { double jegyek[N];
int i;
for (i = 0;
i < N;
i++) { printf("A %d. atlag: ", i + 1);
scanf("%lf", &jegyek[i]);
} i = 0;
while (i < N && jegyek[i] >= 1.5) { i++;
} if (i < N) { printf("Volt bukas!\n");
} else { printf("Nem volt bukas!\n");
} return EXIT_SUCCESS;
} 
