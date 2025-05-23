
2.40.2.
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
} for (idxI = 0;
idxI < depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s>\n", tag);
void printFullTag(FILE* file, int depth, char* tag, char* text) { int idxI;
} for (idxI = 0;
idxI < depth;
idxI++) { fprintf(file, "\t");
} fprintf(file, "<%s\"%s\"/>\n", tag, text);
void printPerson(FILE* file, Person* buddy) { int idxI;
char temp[500];
} printHalfTag(file, 0, "Person");
printFullTag(file, 1, "Name value=", buddy->name);
sprintf(temp, "%d", buddy->age);
printFullTag(file, 1, "Age value=", temp);
printHalfTag(file, 1, "Cars");
for (idxI = 0;
idxI < buddy->carNumber;
idxI++) { printHalfTag(file, 2, "Car");
sprintf(temp, "%d", buddy->myCars[idxI].ID);
printFullTag(file, 3, "Id value", temp);
sprintf(temp, "%lf", buddy->myCars[idxI].price);
printFullTag(file, 3, "Price value=", temp);
printHalfTag(file, 2, "/Car");
} printHalfTag(file, 1, "/Cars");
printHalfTag(file, 0, "/Person");
int main() { const int buddyNumber = 3;
int idxI;
Car init[3][3] = { { { 0, 50 }, { 2, 12.369 }, { 21, 0.569 } }, { { 6, 21 }, { 1, 15.4 } }, { { 3, 5.7 } }, };
Person buddies[3] = { { "Jani", 22, 3, init[0] }, { "Evi", 36, 2, init[1] }, { "Zotya", 25, 1, init[2] } };
FILE *file = NULL;
char fileName[200] = "car.txt";
} file = fopen(fileName, "w");
for (idxI = 0;
idxI < buddyNumber;
idxI++) { printPerson(file, &buddies[idxI]);
} fclose(file);
file = NULL;
printf("XML file created in car.txt.\n");
return 0;

2.40.2. Módosítsa úgy az XML fájlt, hogy Car tag-k egy Cars tag-on belül legyenek! Ahol lehet, az adatok a tagok tulajdonságaiban szerepeljenek! Például: <name value="Jani"/> 

