3.28.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "cds.txt" #define MAX_WORD_LENGTH 16 #define TRUE 1 #define FALSE 0 typedef char TWord[MAX_WORD_LENGTH];
struct TCD { int Num;
TWord Name;
TWord * P;
};
void ReadCD(FILE * fd, struct TCD * A) { int i;
fscanf(fd, "%s", A->Name);
fscanf(fd, "%d", &A->Num);
printf("%s:\n", A->Name);
A->P = (TWord *)malloc(sizeof(TWord) * A->Num);
for (i = 0;
i < A->Num;
i++) { fscanf(fd, "%s", A->P[i]);
printf("\t%s\n", A->P[i]);
} } int ReadCDs(FILE * fd, struct TCD ** A) { int num, i;
fscanf(fd, "%d", &num);
(*A) = (struct TCD * )malloc(sizeof(struct TCD) * num);
for (i = 0;
i < num;
i++) ReadCD(fd, (*A) + i);
return num;
} void Search(struct TCD * A, char * S, int num) { int i = 0;
int j;
int success = FALSE;
while ((i < num) && (!success)) { j = 0;
while ((j < A[i].Num) && (strcmp(A[i].P[j], S) != 0)) j++;
success = j < A[i].Num;
i++;
} if (success) printf("The %s is here: %s\n", S, A[i - 1].Name);
else printf("%s does not exists!\n", S);
} void FreeCDs(struct TCD * A, int num) { int i;
for (i = 0;
i < num;
i++) { free(A[i].P);
A[i].P = NULL;
} } int main(int argc, char * argv[]) { int CDNum;
struct TCD * CDs;
TWord Word;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} CDNum = ReadCDs(fd, &CDs);
fclose(fd);
printf("Program name: ");
scanf(„%s”, Word);
Search(CDs, Word, CDNum);
FreeCDs(CDs, CDNum);
free(CDs);
CDs = NULL;
return 0;
} 
3.28.1. Rendelkezik egy CD katalógussal, amit fájlban tárol. Írjon programot, amely képes arra, hogyha begépeli egy szoftver nevét, akkor megmondja, melyik CD-n van a szoftver! A szoftverek nevei maximum 15 karakter hosszúak, és minden CD-nek van egy neve, amely szintén maximum 15 karakter hosszú. Használjon struktúrákat, illetve dinamikus tömböket a fájlból beolvasott adatok tárolására! Az input fájl formátuma: Első sor: A CD-k száma. A további sorok: String: A CD neve Egész szám: A CD-n lévő szoftverek száma Ezután a CD-n lévő szoftverek neve következik. Példa bemenet: 2 2007/11 2 BurningStudio RadioRama 2005/4 3 Doc2PDF Apollo Stellarium A példában Jamesnek 2 CD-je van, az első neve „2007/11”, ezen a CD-n két szoftver van: BurningStudio és RadioRama. A másik CD 3 szoftvert tartalmaz. Kimenet: Software name: Apollo The Apollo is here: 2005/4 
