// 3.2.1. Tároljon két tömbben 5-5 egész számot, az osztókat és az osztandókat! Az értékeket inicializálással adja át a tömböknek, legyen köztük negatívok is! Tippelje meg az egészosztás és maradékképzés eredményét! Írja ki a helyes választ és számolja, a helyes válaszok számát! Ötlet: ellenőrizze, hogy a második tömbben ne legyen nulla! 

3.2.1.
#include <stdio.h>
#include <math.h> int main() { const int size=4;
int idxI, op1[size]={2, -3, 0, 1}, op2[size]={4, 2, -4, 5}, points=0, answer, result;
for (idxI=0;
idxI<size;
idxI++) { printf("%d/%d=", op1[idxI], op2[idxI]);
scanf("%d", &answer);
result=op1[idxI]/op2[idxI];
printf("%d/%d=%d\n", op1[idxI], op2[idxI], result);
if (answer==result) { points++;
} printf("%d%%%d=", op1[idxI], op2[idxI]);
scanf("%d", &answer);
result=op1[idxI]%op2[idxI];
printf("%d%%%d=%d\n\n", op1[idxI], op2[idxI], result);
if (answer==result) { points++;
} } } printf("You have %d points.\n", points);
return 0;


