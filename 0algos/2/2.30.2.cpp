

2.30.2.
#include <stdio.h>
#include <malloc.h> struct Var { char varChar;
short int varShortInt;
int varInt;
float varFloat;
double varDouble;
long double varLongDouble;
int *varPInt;
};
typedef struct Var VarType;
void readVarType(VarType *myVar) { printf("varChar=");
scanf("%c", &myVar->varChar);
printf("varShortInt=");
scanf("%hd", &myVar->varShortInt);
printf("varInt=");
scanf("%d", &myVar->varInt);
printf("varFloat=");
scanf("%f", &myVar->varFloat);
printf("varDouble=");
scanf("%lf", &myVar->varDouble);
printf("varLongDouble=");
} scanf("%Lf", &myVar->varLongDouble);
myVar->varPInt = &myVar->varInt;
void printVarType(VarType myVar) { printf("\nmyVar\n");
printf("varChar=%c\n", myVar.varChar);
printf("varShortInt=%hd\n", myVar.varShortInt);
printf("varInt=%d\n", myVar.varInt);
printf("varFloat=%g\n", myVar.varFloat);
printf("varDouble=%lg\n", myVar.varDouble);
printf("varLongDouble=%Lg\n", myVar.varLongDouble);
printf("*varPInt=%d", *myVar.varPInt);
} int main() { VarType myVar, *copy=NULL;
readVarType(&myVar);
printVarType(myVar);
copy = (VarType*)malloc(sizeof(VarType)*1);
*copy = myVar;
printVarType(*copy);
*((*copy).varPInt)=666;
printVarType(myVar);
free(copy);
copy=NULL;
return 0;
} 
2.30.2. Módosítsa az előző programot úgy, hogy létrehoz új típusnevet a struktúrának és ezt használja a továbbiakban! Külön függvényben valósítsa meg a struktúra bekérő és kiíró részt! Hozzon létre egy dinamikus struktúrát, amit tegyen egyenlővé a bekért struktúrával! Módosítsa a dinamikus struktúrán keresztül az egész mutató által mutatott értéket! 2.31. Esküvő
