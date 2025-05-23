2.57.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> #define DEFAULT_INPUTFILE "tipp1.txt" void GetNumbers(int * A) { int i, j, num;
for (i = 0;
i < 5;
i++) { } } do { num = rand() % 90 + 1;
j = 0;
while ((j < i) && (A[j] != num)) j++;
} while (j < i);
A[i] = num;
void PrintNumbers(int * A) { int i;
for (i = 0;
i < 4;
i++) printf("%d, ", A[i]);
printf("%d\n", A[4]);
} void Check(FILE * fd, int * A, int * H) { int i, j, k, c, num, a;
fscanf(fd, "%d", &c);
for (k = 0;
k < c;
k++) { a = 0;
for (i = 0;
i < 5;
i++) { fscanf(fd, "%d", &num);
j = 0;
while ((j < 5) && (A[j] != num)) j++;
if (j < 5) a++;
} if (a > 0) H[a - 1]++;
} } void InitHits(int * A) { int i;
for (i = 0;
i < 5;
i++) A[i] = 0;
} void PrintHits(int * A) { int i;
for (i = 0;
i < 5;
i++) { printf("There ");
if (A[i] > 1) printf("are ");
else printf("is ");
printf("%d %d hit", A[i], i + 1);
if (A[i] > 1) } } printf("s\n");
else printf("\n");
int main(int argc, char * argv[]) { int Numbers[5];
int Hits[5];
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, „r”);
if (fd == NULL) { perror("Error");
return 0;
} srand(time(NULL));
InitHits(Hits);
GetNumbers(Numbers);
printf("Generated numbers: ");
PrintNumbers(Numbers);
Check(fd, Numbers, Hits);
PrintHits(Hits);
fclose(fd);
return 0;
} 
2.57.1. Írjon lottó-generáló programot! A program generáljon 1 és 90 között 5 különböző pozitív egész számot! Egy fájl tippeket tartalmaz. Olvassa be a tippeket a fájlból, majd hasonlítsa össze őket a generált számokkal! Írja ki a képernyőre a generált nyerőszámokat, és azt, hogy hány embernek van 1-es, 2-es, 3as, 4-es, illetve 5-ös találata a lottón! Az input fájl formátuma: Első sor: a tippek száma Minden további sor 5 tippet tartalmaz, szóköz karakterekkel elválasztva. Példa bemenet: 6 5 64 23 80 42 4 34 44 62 72 75 43 3 64 80 53 52 21 56 10 1 37 87 9 53 75 10 64 69 78 Kimenet: Generated numbers: 55, 64, 68, 75, 50 There is 1 1 hit There are 2 2 hits There is 0 3 hit There is 0 4 hit There is 0 5 hit 2.58. Hanoi tornyai
