3.8.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { int repeatRequired, repeatAct, num, trial, idxI;
int frequency[6] = {0}, sequence[30];
long int sum = 0;
printf("How much consecutive 6 do you want: ");
scanf("%d", &repeatRequired);
srand((unsigned)time(NULL));
os for (idxI = 0;
idxI < 30;
++idxI) { repeatAct = 0;
trial = 0;
while (repeatAct!=repeatRequired) { num = (rand()%6) + 1;
if (num == 6) else repeatAct=0;
trial++;
} sequence[idxI] = trial;
ismetlesnel } for (idxI = 0;
idxI < 30;
++idxI) { sum += sequence[idxI];
} printf("It's needed on average %d random number to generate %d consecutive 6.\n\n", sum/30, repeatRequired);
return 0;
} 
3.8.2. Módosítsa úgy az előző programot, hogy egy x értékre 30-szor fusson le a program! Átlagosan hány dobás szükséges x darab egymást követő hatoshoz? 3.9. Csúsztatás
