
2.21.2.
#include <stdio.h> int biggest_denominator(int, int);
int main() { int x, y, z;
int first, second;
printf("Give me the first number: ");
scanf("%d", &x);
printf("Give me the second number: ");
scanf("%d", &y);
printf("Give me the third number: ");
scanf("%d", &z);
first = biggest_denominator(x, y);
second = biggest_denominator(y, z);
printf("The biggest common denominator: %d\n", biggest_denominator(first, 
second));
and second denominations return 0;
} int biggest_denominator(int x, int y) { while (x!=y) { if (x>y) x=x-y;
else y=y-x;
} return x;
} 
2.21.2. Módosítsa úgy a programot, hogy az három szám legnagyobb közös 
osztóját számolja ki! 2.22. main paraméterek
