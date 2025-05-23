3.3.1.
#include <stdio.h> int main() { char string[]="23 35678 1.2345e11 -9.8765432e-11";
short int shortIntValue;
int intValue;
float floatValue;
double doubleValue, sum;
sscanf(string, "%hd %d %f %lf", &shortIntValue, &intValue, &floatValue, &doubleValue);
sum = shortIntValue + intValue + floatValue + doubleValue;
sprintf(string, "%lf", sum);
printf("The sum is %s", string);
return 0;
} 
3.3.1. Készítsen programot, amely statikus karaktertömbben lévő 4 számot átkonvertál short int, int, float és double típusra! A számok összegét írja be az eredeti tömbbe! 
