3.5.2.
#include <stdio.h>
#include <math.h> int main() { float * tomb;
int idxI, size;
printf("Size of array? ");
scanf("%d", &size);
tomb = (float*) malloc(size*sizeof(float));
for (idxI = 0;
idxI < size;
idxI++) tomb[idxI] = sqrt(idxI);
for (idxI = 0;
idxI < size;
idxI++) { printf("%f", tomb[idxI]);
if(idxI+1 != size) printf(",");
else printf("\n");
} free(tomb);
return 0;
} 
3.5.2. Oldja meg, hogy az utolsó szám után ne jelenjen meg vessző a 
kiírásnál és hogy a tömb nagyságát szabadon lehessen meghatározni! 3.6. 
Tömb reprezentálása
