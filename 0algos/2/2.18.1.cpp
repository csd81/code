

2.18.1.
#include <stdio.h> int main() { char num;
printf("Roman to arabic number converter");
printf("\nGive me a roman number: ");
scanf("%c", &num);
if (num > 'Z') num = num - ('a'-'A');
switch (num) { case 'I': printf("\n1");
break;
case 'V': printf("\n5");
break;
case 'X': printf("\n10");
break;
case 'L': printf("\n50");
break;
case 'C': printf("\n100");
break;
case 'D': printf("\n500");
break;
case 'M': printf("\n1000");
break;
default: printf("\nWrong character");
} return 0;
} 
2.18.1. Írjon programot, amely megadja, hogy mik a római számjegyek (I, V, L, C, D, M) arab megfelelői! Kérjen be egy római számjegyet, konvertálja nagybetűre, ha szükséges és adja meg a szám értéket! 
