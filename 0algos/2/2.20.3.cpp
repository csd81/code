
2.20.3.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> void wait(int seconds) { clock_t endwait;
endwait = clock() + seconds * CLOCKS_PER_SEC;
while (clock() < endwait) ;
} int main(){ int idxI, idxJ, row = 0, direction;
while(1) { system("clear");
for (idxI = 1;
idxI <= row;
idxI++) printf("\n");
for (idxJ = 0;
idxJ < 3;
idxJ++) { for (idxI = 2 - idxJ;
idxI > 0;
idxI--) printf("");
for (idxI = 0;
idxI <= 2*idxJ;
idxI++) printf("*");
printf("\n");
} wait(1);
if (row == 22) direction = 0;
else if (row == 0) direction = 1;
if (direction) row++;
else row--;
} return 0;
} 
2.20.3. Módosítsa úgy a programot, hogy négyzet helyett háromszög 
jelenjen meg, ami alulról pattanjon vissza! 
