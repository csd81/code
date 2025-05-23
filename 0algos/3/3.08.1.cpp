// 3.8. Kockadobás
// 3.8.1. Írjon programot, amely kockadobást szimulál véletlen számok 
// generálásával! Kérjen be egy sorozat hosszt, x-t, és addig generáljon 
// véletlen számokat, amíg nem jelenik meg egymás után x darab hatos! Hány 
// dobás után kaptuk meg a kívánt eredményt? Számolja az egyes dobások 
// gyakoriságát! 

// 3.8.1.

#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { int repeatRequired, repeatAct, num, trial, idxI;
int frequency[6]={0};
printf("How much consecutive 6 do you want: ");
scanf("%d", &repeatRequired);
srand((unsigned)time(NULL));
repeatAct=0;
trial=0;
while (repeatAct!=repeatRequired) { num = (rand()%6)+1;
frequency[num-1]++;
if (num==6) repeatAct++;
else repeatAct=0;
trial++;
} printf("It needed %d random number to generate %d consecutive 6.\n\n", trial, 
repeatRequired);
printf("Meanwhile we generated\n");
for (idxI=0;
idxI<6;
idxI++) printf("%d pieces of %d\n", frequency[idxI], idxI+1);
return 0;
} 

