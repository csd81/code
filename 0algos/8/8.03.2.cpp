

8.3.2.
#include <stdio.h>
#include <string.h> int main() { int numberOfNames, idxI, idxJ;
char name[10][30], prefix[10][30], tempName[30];
printf("Number of names: ");
scanf("%d", &numberOfNames);
for (idxI = 0;
idxI < numberOfNames;
idxI++) { printf("%d. prefix: ", idxI + 1);
scanf("%s", prefix[idxI]);
printf("%d. name:", idxI + 1);
scanf("%s", name[idxI]);
} for (idxI = 0;
idxI < numberOfNames;
idxI++) { for (idxJ = 0;
idxJ < numberOfNames;
idxJ++) { if (strcmp(name[idxI], name[idxJ]) < 0) { strcpy(tempName, name[idxI]);
strcpy(name[idxI], name[idxJ]);
strcpy(name[idxJ], tempName);
strcpy(tempName, prefix[idxI]);
strcpy(prefix[idxI], prefix[idxJ]);
strcpy(prefix[idxJ], tempName);
} } } } printf("\nThe ordered names are:\n");
for (idxI = 0;
idxI < numberOfNames;
idxI++) printf("%s %s\n", prefix[idxI], name[idxI]);
return 0;

8.3.2. Módosítsa úgy a programot, hogy a különböző előtagok (Dr., prof., PhD., …) ne befolyásolják a sorrendet! 8.4. Rendezett láncolt lista
