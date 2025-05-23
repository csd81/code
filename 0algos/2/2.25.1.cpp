

2.25.1.
#include <stdio.h> int sum(int data) { static int result;
result += data;
return result;
} int main() { int num, total;
char more='y';
do { printf("Provide the next number: ");
scanf("%d", &num);
total = sum(num);
printf("Are there more number: (y/n) ");
_flushall();
scanf("%c", &more);
} while (more=='y');
printf("The The total is %d.\n", total);
return 0;
} 
2.25.1. Írjon programot, amely a konzolról kér be egész számokat egy 
ciklus segítségével és egy függvény segítségével számolja ki azok 
összegét! Ezt a függvényt minden szám bekérése után hívja, ami ezután 
visszaadja az eddigi számok összegét. Használjon statikus változót a 
részösszeg tárolására! 
