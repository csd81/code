
// 3.21.1. Írjon programot, amely számokat olvas be fájlból, majd 
kiszámítja ezek átlagát és mediánját! A program írja ki a képernyőre 
a számokat, az átlagot, és a mediánt is! A medián kiszámításához 
először sorba kell rendeznie a számokat. Páratlan számú adat esetén a 
medián ebben a sorban a középső elem, páros számú adat esetén a két 
középső elem átlaga. Az input fájl formátuma: Első sor: Az adatok 
száma. Második sor: A számok, egy-egy szóköz karakterrel elválasztva. 
Példa bemenet: 4 2 5 3 4 2 5 1 3 5 1 5 5 5 4 4 3 4 4 2 5 5 1 5 5 3 2 5 2 5 
Kimenet: 30 numbers: 4 2 5 3 4 2 5 1 3 5 1 5 5 5 4 4 3 4 4 2 5 5 1 5 5 3 2 5 2 
5 The average is 3.63333 The median is: 4 

3.21.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUT "datas.txt" int Read(FILE * fd, int 
** nums) { int count, i;
fscanf(fd, "%d", &count);
printf("%d numbers:\n", count);
*nums = (int *)malloc(sizeof(int) * count);
for (i = 0;
i < count;
i++) { fscanf(fd, "%d", (*nums) + i);
printf("%d ", (*nums)[i]);
} printf("\n");
return count;
} double Median(int count, int * A) { int i, j, pos, temp;
for (i = 0;
i < count - 1;
i++) { pos = i;
for (j = i;
j < count;
j++) { if (A[j] < A[pos]) pos = j;
} temp = A[i];
A[i] = A[pos];
A[pos] = temp;
} return count % 2 ? A[count / 2] : (A[ count / 2 - 1] + A[ count / 2]) / 2.0 ;
} double Average(int count, int * A) { long int sum = 0;
int i;
for (i = 0;
i < count;
i++) sum += A[i];
return (double)sum / count;
} int main(int argc, char * argv[]) { int count;
int * datas = NULL;
FILE * fd = fopen( argc > 0 ? argv[1] : DEFAULT_INPUT, "r");
if (fd == NULL) { perror("Error");
return 0;
} count = Read(fd, &datas);
fclose(fd);
printf("The average is %g\n", Average(count, datas));
printf("The median is: %g\n", Median(count, datas));
free(datas);
return 0;
} 


