
// 3.19.1. Készítsen gépelést tanító programot! Sztring tömbben 
tároljon 20 különféle szót! Kérje be, hogy hány szót akar gépelni, 
véletlenszerűen válasszon ki egyet, amit megjelenít, és aztán várja azt 
bemenetként! Hibás bevitel esetén kérje be újból a szót! A gyakorlás 
végén írja ki az eltelt időt és a helyes és elrontott szavak számát! 
3.20. Nagy számok összeadása
3.19.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> int main() { char words[][50]={"element", "size", "love", 
"ball", "toy", "gambit", "cruiser", "shadow", "console", "Atlantis", "port", 
"staple", "Leonardo", "bug", "hope", "vanity", "time", "issue", "fan", 
"strength"};
char temp[50];
int size=sizeof(words)/sizeof(*words);
int trial, idxI, randIndex, errors=0;
clock_t start, finish;
double duration;
srand((unsigned)time(NULL));
printf("How much word would you like to type: ");
scanf("%d", &trial);
start = clock();
for (idxI=0;
idxI<trial;
idxI++) { randIndex = rand() % size;
printf("type: %s\n", words[randIndex]);
scanf("%s", temp);
while (strcmp(temp, words[randIndex]) != 0) { printf("error!\n");
errors++;
scanf("%s", temp);
} } finish = clock();
duration = (double)(finish - start) / CLOCKS_PER_SEC;
printf("Ellapsed time: %4.2lf\n", duration);
} printf("Number of good trials: %d, bad trials: %d", trial, errors);
return 0;

