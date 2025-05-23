
2.32.2.
#include <stdio.h>
#include <string.h>
#include <malloc.h> typedef struct { char manufacturer[20];
int productNumber;
char* description;
float price;
} Fan;
Fan readFan() { Fan rec;
int descriptionLength;
} printf("Provide the data of the fan!\n");
printf("manufacturer: ");
scanf("%s", rec.manufacturer);
printf("product number: ");
scanf("%d", &rec.productNumber);
printf("max description length: ");
scanf("%d", &descriptionLength);
rec.description = (char*) malloc(sizeof(char) * descriptionLength);
printf("description: ");
scanf("%s", rec.description);
printf("price: ");
scanf("%f", &rec.price);
return rec;
void printFan(Fan rec) { printf("manufacturer: %s\n", rec.manufacturer);
} printf("product number:%d\n", rec.productNumber);
printf("description:%s\n", rec.description);
printf("price:%5.2f HUF\n", rec.price);
int main() { Fan myFan,myFan2;
myFan = readFan();
myFan2=myFan;
myFan.description="A new file";
printf("Fan data\n");
printFan(myFan);
printf("Fan2 data\n");
printFan(myFan2);
free(myFan.description);
myFan.description = NULL;
free(myFan2.description);
myFan2.description = NULL;
} return 0;

2.32.2. Módosítsa úgy a programot, hogy a ventilátor változó értékét tegye egyenlővé egy másik változóval, módosítsa az eredeti változóban a gyártót és a leírást! Írassa ki újból mindkét struktúrát! Milyen furcsaságot tapasztal? Hogy lehet azt korrigálni? 2.33. Többszörösen összetett típus
