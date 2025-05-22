// 8.1.2. Ismerje meg és valósítson meg a következő rendező függvények közül kettőt! Beszúró rendezés, shell rendezése, radix rendezés, shaker rendezés, heap rendezés, comb rendezés. 8.2. Rekurzív függvények

8.1.2.
#include <stdio.h> void combSort(int *, int);
void insertionSort(int *, int);
int main() { int idxI;
int myArray[] = {5,8,3,4,12,45,87};
int myArray2[] = {5,8,3,4,12,45,87};
int size = sizeof(myArray) /sizeof(int);
combSort(myArray2, size);
for (idxI = 0;
idxI < size;
++idxI) printf("%d, ", myArray2[idxI]);
printf("\n");
} insertionSort(myArray, size);
for (idxI = 0;
idxI < size;
++idxI) printf("%d, ", myArray[idxI]);
printf("\n");
return 0;
void combSort(int * myArray, int size){ int gap = size, idxI, idxJ, swap, temp;
for (;;) { gap = (gap *10) /13;
if (gap == 9 || gap == 10) gap = 11;
if (gap < 1) gap=1;
swap = 0;
for (idxI = 0;
idxI < size -gap;
idxI++) { int idxJ = idxI+gap;
if (myArray[idxI] > myArray[idxJ]) { temp = myArray[idxI];
myArray[idxI] = myArray[idxJ];
myArray[idxJ] = temp;
swap = 1;
} } if (gap == 1 && !swap) break;
} } void insertionSort (int * myArray, int size) { int idxI, idxJ, leftBorder, rightBorder, tempSize, actualElement;
for (idxI = 1;
idxI < size;
idxI++) { actualElement = myArray[idxI];
leftBorder = 0;
rightBorder = idxI-1;
while (leftBorder <= rightBorder) { tempSize = (leftBorder+rightBorder) / 2;
if (actualElement < myArray[tempSize]) rightBorder = tempSize-1;
else leftBorder = tempSize+1;
} elemeket eltolom eggyel for (idxJ = idxI-1;
idxJ >= leftBorder;
idxJ--) myArray[idxJ+1] = myArray[idxJ];
myArray[leftBorder] = actualElement;
} } 