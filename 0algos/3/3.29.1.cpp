3.29.1. Egy cég termékek vásárlásával és eladásával foglalkozik. Az év elején 10.000 Ft-ja van. Egy fájlban tárolja az információkat a termékekről, az eladásokról és a beszerzésekről. Írjon programot, amely a fájlból beolvassa az adatokat, és megmondja az egyes termékek mennyiségét, illetve a cég egyenlegét az eladások és beszerzések után! Használjon dinamikus tömböket és struktúrákat az adatok tárolására! Az input fájl formátuma: Első sor: Number1 - a termékek száma A következő Number1 db sor: String Number2 Number3 Number4 String: az i-edik termék neve Number2: az i-edik termék mennyisége Number3: az i-edik termék beszerzési ára Number4: az i-edik termék eladási ára Number5: a termékekkel kapcsolatos adás-vételek száma Az ezután következő Number5 db sor: Number6 Number7 Number6: Az aktuális termék indexe (nem a neve, hanem a sorszáma) Number7: Ha ez a szám pozitív, a cég beszerzett a Number6-os termékből Number7 db-ot, beszerzési áron;
ha negatív, akkor a cég a Number6-os termékből eladott Number7 abszolút értékének megfelelő számú darabot, eladási áron. Példa bemenet: 2 hammer 100 500 800 screwdriver 50 300 400 2 1 10 2 -5 A példafájl esetében kétféle termékünk van: 100 db hammer és 50 db screwdriver. A cég 500 Ft-ért tud hammer-t beszerezni, és 800 Ft-ért tudja eladni. 2 féle termékmozgás történt, először vásároltak 500 Ft/db áron 10 db hammer-t, majd 400 Ft/db áron eladtak 5 db screwdriver-t. Kimenet: Inventory: **************************************** hammer: Count: 100 Purchase price: 500 Shop price: 800 screwdriver: Count: 50 Purchase price: 300 Shop price: 400 Inventory: **************************************** hammer: Count: 110 Purchase price: 500 Shop price: 800 screwdriver: Count: 45 Purchase price: 300 Shop price: 400 We have got 7000 HUF 3.30. Könyvtári rendszer
3.29.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "inventory.txt" #define MAX_LENGTH 15 #define START_MONEY 10000 struct TGood { int count;
int purchaseprice;
int shopprice;
char name[MAX_LENGTH];
};
int ReadInventory(FILE * fd, struct TGood ** Good) { int num, i;
fscanf(fd, "%d", &num);
(*Good) = (struct TGood*)malloc(sizeof(struct TGood) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s %d %d %d", (*Good)[i].name, &(*Good)[i].count, &(*Good)[i].purchaseprice, &(*Good)[i].shopprice);
return num;
} void PrintInventory(struct TGood * G, int num) { int i;
printf("Inventory:\n****************************************\n");
for (i = 0;
i < num;
i++) printf("%s:\n\tCount: %d\n\tPurchase price: %d\n\tShop price: %d\n", G[i].name, G[i].count, G[i].purchaseprice, G[i].shopprice);
} int ReadLog(FILE * fd, int Money, int num, struct TGood * G) { int lognum, i;
int good, a;
fscanf(fd, "%d", &lognum);
for (i = 0;
i < lognum;
i++) { fscanf(fd, "%d %d", &good, &a);
G[good - 1].count += a;
if (a > 0) Money -= abs(a) * G[good - 1].purchaseprice;
else Money += abs(a) * G[good - 1].shopprice;
} return Money;
} int main(int argc, char *argv[]) { struct TGood * Inventory;
int GoodNum;
int Money = START_MONEY;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} GoodNum = ReadInventory(fd, &Inventory);
PrintInventory(Inventory, GoodNum);
Money = ReadLog(fd, Money, GoodNum, Inventory);
PrintInventory(Inventory, GoodNum);
printf("We have got %d HUF\n", Money);
fclose(fd);
free(Inventory);
Inventory = NULL;
return 0;
} 
