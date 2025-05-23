// 3.13.2. Bővítse úgy a programot, hogy az új sztring egy megfelelően hosszú dinamikus tömbbe kerüljön! Készítse el a visszafele kódoló függvényt! 3.14. Sztring kivonás
3.13.2.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h> int main() { char original[255], *newVer;
int idxI, idxJ;
printf("Sentence: ");
gets(original);
newVer = (char*) malloc (sizeof(char)*strlen(original));
foglalas idxJ = 0;
for (idxI = 0;
idxI < strlen(original);
idxI++) { if (toupper(original[idxI]) != 'V') { newVer[idxJ] = toupper(original[idxI]);
idxJ++;
} else { if ( toupper(original[idxI]) == toupper(original[idxI + 2]) ) { newVer[idxJ++] = toupper(original[idxI++]);
newVer[idxJ++] = toupper(original[idxI++]);
idxI++;
} else idxI++;
} } newVer[idxJ] = '\0';
printf("%s\n", newVer);
free(newVer);
return 0;
} 

