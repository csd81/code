3.27.1. A Cézár-kódolás a következőképpen működik: Minden karaktert egy előre meghatározott N pozícióval eltolunk. Például, ha N = 1, az „APPLE” szó BQQMD lesz, ugyanis A-ból B lett, P-ből Q, stb. Ha N = 1, Z-ből A lesz. Példa N = 3-ra: eredeti szöveg: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG kódolt szöveg: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ Az ellenségtől egy kódolt üzenetet kaptunk. Nem ismerjük N értékét, de a kémünk azt állítja, hogy az eredeti üzenet szavai közt szerepel a „THE” szó. Írjon programot, amely beolvassa a kódolt üzenetet a „codedmessage.txt” fájlból, és megfejti, mi volt az eredeti üzenet! N értéke 1 és 26 közt van, a programnak tehát meg kell vizsgálnia minden N-t, amíg az üzenet nem tartalmazza a „THE” szót. Az üzenet tárolására használjon dinamikus tömböt! Ábra: Caesar kódolás szemléltetése Az input fájl formátuma: Első sor: Az üzenet szavainak száma. Második sor: Az üzenet szavai, egy-egy szóköz karakterrel elválasztva. Példa bemenet: 9 WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ Kimenet: The coded message: WKH TXLFN EURZQ IRA MXPSV RYHU WKH ODCB GRJ The original message: THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG 
3.27.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "codedmsg.txt" #define WORD "THE" #define MAX_WORD_LEN 15 typedef char TWord[MAX_WORD_LEN];
int ReadMessage(FILE * fd, TWord ** M) { int num, i;
fscanf(fd, "%d", &num);
(*M) = (TWord*)malloc(sizeof(TWord) * num);
for (i = 0;
i < num;
i++) fscanf(fd, "%s", (*M)[i]);
return num;
} void PrintMessage(TWord * M, int num) { int i;
for (i = 0;
i < num;
i++) printf("%s ", M[i]);
printf("\n");
} void Offset(TWord * M, int num, int offs) { int i, j, len;
for (i = 0;
i < num;
i++) { len = strlen(M[i]);
for (j = 0;
j < len;
j++) { M[i][j] += offs;
if (M[i][j] > 'Z') M[i][j] -= ('Z' - 'A' + 1 );
} } } void Decoding(TWord * M, int num) { int i = 0;
int j = num;
while ((i <= 'Z' - 'A') && (j >= num)) { Offset(M, num, 1);
j = 0;
while ((j < num) && (strcmp(M[j], WORD) != 0)) j++;
} } int main(int argc, char * argv[]) { int num;
TWord * Message;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} num = ReadMessage(fd, &Message);
fclose(fd);
printf("\nThe coded message: ");
PrintMessage(Message, num);
Decoding(Message, num);
printf("The original message: ");
PrintMessage(Message, num);
printf("\n");
free(Message);
Message = NULL;
return 0;
} 
