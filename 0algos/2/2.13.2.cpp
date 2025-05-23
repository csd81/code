

2.13.2. Kérjen be egy számot és az előző programmal írja ki a kettes 
számrendszerbeli alakját! Kérjen be egy bit pozíciót és állítsa azt a 
bitet egyesre! Írja ki az új értéket tízes és kettes számrendszerben is! 
2.13.2.
#include <stdio.h>
#include <math.h> #define SIZE 8 int main() { unsigned char number = 0, result, 
delMask=0x80;
unsigned char stringNumber[SIZE], newNumber;
int idxI, position;
printf("Number= ");
scanf("%d", &number);
printf("Its value in system 2: ");
for (idxI = 0;
idxI < SIZE;
idxI++) { result = number & delMask;
printf("%u", result?1:0);
stringNumber[idxI] = result?1:0;
delMask = delMask>>1;
} printf("\nPlease enter a position, this bit will be set to 1!(1 is the 
lowest) ");
scanf("%d", &position);
printf("Here comes the new number in system 2: ");
if (!stringNumber[SIZE - position]) newNumber = number + pow(2, position-1);
else newNumber = number;
stringNumber[SIZE - position] = 1;
for (idxI = 0;
idxI < SIZE;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number in system 10: ");
} printf("%d\n", newNumber);
return 0;
