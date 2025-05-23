// 3.16.1. Írjon programot, amely bekéri egy tömb méretét, lefoglalja a 
helyet a tömb számára és feltölti elemekkel! Növelje meg a tömb 
méretét duplájára úgy, hogy létrehoz egy új tömböt, és belemásolja a 
régi tömböt! Töltse fel a maradék helyet is új értékekkel! 

3.16.1.
#include <malloc.h>
#include <memory.h> int main() { int size, idxI;
double *array=NULL, *temp=NULL;
} printf("array size: ");
scanf("%d", &size);
array = (double*)malloc(size*sizeof(double));
for (idxI=0;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} temp = (double*)malloc(size*2*sizeof(double));
memcpy(temp, array, size*sizeof(double));
array = temp;
size *= 2;
temp = NULL;
for (idxI=size/2;
idxI<size;
idxI++) { printf("%d. element: ", idxI);
scanf("%lf", &array[idxI]);
} free(array);
array = NULL;
return 0;
