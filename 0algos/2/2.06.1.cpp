2.6.1.
#include <stdio.h> int main() { int id;
unsigned int age;
char sex, name[200];
float weight;
double accountBalance;
} printf("id=");
scanf("%d", &id);
printf("age=");
scanf("%u", &age);
_flushall();
printf("sex=");
scanf("%c", &sex);
printf("weight=");
scanf("%f", &weight);
printf("account balance=");
scanf("%lf", &accountBalance);
printf("name=");
scanf("%s", name);
printf("\nYour data!\n");
printf("id=%d\n", id);
printf("age=%u\n", age);
printf("sex=%c\n", sex);
printf("weight=%f\n", weight);
printf("account balance=%lf\n", accountBalance);
printf("name=%s", name);
return 0;

2.6.1. Írjon programot, amellyel bekéri egy ember adati közül a 
következőket: azonosító szám - int, életkor - unsigned int, neme - char, 
súlya - float, bankszámla egyenlege - double, neve - char[200]! A bekért 
adatokat írja ki újból a képernyőre! A megadott és a kiírt érték mikor 
különbözhet? Mutasson rá példát! 
