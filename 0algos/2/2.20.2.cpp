
2.20.2.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> void wait(int seconds) { clock_t endwait;
endwait = clock() + seconds * CLOCKS_PER_SEC;
while (clock() < endwait) { } } int main() { int idxI, idxJ = 0, size = 0;
while (1) { system("clear");
size = 4;
if (idxJ == 25) idxJ = 0;
if (idxJ >= 23) { for (idxI = idxJ;
idxI >= 23;
idxI--) { printf("***\n");
size -= 1;
} } for (idxI = 1;
idxI <= idxJ;
idxI++) printf("\n");
for (idxI = 1;
idxI < size;
idxI++) printf("***\n");
wait(1);
idxJ++;
} } return 0;

2.20.2. Módosítsa úgy a programot, hogy amint a négyzet eltűnik alul, felül jelenjen meg újból! 
