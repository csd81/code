2.50.1.
#include <stdio.h>
#include <stdlib.h> #define INPUT_FILE "sets.txt" #define max(a, b) ((a) > (b) 
? (a) : (b)) #define min(a, b) ((a) > (b) ? (b) : (a)) void ReadSet(FILE * fd, 
int * size, int ** set) { int i;
fscanf(fd, "%d", size);
*set = (int *)malloc(sizeof(int) * (*size) );
for (i = 0;
i < *size;
i++) fscanf(fd, "%d", *set + i);
printf("\n");
} void PrintSet(char * name, int size, int * set) { int i;
printf("%s = ", name);
printf("{");
for (i = 0;
i < size - 1;
i++) } printf("%d, ", set[i]);
if (size > 0) printf("%d", set[size - 1]);
printf("}\n");
int Element(int e, int size, int * S) { int i = 0;
while ((i < size) && (S[i] != e)) i++;
return i < size;
} void Intersection(int SizeA, int SizeB, int * SizeI, int * SA, int * SB, int 
** C) { int size = 0;
int i;
*SizeI = 0;
int * A = SizeA > SizeB ? SA : SB;
int * B = SizeA > SizeB ? SB : SA;
for (i = 0;
i < max(SizeA, SizeB);
i++) { if (Element(A[i], max(SizeA, SizeB), A) && Element(A[i], min(SizeA, 
SizeB), B) ) (*SizeI)++;
} *C = (int *)malloc(sizeof(int) * (*SizeI) );
for (i = 0;
i < max(SizeA, SizeB);
i++) { if (Element(A[i], max(SizeA, SizeB), A) && Element(A[i], min(SizeA, 
SizeB), B) ) (*C)[size++] = A[i];
} } int IsSubset(int SizeA, int SizeS, int * A, int * S) { int i;
if (SizeS > SizeA) return 0;
for (i = 0;
i < SizeS;
i++) if (!Element(S[i], SizeA, A)) return 0;
return 1;
} int main(int argc, char *argv[]) { int SetASize, SetBSize, SetISize;
int * SetA;
int * SetB;
int * SetI;
int num;
FILE * fd = fopen(argc > 1 ? argv[1] : INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} ReadSet(fd, &SetASize, &SetA);
ReadSet(fd, &SetBSize, &SetB);
fclose(fd);
Intersection(SetASize, SetBSize, &SetISize, SetA, SetB, &SetI);
printf("Type a number: ");
scanf("%d", &num);
if (Element(num, SetASize, SetA)) printf("%d is element of A\n", num);
else printf("%d is not element of A\n", num);
if (Element(num, SetBSize, SetB)) printf("%d is element of B\n", num);
else printf("%d is not element of B\n", num);
if (Element(num, SetISize, SetI)) printf("%d is element of intersection of A 
and B\n", num);
else printf("%d is not element of intersection of A and B\n", num);
PrintSet("A", SetASize, SetA);
PrintSet("B", SetBSize, SetB);
PrintSet("Intersection of A and B", SetISize, SetI);
if (IsSubset(SetASize, SetBSize, SetA, SetB)) printf("B is subset of A\n");
else printf("B is not subset of A\n");
if (IsSubset(SetBSize, SetASize, SetB, SetA)) printf("A is subset of B\n");
else printf("A is not subset of B\n");
} free(SetA);
SetA = NULL;
free(SetB);
SetB = NULL;
free(SetI);
SetI = NULL;
return 0;

2.50.1. Írjon programot, amely két halmaz metszetét generálja! Mindkét 
halmaz egész számokat tartalmaz. A program olvassa be az input fájlt! 
Kérjen be egy számot a billentyűzetről, és döntse el, hogy a szám 
eleme-e az első halmaznak, a második halmaznak, illetve ezek metszetének! 
Írassa ki a képernyőre az előbbi három halmazt! Végül írassa ki, hogy 
az első halmaz részhalmaza-e a másodiknak, illetve fordítva! Használjon 
dinamikus tömböket! Az input fájl formátuma: Első sor: az első halmaz 
mérete Második sor: az első halmaz elemei Harmadik sor: a második halmaz 
mérete Negyedik sor: a második halmaz elemei A számok egy-egy szóköz 
karakterrel vannak elválasztva. Példa bemenet: 3 80 54 41 5 41 21 54 76 80 
Kimenet: Type a number: 76 76 is not element of A 76 is element of B 76 is not 
element of intersection of A and B A = {80, 54, 41} B = {41, 21, 54, 76, 80} 
Intersection of A and B = {41, 54, 80} B is not subset of A A is subset of B 
2.51. Halmazok uniója
