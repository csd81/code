
// 3.16.2. Alakítsa át úgy az előző programot, hogy függvényben kérje be tömb méretet és ott hozza azt létre!  
3.16.2.
#include <stdio.h>
#include <malloc.h>
#include <memory.h> double* allocArray(int* size) { double* result=NULL;
printf("\narray size: ");
scanf("%d", size);
result = (double*)malloc(*size * sizeof(double));
return result;
} int main() { int size, idxI;
double *array=NULL, *temp=NULL;
array = allocArray(&size);
for (idxI=0;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} temp = (double*)malloc(size*2*sizeof(double));
memcpy(temp, array, size*sizeof(double));
array = temp;
} size *= 2;
temp = NULL;
for (idxI=size/2;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} free(array);
array = NULL;
return 0;

