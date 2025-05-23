
2.24.1.
#include <stdio.h> float deriv(int whichDerivate, float where) { float result;
switch (whichDerivate) { case 1: result = 9*where*where-4*where+6;
break;
case 2: result = 18*where-4;
break;
case 3: result = 18;
break;
default: result = 0;
printf("\nFirst parameter (%d) is wrong, it should be in 1, 2, or 3\n", 
whichDerivate);
break;
} return result;
} int main() { int idxI;
float where, rez;
printf("Where do you want to calculate the derivate: ");
scanf("%f", &where);
for (idxI=1;
idxI<5;
idxI++) { rez=deriv(idxI, where);
printf("The %d. derivative of 9x^2-4x+6 at %f is: %f\n", idxI, where, rez);
} return 0;
} 
2.24.1. Írjon függvényt és hozzá tartozó programot, amely a 3x3-2x2+6x-1 
függvénynek megadja az 1., 2. vagy 3. deriváltjának az értékét egy adott 
pontban! A függvény paraméterei: hányadik deriváltról van szó, milyen 
pontban tekintjük a deriváltat. A függvény visszatérési értéke: a 
derivált értéke. 
