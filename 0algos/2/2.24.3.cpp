
2.24.3.
#include <stdio.h> float deriv(float posX, float poly4, float poly3, float poly2, float poly1, float poly0) { return ( 4*poly4*pow(posX,3) + 3*poly3*pow(posX,2) + 2*poly2*pow(posX,1) + poly1 );
} int main() { float posX, poly4, poly3, poly2, poly1, poly0;
printf("What function do you want to derivate?\n");
printf("x^4: ");
scanf("%f", &poly4);
printf("x^3: ");
scanf("%f", &poly3);
printf("x^2: ");
scanf("%f", &poly2);
printf("x^1: ");
scanf("%f", &poly1);
printf("constant: ");
scanf("%f", &poly0);
printf("So, the ");
if (poly4) printf("%f x^4 ", poly4);
if (poly3) printf("%+f x^3 ", poly3);
if (poly2) printf("%+f x^2 ", poly2);
if (poly1) printf("%+f x^1 ", poly1);
if (poly0) printf("%+f ", poly0);
printf("will be derivated.\n");
printf("Where do you want to calculate the derivate: ");
scanf("%f", &posX);
printf("The first derivative of the function at %f is: %f\n", posX, deriv(posX, poly4, poly3, poly2, poly1, poly0));
return 0;
} 
2.24.3. Tetszőleges negyed-fokú polinomnak határozza meg a deriváltját adott pontban! Legyen a függvénynek egy harmadik paramétere, ahol jelezzük, ha hiba történt, vagyis ha az első paraméter értéke helytelen, vagyis négynél nagyobb! 2.25. Lépésenkénti összegzés
