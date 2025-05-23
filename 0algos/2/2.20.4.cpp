
2.20.4.
#include <stdio.h>
#include <time.h>
#include <stdlib.h> void wait(int seconds) { clock_t endwait;
endwait = clock() + seconds * CLOCKS_PER_SEC;
while (clock() < endwait) ;
} int main() { int idxI, idxJ = 0, direction;
char string [] = "*****";
while (1) { system("clear");
for (idxI = 1;
idxI < 4;
idxI++) eggyel elcsusztatva printf("%*.5s\n", idxJ + 5, string);
wait(1);
if (idxJ == 75) direction = 0;
else if (idxJ == 0) direction=1;
if (direction) idxJ++;
else idxJ--;
} } return 0;

2.20.4. Négyzet helyett téglalap mozogjon vízszintesen a szélekről visszapattanva! 2.21. Legnagyobb közös osztó
