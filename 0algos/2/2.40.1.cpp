
2.40.1.
#include <stdio.h>
#include <stdlib.h> typedef struct { int ID;
double price;
} Car;
typedef struct { char name[200];
int age;
int carNumber;
Car* myCars;
} Person;
void printHalfTag(FILE* file, int depth, char* tag) { int idxI;
for (idxI=0;
idxI<depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s>\n", tag);
} void printFullTag(FILE* file, int depth, char* tag, char* text) { int idxI;
for (idxI=0;
idxI<depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s>%s</%s>\n", tag, text, tag);
} void printPerson(FILE* file, Person* buddy) { int idxI;
char temp[500];
printHalfTag(file, 0, "Person");
printFullTag(file, 1, "Name", buddy->name);
sprintf(temp, "%d", buddy->age);
printFullTag(file, 1, "Age", temp);
printFullTag(file, 1, "Count", buddy-> carNumber);
for (idxI=0;
idxI<buddy->carNumber;
idxI++) { printHalfTag(file, 1, "Car");
sprintf(temp, "%d", buddy->myCars[idxI].ID);
printFullTag(file, 2, "ID", temp);
sprintf(temp, "%lf", buddy->myCars[idxI].price);
printFullTag(file, 2, "price", temp);
printHalfTag(file, 1, "/Car");
} printHalfTag(file, 0, "/Person");
} int main() { const int buddyNumber=3;
int idxI;
Car init[buddyNumber][3]={ { {0, 50}, {2, 12.369}, {21, 0.569} }, {{6, 21}, {1, 15.4}}, {{3, 5.7}}, };
Person buddies[buddyNumber]={{"Jani", 22, 3, init[0]}, {"Evi", 36, 2, init[1]}, {"Zotya", 25, 1, init[2]} };
FILE *file=NULL;
char fileName[200]="car.txt";
file = fopen(fileName, "w");
for (idxI=0;
idxI<buddyNumber;
idxI++) { printPerson(file, &buddies[idxI]);
} fclose(file);
file = NULL;
return 0;
} 
2.40.1. Írjon programot, amely XML-ben ment el rekordokat! A kocsi típus azonosítót és árat, a személy típus nevet, életkort, a kocsik számát, és kocsi tömböt tartalmaz. Hozzon létre és inicializáljon egy 3 hosszú személy tömböt és mentse el azokat XML fájlba! Az XML fájl legyen szépen tördelve! Írjon halfTag és fullTag függvényeket! Az előbbi csak „<tagName>” vagy „</tagName>” -t ír ki, az útóbbi „<tagName> Text </tagName>”-t ír ki. Példa: <Person> <Name>Jani</Name> <Age>22</Age> <Count>3</ Count> <Car> <ID>0</ID> <price>50.000000</price> </Car> <Car> … 
