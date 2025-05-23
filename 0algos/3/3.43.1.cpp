3.43.1.-3.34.3.
#include <stdio.h>
#include <stdlib.h> #define AKTUALIS_EV 2010 int main(int argc, char** argv) { FILE * fd = fopen(argv[1], "r");
if (fd == NULL) { perror("Hiba");
return EXIT_FAILURE;
} int kiskoru = 0;
int felnott = 0;
int nyugdijas = 0;
int vh2 = 0;
int szokoevben = 0;
int eletkor;
while (!feof(fd)) { if (fscanf(fd, "%d", &eletkor)) { if (eletkor < 18) { kiskoru++;
} else { felnott++;
if (eletkor >= 62) { nyugdijas++;
} } int ev = AKTUALIS_EV - eletkor;
if (ev >= 1939 && ev <= 1945) { vh2++;
} printf("ev: %d\n", ev);
if ((ev % 400 == 0) || (ev % 4 == 0 && ev % 100 != 0)) { printf("szokoev\n");
szokoevben++;
} } } fclose(fd);
} printf("Kiskoruak: %d\n", kiskoru);
printf("Felnottek: %d\n", felnott);
printf("Nyugdijasok: %d\n", nyugdijas);
printf("Vilaghaboru alatt: %d\n", vh2);
printf("Szokoevben: %d\n", szokoevben);
return EXIT_SUCCESS;
3 3 5 2 3 
3.43.1. Egy 5000 fős település lakosainak adatait kell feldolgoznunk. Van egy fájlunk, amely a lakosok életkorát tartalmazza. Írjon programot, amely kiírja a képernyőre, hogy mennyi kiskorú, felnőtt, nyugdíjas él a teleülésen! Kiskorúnak számít az, aki még nem töltötte be a 18. életévét, egyébként a felnőttek közé soroljuk. A nyugdíjkorhatár 62 év. 
3.43.2. Bővítse ki az előző programot úgy, hogy a program kiírja, hogy hányan születtek a második világháború alatt (1939-1945). Az aktuális év 2010. 
3.43.3. Bővítse ki az előző programot úgy, hogy a program kiírja azt is, hogy hányan születtek szökőévben! Szökőévnek számítanak azok az évek, ahol az évszám osztható 4-el, de a 100-asra végződőek közül csak azok, amelyek oszthatóak 400-al. Ez alapján szökőév volt 1992, 1996, de 1900 nem, viszont 2000 igen. 3.44. Kerítés
