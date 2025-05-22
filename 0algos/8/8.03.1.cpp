

8.3.1. Feladat: Írjon programot, amely abc sorrendbe rendez neveket! Kérje be, hogy hány nevet akar rendezni, ezután kérje be a neveket! Rendezze a neveket buborék rendezéssel! Ötlet: használja az stricmp függvényt! 
8.3.1.
#include <stdio.h>
#include <string.h> int main() { int n, idxI, idxJ;
char name[10][30], tempName[30];
} printf("Number of names: ");
scanf("%d",&n);
for(idxI = 0;
idxI < n;
idxI++) { printf("%d. name:", idxI+1);
scanf("%s", name[idxI]);
} for(idxI = 0;
idxI < n;
idxI++) for(idxJ = 0;
idxJ < n;
idxJ++) { if (strcmp(name[idxI], name[idxJ]) < 0) { strcpy(tempName, name[idxI]);
strcpy(name[idxI], name[idxJ]);
strcpy(name[idxJ], tempName);
} } printf("\nThe ordered names are:\n");
for(idxI = 0;
idxI < n;
idxI++) printf("%s\n", name[idxI]);
return 0;