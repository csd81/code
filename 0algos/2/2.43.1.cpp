2.43.1.
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h> int main() { clock_t start, end;
int wait;
char temp[50];
double actWait;
srand((unsigned)time(NULL));
printf("Press 'a' and enter to start the clock!\n");
printf("Do the same to stop it!\n");
printf("Type quit to end program!\n");
while (strcmp(temp, "quit") != 0) { wait = rand()%4 + 1;
printf("\nWait for %d seconds!\n", wait);
printf("Begin: ");
scanf("%s", temp);
if (strcmp(temp, "quit")==0) break;
start = clock();
printf("End: ");
scanf("%s", temp);
end = clock();
actWait = (double)(end - start) / CLOCKS_PER_SEC;
printf("You have waited %6.2lf seconds instead of %d. ", actWait, wait);
} return 0;
} 
2.43.1. Írjon időtippelő programot! A program állítson elő egy véletlen 
számot 1 és 5 között és ezt írja ki a képernyőre! Ennyi időt kell majd 
várni a felhasználónak. Ezután kérjen be két sztringet úgy, hogy méri a 
bekérések között eltelt időt! Írja ki, hogy ténylegesen mennyi idő telt 
el a két bekérés között! Ha a bemenet a „quit” sztring, akkor lépjen 
ki a programból! 2.44. Milyen nap?
