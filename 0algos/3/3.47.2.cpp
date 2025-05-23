3.47.2.
#include <stdio.h>
#include <stdlib.h> int main() { double jegy;
int sorszam = 1;
do { printf("Kerem a %d. atlagot: ", sorszam++);
scanf("%lf", &jegy);
} while (jegy >= 1.5);
if (jegy == 0.0 || jegy >= 1.5) { printf("Nem volt bukas!\n");
} else { printf("Volt bukas!\n");
} return EXIT_SUCCESS;
} 
3.47.2. Módosítsa az előző programot úgy, hogy addig olvassa be az átlagokat, amíg bukott embert nem talál! Amennyiben 0-t olvasunk be, az azt jelenti, hogy vége a beolvasásnak, vagyis ez nem egy átlag. A program ez esetben is írja ki, hogy bukik-e valaki! 3.48. Marsjáró A Mars Explorer 3000-es marsjáró robot utazása során 100 méterenként feljegyzi, hogy a bolygón való leszállóhelyéhez viszonyítva milyen magasan / mélyen jár, így egy domborzati keresztmetszetet továbbít a földi irányító központba. Szeretnénk részletesen megvizsgálni a bejárt terepet. A vizsgálatra számítógépet használunk. A domborzati magasságokat egy tömbben tároljuk.
