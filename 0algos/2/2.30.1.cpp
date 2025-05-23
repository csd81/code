
2.30.1.
#include <stdio.h> struct Var { char varChar;
short int varShortInt;
int varInt;
float varFloat;
double varDouble;
};
long double varLongDouble;
int *varPInt;
int main() { struct Var myVar;
printf("varChar=");
scanf("%c", &myVar.varChar);
printf("varShortInt=");
scanf("%hd", &myVar.varShortInt);
printf("varInt=");
scanf("%d", &myVar.varInt);
printf("varFloat=");
scanf("%f", &myVar.varFloat);
printf("varDouble=");
scanf("%lf", &myVar.varDouble);
printf("varLongDouble=");
scanf("%Lf", &myVar.varLongDouble);
printf("varPInt=");
scanf("%p", &myVar.varPInt);
} printf("\nmyVar\n");
printf("varChar=%c\n", myVar.varChar);
printf("varShortInt=%hd\n", myVar.varShortInt);
printf("varInt=%d\n", myVar.varInt);
printf("varFloat=%g\n", myVar.varFloat);
printf("varDouble=%lg\n", myVar.varDouble);
printf("varLongDouble=%Lg\n", myVar.varLongDouble);
printf("varPInt=%p", myVar.varPInt);
return 0;

2.30.1. Készítsen struktúrát, amely minden egyszerű adattípusból tartalmaz egyet valamint egy egészre mutató mutatót! Kérje be a struktúra adattagjait a konzolról, majd írja ki azokat! 
