3.45.2-3.45.3.
#include <stdio.h>
#include <stdlib.h>
#include <math.h> #define N 10 typedef struct lista { struct lista * kovetkezo;
int jegy;
} lista;
int main() { lista * jegyek = NULL;
int i;
int osszeg = 0;
int jegy;
double atlag;
i = 1;
do { printf("%d. jegy: ", i++);
scanf("%d", &jegy);
osszeg += jegy;
if (jegy > 0) { lista * elem = (lista *) malloc(sizeof (lista));
elem->jegy = jegy;
if (jegyek == NULL) { elem->kovetkezo = NULL;
} else { elem->kovetkezo = jegyek;
} jegyek = elem;
} } while (jegy > 0);
atlag = (double) osszeg / (i - 2);
lista * temp = jegyek;
lista * prev;
double elteres = 0;
while (temp != NULL) { elteres += (atlag - temp->jegy) * (atlag - temp->jegy);
prev = temp;
temp = temp->kovetkezo;
free(prev);
} double szoras = sqrt(elteres / (i - 2));
printf("A jegyek szamtani atlaga: %g\n", atlag);
printf("A jegyek szorasa: %g\n", szoras);
return EXIT_SUCCESS;
} 
3.45.2. Bővítse ki az előző programot úgy, hogy 0 végjelig olvassa be a jegyeket és úgy végzi el a számolást! 
3.45.3. Fejlessze tovább a programot úgy, hogy a jegyek szórását is meghatározza! Határozza meg az egyes jegyek átlagtól való eltérésit, utána ezen eltérések négyezeteinek az átlagát, majd az így kapott eredmény gyökét! 3.46. Nyúltenyésztés
