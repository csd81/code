3.6.1. A karakteres képernyőn reprezentáljon egy 4 hosszú egész tömböt! 
Kérje be a tömb elemeit és írja ki az értékeket '*' szimbólumokból 
készített négyzetekbe! Adja meg az egyes elemek indexeit és címeit! Írja 
ki a tömb mint mutató értékét és annak a címét! 3.2. ábra: Lehetséges 
képernyőkép
3.6.1.
#include <stdio.h>
#include <math.h> int main() { const int size=4;
int tomb[size];
int idxI, idxJ;
for (idxI=0;
idxI<size;
idxI++) { printf("The %d. value: ", idxI);
scanf("%d", &tomb[idxI]);
} printf("\n%20.20s", " ");
for (idxI=0;
idxI<size;
idxI++) { for (idxJ=0;
idxJ<12;
idxJ++) { printf("*");
} printf("");
} } printf("\n%20.20s", " ");
for (idxI=0;
idxI<size;
idxI++) { printf("*%10d* ", tomb[idxI]);
} printf("\n%20.20s", " ");
for (idxI=0;
idxI<size;
idxI++) { for (idxJ=0;
idxJ<12;
idxJ++) { printf("*");
} printf("");
} printf("\n%20.20s", "index: ");
for (idxI=0;
idxI<size;
idxI++) { printf("%-13d", idxI);
} printf("\n%20.20s", "address: ");
for (idxI=0;
idxI<size;
idxI++) { printf("%-#13p", &tomb[idxI]);
} printf("\n%20.20s%#p", "tomb: ", tomb);
printf("\n%20.20s%#p", „&tomb: ", &tomb);
printf("\n%20.20s%d", "tomb size: ", size);
return 0;


