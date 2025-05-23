2.58.1. A Hanoi tornyai játék 3 rudat tartalmaz (start, segéd, cél). Az 
első rúdon N db korong van egymás fölött, amelyek különböző 
méretűek. A korongok fentről lefelé növekvő sorrendben következnek, 
legnagyobb van legalul, a legkisebb legfelül, ahogyan az ábrán látható. A 
feladat a következő: a korongokat át kell rakni a start rúdról a célra, a 
segédrúd segítségével. Az átrakás szabálya, hogy nagyobb korongot 
kisebbre nem rakhatunk rá. Írjon programot ennek a feladatnak a 
szimulálására! A program argumentumként megkapja N értékét. Kezdetben 
minden korong a start rúdon van. Minden lépésben kérdezze meg, melyik 
rúdról melyikre tegyük át a legfelső korongot! Ha ez nem ellenkezik a 
szabályokkal, helyezzük át a korongot! Minden mozgatás után írja ki a 
képernyőre a korongok helyzetét, a példában látható módon! Ha a 
felhasználó 0-t gépel, vagy minden korong a cél rúdon van, a program 
véget ér. Használjon dinamikus tömböket és struktúrákat a korongok 
helyének tárolására! 2.4. ábra: Hanoi tornyai szemléltetése Példa 
bemenet: ************************************* Source: 3, 2, 1 Auxiliary: 0 
Destination: 0 From: aux To: src Incorrect step! 
************************************* Source: 3, 2, 1 Auxiliary: 0 Destination: 
0 From: src To: aux ************************************* Source: 3, 2 
Auxiliary: 1 Destination: 0 From: src To: dst 
************************************* Source: 3 Auxiliary: 1 Destination: 2 
From: aux To: dst ************************************* Source: 3 Auxiliary: 0 
Destination: 2, 1 From: 0 The disks are not on the destination! 
************************************* Source: 3 Auxiliary: 0 Destination: 2, 1 
2.59. Törtek összeadása
2.58.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_RINGNUM 3 #define TRUE 1 #define FALSE 0 
#define NAMELEN 12 struct TTower { int MaxHeight;
int Height;
int * Disks;
char Name[NAMELEN];
};
void InitTower(struct TTower * T, int height, int full, char * name) { int i;
T->Disks = (int*)malloc(sizeof(int) * height);
T->MaxHeight = height;
strcpy(T->Name, name);
if (full) { for (i = height;
i >= 1;
i--) T->Disks[height - i] = i;
T->Height = height;
} else { for (i = 0;
i < height;
i++) T->Disks[i] = 0;
T->Height = 0;
} } void FreeTower(struct TTower * T) { free(T->Disks);
T->Disks = NULL;
T->Height = T->MaxHeight = 0;
} void PrintTower(struct TTower * T) { int i;
printf("%s: ", T->Name);
for (i = 0;
i < T->Height - 1;
i++) printf("%d, ", T->Disks[i]);
printf("%d\n", T->Disks[i]);
} int GetIndex(char * S) { if (strcmp(S, "src") == 0) return 0;
if (strcmp(S, "aux") == 0) return 1;
if (strcmp(S, "dst") == 0) return 2;
return -1;
} int IsCorrect(int f, int t, struct TTower * Towers) { if ((f == -1) || (t == 
-1)) return FALSE;
if (f == t) return FALSE;
if (Towers[f].Height == 0) return FALSE;
if (Towers[f].Disks[Towers[f].Height - 1] > Towers[t].Disks[Towers[t].Height - 
1]) return FALSE;
return TRUE;
} int isComplete(struct TTower * T) { int i;
for (i = T->MaxHeight;
i >= 1;
i--) if (T->Disks[ T->MaxHeight - i] != i) return FALSE;
return TRUE;
} int main(int argc, char * argv[]) { char From[5];
char To[5];
int f, t;
int giveup;
struct TTower Towers[3];
int MaxH = argc > 1 ? atoi(argv[1]) : DEFAULT_RINGNUM;
InitTower(Towers, MaxH, TRUE, "Source");
InitTower(Towers + 1, MaxH, FALSE, "Auxiliary");
InitTower(Towers + 2, MaxH, FALSE, "Destination");
do { printf("\n\n*************************************\n\n");
PrintTower(Towers);
PrintTower(Towers + 1);
PrintTower(Towers + 2);
printf("From: ");
scanf("%s", From);
if (From[0] != '0') { printf("To: ");
scanf("%s", To);
} giveup = ((From[0] == '0') || (To[0] == '0'));
if (!giveup) { f = GetIndex(From);
t = GetIndex(To);
if (IsCorrect(f, t, Towers)) { Towers[t].Disks[Towers[t].Height++] = 
Towers[f].Disks[Towers[f].Height - 1];
Towers[f].Disks[--Towers[f].Height] = 0;
} else printf("Incorrect step!\n");
} } while ((!giveup) && !isComplete(Towers + 2));
if (!giveup) printf("The disks are on their's place!\n");
else printf("The disks are not on the destination!\n");
} printf("\n\n*************************************\n\n");
PrintTower(Towers);
PrintTower(Towers + 1);
PrintTower(Towers + 2);
FreeTower(Towers);
FreeTower(Towers + 1);
FreeTower(Towers + 2);
return 0;

