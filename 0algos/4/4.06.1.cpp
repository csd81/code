4.6.1.
#include <stdio.h>
#include <stdlib.h> struct TElement { struct TElement * next;
int Data;
};
struct TList { struct TElement * Head;
struct TElement * Actual;
};
void InitList(struct TList * L) { L->Head = L->Actual = NULL;
} void Add(struct TList * L, int data) { if (L->Head == NULL) L->Head = L->Actual = (struct TElement *)malloc(sizeof(struct TElement));
else { L->Actual->next = (struct TElement *)malloc(sizeof(struct TElement));
L->Actual = L->Actual->next;
} L->Actual->Data = data;
L->Actual->next = NULL;
} void PrintList(struct TList * L) { if (L->Head == NULL) return;
L->Actual = L->Head;
printf("The list: ");
while (L->Actual->next) { printf("%d ", L->Actual->Data);
L->Actual = L->Actual->next;
} printf("%d\n", L->Actual->Data);
} void FreeList(struct TList * L) { struct TElement * tmp;
if (L->Head == NULL) return;
L->Actual = L->Head;
do { tmp = L->Actual;
L->Actual = L->Actual->next;
free(tmp);
tmp = NULL;
} while (L->Actual);
} int main() { struct TList List;
int num;
InitList(&List);
do { printf("Type a number: ");
scanf("%d", &num);
if (num != 0) { if (num != -1) Add(&List, num);
else PrintList(&List);
} } while (num != 0);
FreeList(&List);
return 0;
} 
4.6.1. Írjon programot, amely számokat olvas be a billentyűzetről addig, amíg a beolvasott szám nem 0! A program fűzze a beolvasott számot egy egyszeresen láncolt lista végére! A -1 gépelése után írja ki a képernyőre a lista tartalmát! Valósítsa meg az add és print függvényeket, valamint a lista felszabadítását! Példa: Type a number: 10 Type a number: 20 Type a number: 30 Type a number: -1 The list: 10 20 30 Type a number: 40 Type a number: 50 Type a number: -1 The list: 10 20 30 40 50 Type a number: 0 4.7. Prímszita
