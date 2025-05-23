
// 3.18.1. Kérje be egy lebegőpontos tömb méretét! Ha az 5 vagy kisebb, akkor hozzon létre dinamikus tömböt a memóriában, ha nagyobb, akkor pedig bináris fájlt a háttértáron! Készítsen struktúrát, amely tartalmaz egy FILE*, double* és méret adattagot! Készítsen függvényeket: tároló inicializálására és felszabadítására, tároló adott pozíciójában történő olvasásra és írásra. Menüben kérje be, hogy írni vagy olvasni akar, a fő függvény számára a tárolás módja legyen transzparens! 3.19. Gépelés
3.18.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> const int limit=5;
typedef struct { FILE* bf;
double* array;
long int size;
} Store;
void initStore(Store* myStore) { printf("Size of the array: ");
scanf("%ld", &myStore->size);
if (myStore->size>limit) myStore->bf = fopen("temp.txt", "w+b");
else myStore->array = (double*)malloc(sizeof(double)*myStore->size);
return;
} void delStore(Store* myStore) { if (myStore->size>limit) { fclose(myStore->bf);
myStore->bf = NULL;
} else free(myStore->array);
myStore->array = NULL;
return;
} void readStore(Store* myStore) { double result;
int idx;
printf("Index of element to read: ");
scanf("%d", &idx);
if (myStore->size>limit) { fseek(myStore->bf, sizeof(double)*idx, SEEK_SET);
fread(&result, sizeof(double), 1, myStore->bf);
} else { result = myStore->array[idx];
} printf("At %d there is: %lf\n", idx, result);
} void writeStore(Store* myStore) { double value;
int idx;
printf("Index of element to write: ");
scanf("%d", &idx);
printf("value: ");
scanf("%lf", &value);
if (myStore->size>limit) { fseek(myStore->bf, sizeof(double)*idx, SEEK_SET);
fwrite(&value, sizeof(double), 1, myStore->bf);
} else { myStore->array[idx] = value;
} printf("%lf is written at %d\n", value, idx);
} int main() { Store myStore={NULL, NULL, 0};
int selection=0;
} initStore(&myStore);
while (selection!=3) { printf("\nRead - 1\nWrite - 2\nQuit - 3\n");
scanf("%d", &selection);
switch (selection) { case 1: readStore(&myStore);
break;
case 2: writeStore(&myStore);
break;
} } delStore(&myStore);
return 0;

