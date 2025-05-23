

2.16.2. Kérje be a következő változókat: a - esik az eső, b - jönnek 
mások is, c - van szabadnapom. Ezen változók alapján határozzuk meg, hogy 
mikor megy a felhasználó túrázni. A feltételek a következőek: akkor 
megyek túrázni ha, nem esik az eső és van szabadnapom;
akkor is túrázom, ha mások nem jönnek, de az eső esik. Írja át a 
feltételeket De Morgan azonosságok segítségével! 
#include <stdio.h> int main() { int isRaining, comeOthers, gotFreeTime;
} printf("Type 1 for yes and 0 for no!\n");
printf("isRaining: ");
scanf("%d", &isRaining);
printf("comeOthers: ");
scanf("%d", &comeOthers);
printf("gotFreeTime: ");
scanf("%d", &gotFreeTime);
if( (!(isRaining || !gotFreeTime)) || (!(!isRaining || comeOthers)) ) 
printf("I'm going hiking!\n");
else printf("Peharps next time.\n");
return 0;