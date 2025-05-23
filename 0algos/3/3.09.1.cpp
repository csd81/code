3.9.1.
#include <stdio.h> void print(float a, float b, float c) { printf("a=%f b=%f c=%f\n", a, b, c);
} void shift(float* a, float* b, float* c, int cyclic) { float temp;
} temp = *c;
*c = *b;
*b = *a;
if (cyclic) *a = temp;
else *a = 0;
int main() { float x1, x2, x3;
} printf("Provide the next number: ");
scanf("%f", &x1);
printf("Provide the next number: ");
scanf("%f", &x2);
printf("Provide the next number: ");
scanf("%f", &x3);
printf("Original: ");
print(x1, x2, x3);
shift(&x1, &x2, &x3, 1);
printf("After cyclic shift: ");
print(x1, x2, x3);
shift(&x1, &x2, &x3, 0);
printf("After non-cyclic shift: ");
print(x1, x2, x3);
return 0;

3.9.1. Írjon függvényt, amely 3 cím szerint átadott float paraméter értékét (a, b és c) elcsúsztatja a következő módon: ciklikus eltolás: a → b, b → c, c → a, nem ciklikus eltolás: a → b, b → c, 0 → a! Egy negyedik paraméter jelezze, hogy az eltolás ciklikus-e! 
