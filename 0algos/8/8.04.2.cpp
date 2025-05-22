
8.4.2. Egészítse ki a lista struktúrát egy egésszel, amely az elemek számát mutatja a listában! Módosítsa a függvényeket, hogy azok kezeljék az új adattagot! 8.5. Kupacrendezés
8.4.2.
#include <stdio.h>
#include <malloc.h>
#include <string.h> typedef struct { int ID;
double size;
char origin[100];
} DataType;
typedef struct le { DataType* data;
struct le* next;
struct le* prev;
} listElem;
typedef struct { struct le head;
struct le tail;
int count;
} List;
void displayListElem(DataType* data) { printf("(ID: %d, ", data->ID);
printf("size: %lf, ", data->size);
printf("origin: %s)", data->origin);
} void deleteList(List* myList) { listElem *act;
act = myList->head.next;
if (act == &myList->tail) return;
while (act != &myList->tail) { act = act->next;
free(act->prev);
} } void listList(List* myList) { listElem *act=myList->head.next;
printf("List elments: ");
while (act != &myList->tail) { displayListElem(act->data);
act = act->next;
if (act != &myList->tail) printf(", ");
} printf("\n");
printf("Element count: %d\n", myList->count);
} void insert(List* myList, DataType* newData) { listElem *act=myList->head.next, *newElem=NULL, *beforeElem=NULL, *afterElem=NULL;
while (act != &myList->tail && act->data->ID > newData->ID) { // check it's ID field 
    act = act->next;
} afterElem = act;
beforeElem = act->prev;
newElem = (listElem*)malloc(sizeof(listElem));
newElem->data = newData;
beforeElem->next = newElem;
newElem->next = afterElem;
afterElem->prev = newElem;
newElem->prev = beforeElem;
} int main() { List myList={NULL};
myList.count = 0;
myList.head.next = &myList.tail;
myList.tail.prev = &myList.head;
DataType testData[]={{1, 2.3, "Hu"}, {7, 12.3, „Ro”}, {0, 45.3, "Eu"}, {5, 14.1, "Gb"} };
int idxI;
for (idxI=0;
idxI<4;
idxI++) { printf("Insert ");
displayListElem(&testData[idxI]);
printf("\n");
insert(&myList, &testData[idxI]);
myList.count += 1;
listList(&myList);
printf("\n");
} printf("Count: %d\n", myList.count);
deleteList(&myList);
return 0;
} 
