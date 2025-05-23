3.44.1. Egy 400 méter kerületű telket szeretnénk körülvenni drótkerítéssel. Több köteg drótkerítésünk van, amelyek hosszát egyenként ismerjük. Írjon programot, amely 0 végjelig beolvassa az egyes kötegek hosszait, majd a végén kiírja, hogy összesen hány méternyi kerítésünk van és, ha kell-e még kerítést vennünk, akkor összesen mennyit! 3.45. Jegyek átlaga Aladár év végén szeretné kiszámolni, hogy mely tantárgyból hányasra áll. Minden tárgyból sok jegyet szerzett, ezért úgy véli, fárasztó munka lenne kézzel átlagokat számolni, ezért számítógépes segítséghez folyamodik.
3.44.1.
#include <stdio.h>
#include <stdlib.h> int main() { int koteg;
int osszeg = 0;
do { printf("Kerem a keriteskoteg hosszat: ");
scanf("%d", &koteg);
osszeg += koteg;
} while (koteg > 0);
printf("Osszesen van %d meter kerites\n", osszeg);
if (osszeg < 400) { printf("Meg kell %d meternyi kerites\n", 400 - osszeg);
} return EXIT_SUCCESS;
} 
