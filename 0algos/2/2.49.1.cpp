2.49.1.
#include <stdio.h>
#include <stdlib.h> #define NEV_HOSZ 11 #define INPUT_FILE "in.txt" struct TSubscriber { char FirstName[NEV_HOSZ];
char LastName[NEV_HOSZ];
int InRushH, OutRushH;
int TotalMin, Fee;
};
void read(FILE * fd, int num, struct TSubscriber * Subscribers) { int i;
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s", Subscribers[i].FirstName, Subscribers[i].LastName);
fscanf(fd, "%d %d", &Subscribers[i].InRushH, &Subscribers[i].OutRushH);
} } void calc(int num, struct TSubscriber * A, int csucs, int kedv) { int i;
int MaxMin = 0;
int MaxFee = 0;
for (i = 0;
i < num;
i++) { A[i].Fee = A[i].InRushH * csucs + A[i].OutRushH * kedv;
A[i].TotalMin = A[i].InRushH + A[i].OutRushH;
printf("\t\t\t %5d Ft %5d minute\r%s %s :\n", A[i].Fee, A[i].TotalMin, A[i].FirstName, A[i].LastName);
if (MaxMin < A[i].TotalMin) MaxMin = A[i].TotalMin;
if (MaxFee < A[i].Fee) MaxFee = A[i].Fee;
} printf("\nHighest fee: %d Ft\n", MaxFee);
for (i=0;
i<num;
i++) { if (A[i].Fee == MaxFee) } printf("\t%s %s\n", A[i].FirstName, A[i].LastName);
} printf("\nLongest speaking: %d Ft\n", MaxMin);
for (i=0;
i<num;
i++) { if (A[i].TotalMin == MaxMin) printf("\t%s %s\n",A[i].FirstName, A[i].LastName);
} int main() { struct TSubscriber * Subscribers = NULL;
int inrush, outrush, num;
FILE * fd = fopen(INPUT_FILE, "r");
if (fd == NULL) { perror("Hiba");
return 0;
} fscanf(fd, "%d", &num);
fscanf(fd, "%d %d", &inrush,&outrush);
Subscribers = (struct TSubscriber *)malloc(num * sizeof(struct TSubscriber));
read(fd, num, Subscribers );
fclose(fd);
calc(num, Subscribers, inrush, outrush);
free(Subscribers);
Subscribers = NULL;
} return 0;

2.49.1. Írjon programot egy telefontársaság számára, ami az egyes előfizetők telefonszámláit szeretné kiszámolni! Az előfizetők adatai az „in.txt” nevű fájlban tárolja! A program készítsen felsorolást minden előfizető számára, amelynek tartalmaznia kell a teljes beszélgetési időt, és a fizetendő összeget! Ezután a program számolja ki, melyik előfizető telefonált összesen a legtöbb ideig, ez milyen hosszú idő, kinek kell a legtöbbet fizetni, és mennyit! Használjon dinamikus tömböket! Feltételezzük, hogy a bemeneti fájl az előírásoknak megfelelő. Az input formátuma: Első sor: az előfizetők száma Második sor: két tízes számrendszerbeli szám, a csúcsidőben való telefonálás tarifája, és a csúcsidőn kívüli telefonálás tarifája. A többi sor az előfizetők adatait tárolja: az előfizető neve (keresztnév, vezetéknév), majd két tízes számrendszerbeli szám: mennyi időt telefonált az illető csúcsidőben, illetve csúcsidőn kívül. Mind a keresztnév, mind a vezetéknév maximum 10 karakterből áll. Példa bemenet: 2 3 1 csúcsidőn kívül Bela Kovacs 731 123 123 percet csúcsidőn kívül Mihaly Toth 300 35 Kimenet: Bela Kovacs: Mihaly Toth: 2316 Ft 935 Ft 854 minute 335 minute Highest fee: 2316 Ft Bela Kovacs Longest speaking: 854 Ft Bela Kovacs 2.50. Halmazok metszete
