2.3.2.
#include <stdio.h> int main() { float a, b;
char figure, property;
printf("Program to calculate the area or perimeter of a rectengular or square.\n");
printf("Calculate rectengular (r) or square (s) ");
scanf("%c", &figure);
if (figure=='r') { printf("a=");
scanf("%f", &a);
printf("b=");
scanf("%f", &b);
printf("Would you like to calculate area (a) or perimeter (p) ? ");
scanf("%c", &property);
if (property=='a') { printf("The area of the rectengular is: %f", a*b);
} else { printf("The perimeter of the rectengular is: %f", (a+b)*2);
");
} } } else { printf("a=");
scanf("%f", &a);
printf("Would you like to calculate area (a) or perimeter (p) ? scanf("%c", &property);
if (property=='a') { printf("The area of the square is: %f", a*a);
} else { printf("The perimeter of the square is: %f", a*4);
} } return 0;

2.3.2. Módosítsa az előző programot úgy, hogy az oldalak hossza tört érték is lehessen! A program elején kérje be, hogy négyzet vagy téglalapot vizsgál-e és ennek függvényében kérjen be egy vagy két oldal hosszat! 
