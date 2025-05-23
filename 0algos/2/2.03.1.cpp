2.3.1.
#include <stdio.h> int main() { int a, b;
char decision;
printf("Program to calculate the area or perimeter of a rectengular.\n");
printf("a=");
scanf("%d", &a);
printf("b=");
scanf("%d", &b);
printf("Would you like to calculate area (a) or perimeter (p) ? ");
scanf("%c", &decision);
if (decision=='a') { printf("The area of the rectengular is: %d", a*b);
} else { printf("The perimeter of the rectengular is: %d", (a+b)*2);
} } return 0;

2.3.1. Írjon programot, amely bekéri egy téglalap két oldalának a 
hosszát, és hogy területet vagy kerületet akar-e a felhasználó számolni! 
A választástól függően számolja ki a területet vagy a kerületet! Az 
oldal hosszak egész értékek, a választás karakter típusú. Ötlet: 
ügyeljen arra, hogy negatív nagyságú oldal nincsen! 
