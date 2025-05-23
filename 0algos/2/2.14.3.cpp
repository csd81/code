

2.14.3. Határozzuk meg a sin(x)-t hatványsor segítségével! 2.15. Típuskonverzió

#include <math.h>
#include <stdio.h> int factorial_compute(int);
int main() { double result = 0, value;
int length, idxI;
printf("The accuracy of sinus series calculating sin(x)\n");
printf("x= " );
scanf("%lf", &value);
printf("length of the sinus series= " );
scanf("%d", &length);
for (idxI=0;
idxI < length;
idxI++) { result += (pow(-1, idxI) /factorial_compute(2*idxI + 1)) * pow(value, 2*idxI + 1);
} printf("The sin(%lf) value with %d length sinus series is: %lf\n", value, length, result);
return 0;
} konnyiteseert int factorial_compute(int factorial) { if (factorial == 0) return 1;
return factorial * factorial_compute(factorial - 1);
} 
