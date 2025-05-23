3.23.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define MAX_LENGTH 100 #define DEFAULT_INPUTFILE "dune.txt" #define DEFAULT_WORD "Atreides" #define FALSE 0 #define TRUE 1 int CheckWord(char * W, int len) { int l = strlen(W);
int i;
for (i = len;
i < l;
i++) { if (((W[i] >= 'A') && (W[i] <= 'Z')) || ((W[i] >= 'a') && (W[i] <= 'z'))) } return FALSE;
} return TRUE;
int SearchWord(FILE * fd, char * W) { int count = 0;
int len = strlen(W);
char ReadedWord[MAX_LENGTH]={0};
char BeforeWord[MAX_LENGTH]={0};
BeforeWord[0] = 0;
do { strcpy(BeforeWord, ReadedWord);
ReadedWord[0] = 0;
fscanf(fd, "%s", ReadedWord);
if (strncmp(ReadedWord, W, len) == 0) { if (CheckWord(ReadedWord, len)) { printf("%s %s\n",BeforeWord, ReadedWord);
count++;
} } } while (!feof(fd));
return count;
} int main(int argc, char *argv[]) { char * FileName = argc > 1 ? argv[1] : DEFAULT_INPUTFILE;
char Word[MAX_LENGTH];
FILE * fd = fopen(FileName, "r");
if (fd == NULL) { perror(FileName);
return 0;
} if (argc > 2) strcpy(Word, argv[2]);
else strcpy(Word, DEFAULT_WORD);
printf("%d hits\n", SearchWord(fd, Word));
fclose(fd);
return 0;
} 
3.23.1. Írjon programot, amely beolvassa a „dune.txt” nevű fájlt és keresi benne az „Atreides” szót! A program írja ki a képernyőre az összes találatot az előtte lévő szóval együtt! Írja ki a találatok számát is! Ha egy írásjel szerepel az Atreides szó után, pl. „Atreides.”, „Atreides,”, az jó találatnak minősül, azonban amikor az Atreides szó egy részsztringje egy szónak, azt nem tekintjük jó találatnak, pl. „Atreides-Harkonnen”, „Atreides's”. Az input fájl formátuma: A szavak szóköz karakterekkel vannak elválasztva. Példa bemenet: Leto Atreides is the head of the Atreides house. Leto Atreides's son is Paul. Kimenet: Leto Atreides the Atreides 2 hits 3.24. Egyszerű sztringfordító
