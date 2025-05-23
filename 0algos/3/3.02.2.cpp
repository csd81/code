3.2.2. Továbbra is meg kell tippelni a megoldást, de az operandusokat 
generálja véletlenszerűen -10 és 10 között! Véletlenszerűen döntse el 
azt is, hogy egész vagy lebegőpontos osztást végez! Utóbbinál függvényt 
kell használni a maradékképzésre. Lebegőpontos osztásnál mindig írja ki 
a tizedes pontot az operandusoknál! 

3.2.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { int A,B,TIP;
double result;
} srand(time(NULL));
A=((rand() % 20));
B=((rand() % 20));
TIP=(rand() % 2);
if(!TIP){ result=A/B;
printf("Integer division:\n");
printf("%d/%d=%d\n",A,B,(int)result);
}else{ result=(double)A/(double)B;
printf("Floating point division:\n");
printf("%d/%d=%.4lf\n",A,B,result);
} return 0;


