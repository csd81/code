3.9.3. Egy plusz változó jelezze, hogy melyik irányba történik a 
csúsztatás! A tömb mérete legyen megadható! 3.10. Műveletek tömbökön
3.9.3.
#include <stdio.h>
#include <malloc.h> void print(float a[], int size) { int idxI;
for(idxI = 0;
idxI < size;
++idxI) printf("myArray[%d]= %f ", idxI, a[idxI]);
printf("\n");
} void shift(float* a, char direction, int cyclic, int size) { float temp = 
(direction=='r')?a[size-1]:a[0];
int idxI;
if(direction == 'r') { for(idxI = size-1;
idxI > 0;
--idxI) { a[idxI] = a[idxI-1];
} if (cyclic) a[0] = temp;
else a[0] = 0;
} else { for(idxI = 0;
idxI < size;
++idxI) { a[idxI] = a[idxI+1];
} } if (cyclic) a[size-1] = temp;
else a[size-1] = 0;
} int main() { float *myArray;
int size, idxI;
char direction;
printf("Array size? ");
scanf("%d", &size);
myArray = (float*) malloc(sizeof(float)*size);
for(idxI = 0;
idxI < size;
++idxI) { printf("Provide the next number: ");
scanf("%f", &myArray[idxI]);
} _flushall();
printf(„Original array: „);
print(myArray, size);
printf("In which direction do you want to shift? (l/r) ");
scanf("%c", &direction);
_flushall();
printf("After cyclic shift: ");
shift(myArray, direction, 1, size);
print(myArray, size);
} printf("After non-cyclic shift: ");
shift(myArray, direction, 0, size);
print(myArray, size);
return 0;
