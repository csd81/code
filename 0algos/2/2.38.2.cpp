
2.38.2.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> int main() { FILE* tf;
int idxI, data, min, max, db = 0;
char fileName[200];
int num;
printf("This program will save certain ammount number random number in a 
file.\n");
printf("file name=");
scanf("%s", fileName);
printf("min number=");
scanf("%d", &min);
printf("max number=");
scanf("%d", &max);
printf("number of data=");
scanf("%d", &num);
srand((unsigned) time(NULL));
tf = fopen(fileName, "w");
if (tf == NULL) { fprintf(stderr, "File open to write has failed!\n");
exit(-1);
} fprintf(tf, "%d\n", num);
for (idxI = 0;
idxI < num;
idxI++) { data = rand() % (max + 1 - min) + min;
fprintf(tf, „%d\t”, data);
db++;
if (db == 100) { fprintf(tf, "\n");
db = 0;
} } fclose(tf);
tf = NULL;
return 0;
} 
2.38.2. Módosítsa úgy a programot, hogy az első sorba írja ki az adatok 
számát! Szóközökkel válassza el az egyes értékeket és minden számot 
fix hosszan írjon ki! 100 számonként szúrjon be egy üres sort! 2.39. 
Hamupipőke
