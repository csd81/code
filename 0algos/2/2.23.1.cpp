
2.23.1.
#include <stdio.h> int main(int argc, char* argv[]) { int idxI=0;
float x, y;
do { printf("x=");
scanf("%f", &x);
printf("y=");
scanf("%f", &y);
if ( x>100 || -x>100) { printf("x is too big!\n");
continue;
} if (!y) { printf("y equals 0!\n");
break;
} printf("%f/%f=%f\n\n", x, y, x/y);
idxI++;
if (idxI==3) break;
} } while (1);
return 0;

2.23.1. Írjon programot, amely osztást végez el egy hátul tesztelős ciklusban! Használjon végtelen ciklust, amelyet majd break paranccsal fog megszakítani! Kérje be a két változót! Ha az osztandó abszolút értéke nagyobb, mint 100, akkor hiba üzenet után hajtsa végre a következő iterációt! Ha az osztó értéke 0, akkor szakítsa meg a ciklust! Szintén szakítsa meg a ciklust, ha már három osztást elvégzett! 2.24. Deriválás
