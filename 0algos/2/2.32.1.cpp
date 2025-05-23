
2.32.1.
#include <stdio.h>
#include <string.h>
#include <malloc.h> typedef struct { char manufacturer[20];
int productNumber;
char* description;
float price;
} Fan;
Fan readFan() { Fan rec;
int descriptionLength;
printf("Provide the data of the fan!\n");
printf("manufacturer: ");
gets(rec.manufacturer);
printf("product number: ");
scanf("%d", &rec.productNumber);
printf("max description length: ");
scanf("%d", &descriptionLength);
rec.description = (char*)malloc(sizeof(char)*descriptionLength);
_flushall();
printf("description: ");
gets(rec.description);
printf("price:");
scanf("%f", &rec.price);
return rec;
} void printFan(Fan rec) { printf("Fan data\n");
printf("manufacturer: %s\n", rec.manufacturer);
printf("product number:%d\n", rec.productNumber);
printf("description:%s\n", rec.description);
printf("price:%5.2f HUF\n", rec.price);
} int main() { Fan myFan;
myFan = readFan();
printFan(myFan);
free(myFan.description);
myFan.description=NULL;
return 0;
} 
2.32.1. Írjon programot, amelyben létrehoz egy ventilátor típust: gyártó 
(statikus tömb), termékszám, leírás (dinamikus tömb), ár! Írjon 
függvényt, amely bekéri az adattagok értékét és a rekordot 
visszatérési értékként adja vissza! Szintén írjon függvényt a 
struktúra kiírásához!
