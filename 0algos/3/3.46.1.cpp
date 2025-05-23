3.46.1.-3.46.2.
#include <stdio.h>
#include <stdlib.h> int main() { unsigned long long int termekeny = 0, termeketlen = 1;
unsigned long long int osszesen = termeketlen;
int honap;
int ev;
for (ev = 1;
ev <= 5;
ev++) { for (honap = 1;
honap <= 12;
honap++) { unsigned long long int nyulakUj = termekeny + termeketlen;
osszesen += nyulakUj;
termekeny = termeketlen;
termeketlen = nyulakUj;
printf("%d\n", nyulakUj);
} van\n", termekeny *= 0.1;
termeketlen *= 0.05;
printf("eladas utan %llu termekeny es %llu termeketlen nyulpar termekeny, termeketlen);
printf("Osszesen %llu adag tapra lesz szukseg\n", osszesen * 2);
} return EXIT_SUCCESS;
} 
3.46.1. Mr. Fibonacci elhatározta, hogy belevág a nyúltenyésztésbe. Az első hónapban vesz egy újszülött nyúlpárt. Minden nyúl 2 hónap után válik termékennyé. Minden hónapban minden termékeny nyúlpár egy új nyúlpárt szül. A nyulakat etetni kell, minden nyúl egy zsák nyúltápot fogyaszt el minden hónapban és egy nyúlpár se pusztul el. Írjon programot, amely meghatározza, hogy hány zsák nyúltápot kell vásárolni egy évre, ha az első hónapban 1 nyúlpár van! 
3.46.2. Bővítse ki az előző programot úgy, hogy 3 évre előre számoljon, figyelembe véve, hogy Mr. Fibonacci minden év elején eladja a termékeny nyulak 90 %-át, és a terméketlenek 95 %-át! Amennyiben az eladandó nyulak mennyisége nem egész szám, úgy ezt az értéket mindig lefele kerekítjük. Például 101 termékeny nyúl esetén 90-et adunk el. 3.47. Jegyek
