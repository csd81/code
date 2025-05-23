2.54.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> #define MIN_TIP 1 #define EASY_MAX 5 #define MEDIUM_MAX 10 
#define HARD_MAX 15 #define START_MONEY 1000 int GetStake() { int stake;
do { printf("Take your stake: ");
scanf("%d", &stake);
if (stake <= 0) printf("The stake have to higher than zero!\n");
} while (stake <= 0);
return stake;
} int GetTip(int min, int max) { int tip;
do { printf("What's your tip (%d..%d)? ", min, max);
scanf("%d", &tip);
if ((tip > max) || (tip < min)) printf("The tip have to be between %d and 
%d!\n", min, max);
} while ((tip > max) || (tip < min));
return tip;
} int GetMax() { int d;
do { printf("Choose the difficulty!\n\n");
printf("\tEasy:...........1\n");
printf("\tMedium:.........2\n");
printf("\tHard:...........3\n\n");
scanf("%d", &d);
if ((d > 3) || (d < 1)) printf("Wrong number!\n");
} while ((d > 3) || (d < 1));
switch (d) { case 1: return EASY_MAX;
case 2: return MEDIUM_MAX;
case 3: return HARD_MAX;
} return 0;
} int Random(int min, int max) { return (rand() % (max - min)) + min;
} int main() { int stake, tip;
int max;
int num;
int Money = START_MONEY;
char s[5];
srand(time(NULL));
max = GetMax();
printf("You have %d HUF now.\n", Money);
do { printf("\n\n");
stake = GetStake();
num = Random(MIN_TIP, max);
tip = GetTip(MIN_TIP, max);
if (tip == num) { Money += stake;
printf("You've hit the number!\nYou have %d HUF!\n", Money);
} else { printf("The number was %d\n", num);
Money -= stake;
printf("You have %d HUF!\n", Money);
} if (Money > 0) { printf("Try again? (y/n)\n");
scanf("%s", s);
} } while (((s[0] == 'y') || (s[0] == 'Y')) && (Money > 0));
if (Money > 0) printf("Congratulations!\nYou get %d HUF!\n", Money);
else printf("I'm sorry, you lost\n");
srand(time(NULL));
return 0;
} 
2.54.1. Írjon hazárdjátékot! A szabályok a következők: A játék 
kezdetekor a játékosnak 1000 Ft-ja van. A program generál egy véletlen 
számot, a játékosnak pedig meg kell adnia egy tippet, és egy tétet. Ha 
eltalálja a számot, megkapja a tét összegét, ha nem, elveszíti. Ezután a 
program megkérdezi: „Try again? (y/n)”, a játékosnak pedig egy „y” 
vagy egy „n” karakterrel kell válaszolnia. Ha újból próbálkozik, akkor 
a program új számot generál. A játék addig folytatódik, amíg a 
játékosnak van pénze, vagy amíg nem szeretné befejezni a játékot. 3 
különböző szint van: a „könnyű”, amelyben a program 1 és 5 közötti 
számot generál, a „közepes”, amelyben 1 és 10 közötti számot 
generál, és a „nehéz”, amelyben 1 és 15 közötti számot generál. A 
szintet a játék megkezdése előtt választja ki a játékos, egy egyszerű 
menü segítségével. A játék végén a program írja ki a képernyőre, 
mennyit nyert vagy veszített a játékos. Példa játék: Choose the 
difficulty! Easy:...........1 Medium:.........2 Hard:...........3 2 You have 
1000 HUF now. Take your stake: 10 What's your tip (1..10)? 5 You've hit the 
number! You have 1010 HUF! Try again? (y/n) y Take your stake: 1000 What's your 
tip (1..10)? 1 The number was 7 You have 10 HUF! Try again? (y/n) n 
Congratulations! You get 10 HUF! 2.55. Dátumellenőrzés

