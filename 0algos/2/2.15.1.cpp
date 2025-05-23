
2.15.1. Írjon programot, amely bekér egy double értéket kiírja az eredeti értéket a float, int, short int, char típussá konvertált változatok nagyságát és értékeit! A változók méretei jobbra legyenek rendezve és az értékek kiírása azonos oszlopban kezdődjön! 

#include <math.h>
#include <stdio.h> int main() { double doubleValue=1.12345678912346789123456789e5;
printf("%20.20s”, „doubleValue=");
scanf("%lf", &doubleValue);
float floatValue=(float)doubleValue;
int intValue=(int)floatValue;
short int shortIntValue=(short int)intValue;
char charValue=(char)shortIntValue;
printf("%20.20s%d ", "size of double=", sizeof doubleValue);
printf("doubleValue=%25.20lf\n", doubleValue);
printf("%20.20s%d ", "size of float=", sizeof floatValue);
printf("floatValue=%25.20f\n", floatValue);
printf("%20.20s%d ", "size of int=", sizeof intValue);
printf("intValue=%d\n", intValue);
printf("%20.20s%d ", "size of short int=", sizeof shortIntValue);
printf("shortIntValue=%d\n", shortIntValue);
printf("%20.20s%d ", "size of char=", sizeof charValue);
printf("charValue=%d\n", charValue);
return 0;
} 
