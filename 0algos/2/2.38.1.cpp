
2.38.1.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> int main() { FILE* tf;
int idxI, data, min, max;
char fileName[200];
double num;
printf("This program will save certain ammount number random number in a 
file.\n");
printf("file name=");
scanf("%s", fileName);
printf("min number=");
scanf("%d", &min);
printf("max number=");
scanf("%d", &max);
printf("number of data=");
scanf("%lf", &num);
srand((unsigned)time(NULL));
tf=fopen(fileName, "w");
if (tf==NULL) { fprintf(stderr, "File open to write has failed!\n");
exit(-1);
} for(idxI=0;
idxI<(int)num;
idxI++) { data = rand()+max+1-min;
fprintf(tf, "%d\n", data);
} fclose(tf);
tf = NULL;
return 0;
} 
2.38.1. Írjon programot, amely bekéri a következő információkat: 
minimális érték, maximális érték fájl név, adatok száma! Generáljon 
adott számú véletlen számot a megfelelő határok között és mentse el 
azokat egy szövegfájlba külön sorokba! 
