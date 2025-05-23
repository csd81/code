
2.24.2. A sin(x) függvénynek határozza meg az 1., 2. vagy 3. deriváltjának az értékét egy adott pontban! Használja fel, hogy sin'(x) = cos(x), cos'(x) = -sin(x). 
2.24.2.
#include <stdio.h>
#include <math.h> float deriv(int whichDerivate, float posX) { float result;
switch (whichDerivate%4) { case 0: result = sin(posX);
break;
case 1: result = cos(posX);
break;
case 2: result = -sin(posX);
break;
case 3: result = -cos(posX);
break;
default: result = 0;
printf("\nError!\n");
break;
} return result;
} int main() { int idxI;
float posX, result;
int times;
printf("Where do you want to calculate the derivate of sin(x) (in radian): ");
scanf("%f", &posX);
printf("How many times? ");
scanf("%d", &times);
for (idxI = 1;
idxI <= times;
idxI++) { result = deriv(idxI, posX);
printf("The %d. derivative of sin(x) at %f is: %f\n", idxI, posX, result);
} return 0;
} 
