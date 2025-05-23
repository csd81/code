

2.14.1. Írjunk programot, amely hatványsor és könyvtári függvény segítségével is kiszámolja ex értékét a következő képlettel: = ! Megfelelően pontos értéket kapunk, ha a sort a negyedik elemig határozzuk meg. Írjuk ki a hatványsor és a valós érték közötti különbséget!
2.14.1.
#include <math.h>
#include <stdio.h> int main() { double result, accurateResult, value;
int length, faktor, idxI;
printf("The accuracy of power series calculating e^x\n");
printf("x=" );
scanf("%lf", &value);
printf("lengtgh of the power series=" );
scanf("%d", &length);
accurateResult = exp(value);
result = 1;
faktor = 1;
for (idxI=1;
idxI<length;
idxI++) { result += pow(value, idxI)/faktor;
faktor*=(idxI+1);
} printf("The difference between the power series and the exact value is %lf", accurateResult-result);
return 0;
} 