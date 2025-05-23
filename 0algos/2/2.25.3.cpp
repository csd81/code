
2.25.3.
#include <stdio.h> int sum(int data, int subTotal) { subTotal += data;
return subTotal;
} int main() { int num, total, subTotal=0;
char more = 'y';
} do { printf("Provide the next number: ");
scanf("%d", &num);
subTotal = sum(num, subTotal);
printf("Are there more number: (y/n) ");
_flushall();
scanf("%c", &more);
} while (more == 'y');
total = subTotal;
printf("The total is %d.\n", total);
return 0;

2.25.3. Módosítsa úgy az előző programot, hogy nem használ statikus változót, hanem paraméterként adja át az eddigi részösszeget! 2.26. Alias változók
