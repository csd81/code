2.21.1.
#include <stdio.h> int main() { int x, y;
printf("Give me the first number: ");
scanf("%d",&x);
printf("Give me the second number: ");
scanf("%d",&y);
while (x!=y) { if (x>y) x=x-y;
else y=y-x;
} printf("The biggest common denominator: %d\n", x);
return 0;
} 
2.21.1. Írjon programot, amely kiszámolja két szám legnagyobb közös 
osztóját a következő algoritmus segítségével! ciklus amíg a két szám 
nem egyenlő a nagyobb szám értékét csökkentsük a kisebb számmal 
