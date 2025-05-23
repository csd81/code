
2.31.1.
#include <stdio.h>
#include <malloc.h> typedef struct { char name[200];
int age;
int ID;
} Person;
typedef struct { int carat;
float price;
int numberOfStones;
} Ring;
typedef struct { Person man, wife;
Ring weddingRing, engagementRing;
int guestNumber;
Person *guests;
} Wedding;
void printPerson(Person myPerson) { printf("person{");
printf("name=%s, ", myPerson.name);
printf("age=%d, ", myPerson.age);
printf("ID=%d}", myPerson.ID);
} void printRing(Ring myRing) { printf("ring{");
} printf("carat=%d, ", myRing.carat);
printf("price=%f, ", myRing.price);
printf("number of stones=%d}", myRing.numberOfStones);
void printWedding(Wedding myWedding) { int idxI;
printf("wedding{\n\tman=");
printPerson(myWedding.man);
printf(",\n\twife=");
printPerson(myWedding.wife);
printf(",\n\twedding ring=");
printRing(myWedding.weddingRing);
printf(",\n\tengagement ring=");
printRing(myWedding.engagementRing);
printf(",\n\tGuests={");
for (idxI=0;
idxI<myWedding.guestNumber;
idxI++) { printf("\n\t\t");
printPerson(myWedding.guests[idxI]);
printf(",");
} printf("\n\t}\n}");
} int main() { const int friendNumber=3;
Person friends[friendNumber]={{"Jani", 28, 12345}, {"Emese", 29, 66666}, 
{"Zoli", 32, 222222}};
Wedding brotherWedding={ {"Arpi", 32, 23332}, {"Panna", 29, 22222}, {16, 60000, 
0}, {24, 200000, 3}, friendNumber, friends };
printf("brotherWedding=");
printWedding(brotherWedding);
return 0;
} 
2.31.1. Készítsen programot, amely tartalmazza a következő 
adatszerkezeteket: ember típus: név, életkor, azonosító;
gyűrű típus: karát, érték, kövek száma;
esküvő típus: férj, feleség, eljegyzési gyűrű, esküvői gyűrű, 
vendégek (dinamikus tömb), vendégek száma. Inicializáljon egy esküvő 
típusú változót, írja ki a változó értékét szépen tördelve úgy, 
hogy minden struktúra kiíráshoz külön függvényt hoz létre! 2.32. 
Ventilátor
