2.29.1.
#include <stdio.h>
#include <malloc.h> int main() { int choice;
short int *si1=NULL, *si2=NULL;
long double *ld1=NULL, *ld2=NULL;
printf("Short int operands (1)\n");
printf("Long double operands (2)\n");
scanf("%d", &choice);
switch (choice) { case 1: si1 = (short int*)malloc(1*sizeof(short int));
si2 = (short int*)malloc(1*sizeof(short int));
printf("si1=");
scanf("%hd", si1);
printf("si2=");
scanf("%hd", si2);
*si1 = *si1 + * si2;
printf("The increased value is: %hd\n", *si1);
free(si1);
si1=NULL;
free(si2);
si2=NULL;
break;
case 2: ld1 = (long double*)malloc(1*sizeof(long double));
ld2 = (long double*)malloc(1*sizeof(long double));
printf("ld1=");
scanf("%Lf", ld1);
printf("ld2=");
scanf("%Lf", ld2);
*ld1 = *ld1 + *ld2;
printf("The increased value is: %Lf\n", *ld1);
free(ld1);
ld1=NULL;
free(ld2);
ld2=NULL;
break;
} return 0;
} 
2.29.1. Írjon programot, amelyben bekéri, hogy rövid egész vagy hosszú lebegőpontos típussal akar dolgozni. Hozzon létre két dinamikus változót a megfelelő típusból! Kérje be a változók értékeit és az első változó értékét növelje meg a másodikéval! 2.30. Struktúra kezelés
