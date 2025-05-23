3.9.2. 3 változó helyett egy 3 elemű tömbön végezze el az 
elcsúsztatást! 
3.9.2.
#include <stdio.h> void print(float a[], int size) { int i;
for(i = 0;
i < size;
++i) printf("a[%d]= %f ", i, a[i]);
printf("\n");
} void shift(float* a, int cyclic) { float temp;
} temp = a[2];
a[2] = a[1];
a[1] = a[0];
if (cyclic) a[0] = temp;
else a[0] = 0;
int main() { float x[3];
} printf("Provide the next number: ");
scanf("%f", &x[0]);
printf("Provide the next number: ");
scanf("%f", &x[1]);
printf("Provide the next number: ");
scanf("%f", &x[2]);
printf("Original: ");
print(x, 3);
shift(x, 1);
printf("After cyclic shift: ");
print(x, 3);
shift(x, 0);
printf("After non-cyclic shift: ");
print(x, 3);
return 0;

