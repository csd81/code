3.32.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define MAXLEN 21 #define DEFAULT_INPUTFILE "dict.txt" void Search(FILE * fd, char * word) { int num, i, hits = 0;
char hword[MAXLEN], eword[MAXLEN];
fscanf(fd, "%d", &num);
eword[0] = 0;
for (i = 0;
i < num;
i++) { fscanf(fd, "%s %s", eword, hword);
if (strncmp(eword, word, strlen(word)) == 0) { printf("Eng->Hun: %s %s\n", eword, hword);
hits++;
} if (strcmp(hword, word) == 0) { printf("Hun->Eng: %s %s\n", hword, eword);
hits++;
} } printf("\n%d hits\n\n", hits);
} int main(int argc, char * argv[]) { char word[MAXLEN];
} FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} printf("\nType the word: ");
scanf("%s", word);
Search(fd, word);
fclose(fd);
printf("\n");
return 0;

3.32.1. Írjon angol-magyar szótár programot! Fájl tartalmazza az angol-magyar szópárokat! A program olvasson be egy szót a billentyűzetről! A szó a két nyelv bármelyikén lehet. Ezután olvassa be a szópárokat a fájlból, és keresse meg a megadott szóhoz tartozó szópárt! Az is találatnak számít, ha a begépelt szó, az előtagja az egyik szótári bejegyzésnek. Írja ki a képernyőre a találatokat! Az input fájl formátuma: Első sor: A szópárok száma A többi sor: Angol_szó Magyar_szó (szóköz karakterrel elválasztva) Egy-egy szó maximális hossza 20 karakter. Példa bemenet: 5 SUN NAP DOG KUTYA BICYCLE BICIKLI VILLAGE FALU SUNSHINE NAPSUTES Kimenet: Type the word: NAP Hun->Eng: NAP SUN 1 hits Kimenet: Type the word: SUN Eng->Hun: SUN NAP Eng->Hun: SUNSHINE NAPSUTES 2 hits 3.33. Sudoku ellenőrző
