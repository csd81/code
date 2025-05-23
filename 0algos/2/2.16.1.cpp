

2.16.1. Írjon programot, amelyben egész változókat használ logikaiként! A változók a következőek: a - van pénzem, b - van kedvem, c - nincs időm, d - nagyon érdekel. Kérje be a változók értékeit és a következők alapján döntse el, hogy megy-e nyaralni: ha van pénze, kedve és ideje, akkor megy, ha az előzőek közül csak egyik igaz, de nagyon érdekli akkor is megy. Írja át a feltételeket DeMorgan azonosságok segítségével! 
#include <math.h>
#include <stdio.h> int main() { int gotMoney, gotMood, noTime, veryInterested;
printf("Type 1 for yes and 0 for no!\n");
printf("gotMoney=");
scanf("%d", &gotMoney);
printf("gotMood=");
scanf("%d", &gotMood);
printf("noTime=");
scanf("%d", &noTime);
printf("veryInterested=");
scanf("%d", &veryInterested);
if ( (gotMoney && gotMood && !noTime) || (gotMoney && veryInterested) || (gotMood && veryInterested) || (!noTime && veryInterested) ) { printf("I will go to holiday!\n");
} else { printf("I will not go to holiday!\n");
} return 0;
} 