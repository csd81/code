
8.6.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "words.txt" #define MAX_LENGTH 16 #define TRUE 1 #define FALSE 0 typedef char TWord[MAX_LENGTH];
int Greater(char * A, char * B) { int i;
int sa = strlen(A);
int sb = strlen(B);
int min = sa < sb ? sa : sb;
for (i = 0;
i < min;
i++) { if (A[i] > B[i]) return TRUE;
if (A[i] < B[i]) return FALSE;
} return sa > sb;
} int ReadWords(FILE * fd, TWord ** W) { int num, i;
fscanf(fd, "%d", &num);
(*W) = (TWord *)malloc(sizeof(TWord) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s", (*W)[i]);
return num;
} void PrintWords(TWord * W, int num) { int i;
for (i = 0;
i < num;
i++) printf("\t%d.: %s\n", i + 1, W[i]);
} void Sort(TWord * W, int num) { int min, i, j;
TWord Temp;
for (i = 0;
i < num - 1;
i++) { min = i;
for (j = i;
j < num;
j++) { if (Greater(W[min], W[j])) min = j;
} strcpy(Temp, W[min]);
strcpy(W[min], W[i]);
strcpy(W[i], Temp);
} } int main(int argc, char * argv[]) { TWord * Words;
int WNum;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror(„Error”);
return 0;
} WNum = ReadWords(fd, &Words);
} fclose(fd);
printf("Read words:\n");
PrintWords(Words, WNum);
Sort(Words, WNum);
printf("\n***************\nSorted words:\n");
PrintWords(Words, WNum);
free(Words);
Words = NULL;
return 0;
7 WARIOR APPLE SZOKOZSHIP BOOK SZOKOZ PHISIC LIMON 

8.6.1. Írjon programot, amely szavakat rendez növekvő sorrendbe az strcmp függvény használata nélkül! A szavak csak nagybetűkből állnak. A program olvassa be fájlból a szavakat, és írja ki azokat a képernyőre növekvő sorrendben. Ha egy szó megegyezik egy másik, hosszabb szó elejével, akkor a hosszabb szó szerepel később. Például: SO < SOAP. A szavak maximális hossza 15 karakter. Használjon dinamikus tömböket a szavak tárolásához! A sorrendnél a betűk ASCII kódja számít. Az input fájl formátuma: Első sor: A szavak száma. A többi sor egy-egy szót tartalmaz. Példa bemenet: 7 WARIOR APPLE SZOKOZSHIP BOOK SZOKOZ PHISIC LIMON Kimenet: Read words: 1.: WARIOR 2.: APPLE 3.: SOAP 4.: BOOK 5.: SO 6.: PHISIC 7.: LIMON *************** Sorted words : 1.: APPLE 2.: BOOK 3.: LIMON 4.: PHISIC 5.: SO 6.: SOAP 7.: WARIOR 8.7. Emlékeztetők
