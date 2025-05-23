




2.13.3. Folytassa az előző programot úgy, hogy bekér még két bit pozíciót! Az elsőnél törölje a bitet a másodiknál negálja. Minden részeredményt írjon ki a képernyőre! 2.14. Hatványsor
2.13.3.
#include <stdio.h>
#include <math.h> #define SIZE 8 int main() { unsigned char number=0, result, delMask=0x80;
unsigned char stringNumber[SIZE], newNumber;
int idxI, position, positionDelete, positionNegate;
printf("Number= ");
scanf("%d", &number);
printf("Its value in system 2: ");
for (idxI = 0;
idxI < SIZE;
idxI++) { result = number & delMask;
printf("%u", result?1:0);
stringNumber[idxI] = result?1:0;
delMask = delMask>>1;
} printf("\nPlease enter a position, this bit will be set to 1!(1 is the lowest) ");
scanf("%d", &position);
printf("Here comes the new number in system 2: ");
if (!stringNumber[SIZE - position]) newNumber = number + pow(2, position-1);
else newNumber = number;
stringNumber[SIZE - position] = 1;
for (idxI = 0;
idxI < SIZE;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number in system 10: ");
printf("%d\n", newNumber);
if (stringNumber[SIZE-position]) newNumber = number + pow(2, position-1);
else newNumber = number;
printf("%d\n", newNumber);
printf("Please enter 2 new position, the first position bit will be deleted, the second will be negated.(ex: 1 5) ");
scanf("%d%d", &positionDelete, &positionNegate);
for (idxI = SIZE-positionDelete;
idxI < SIZE;
++idxI) stringNumber[idxI] = stringNumber[idxI+1];
printf("Here comes the new number after bit delete in system 2: ");
for (idxI = 0;
idxI < 7;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number after bit delete in system 10: ");
newNumber = 0;
for (idxI = 6;
idxI >= 0;
--idxI) if (stringNumber[idxI] != 0) newNumber += pow(2, (6-idxI)* stringNumber[idxI]);
printf("%d\n", newNumber);
printf("Here comes the new number after bit delete and bit negate in system 2: ");
if (stringNumber[SIZE-positionNegate] == 0) stringNumber[SIZE-positionNegate] = 1;
else stringNumber[SIZE-positionNegate] = 0;
for (idxI=0;
idxI<7;
idxI++) printf("%d", stringNumber[idxI]);
printf("\nHere comes the new number after bit delete and bit negate in system 10: ");
newNumber = 0;
for (idxI = 6;
idxI >= 0;
--idxI){ if (stringNumber[idxI] != 0) { newNumber += pow(2, (6-idxI)* stringNumber[idxI]);
} } printf("%d\n", newNumber);
return 0;
} 