
// 3.1.2. Alakítsa át a program kiírását úgy, hogy a bekért szó függőlegesen jelenjen meg és a hozzá tartozó kiírások az egyes karakterektől jobbra helyezkedjenek el! 3.2. Osztás és maradékképzés
3.1.2.
#include <stdio.h> int main() { const int size = 6;
int idxI;
char string[size + 1];
} printf("string=");
scanf("%6s", string);
printf("The string is: %s\n", string);
printf("The static string address, string: %p\n", string);
printf("The dynamic string address, &string: %p\n", &string);
for (idxI = 0;
idxI < size;
idxI++) { printf("\'%c\'", string[idxI]);
if (string[idxI] == 0) { printf("\t0x");
printf("%#-2x", string[idxI]);
} else { printf("\t%#-2x", string[idxI]);
} printf("\tstring[%d] ", idxI);
printf("\t%p ", &(string[idxI]));
printf("\n");
} return 0;

