// 3.23. Szavak keresése
// 3.23.1. Írjon programot, amely beolvassa a „dune.txt” nevű fájlt és 
// keresi benne az „Atreides” szót! A program írja ki a képernyőre az 
// összes találatot az előtte lévő szóval együtt! Írja ki a találatok 
// számát is! Ha egy írásjel szerepel az Atreides szó után, pl. 
// „Atreides.”, „Atreides,”, az jó találatnak minősül, azonban amikor 
// az Atreides szó egy részsztringje egy szónak, azt nem tekintjük jó 
// találatnak, pl. „Atreides-Harkonnen”, „Atreides's”. Az input fájl 
// formátuma: A szavak szóköz karakterekkel vannak elválasztva. Példa 
// bemenet: Leto Atreides is the head of the Atreides house. Leto Atreides's son 
// is Paul. Kimenet: Leto Atreides the Atreides 2 hits 
// 3.23.1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100
#define DEFAULT_INPUTFILE "dune.txt"
#define DEFAULT_WORD "Atreides"

// Ellenőrzi, hogy a len hosszú előtag után csak írásjel van-e
int CheckWord(const char *W, int len) {
    int l = strlen(W);
    for (int i = len; i < l; i++) {
        if (isalpha(W[i])) return 0; // Rossz: még betű jön
        if (W[i] == '-' || W[i] == '\'') return 0; // Rossz: kötőjel, aposztróf
    }
    return 1; // Jó: csak írásjelek
}

// Megkeresi a szót a fájlban
int SearchWord(FILE *fd, const char *target) {
    int count = 0;
    int len = strlen(target);
    char ReadedWord[MAX_LENGTH] = {0};
    char BeforeWord[MAX_LENGTH] = {0};

    while (fscanf(fd, "%s", ReadedWord) == 1) {
        if (strncmp(ReadedWord, target, len) == 0) {
            if (CheckWord(ReadedWord, len)) {
                printf("%s %s\n", BeforeWord, ReadedWord);
                count++;
            }
        }
        strcpy(BeforeWord, ReadedWord);
    }

    return count;
}

int main(int argc, char *argv[]) {
    const char *filename = (argc > 1) ? argv[1] : DEFAULT_INPUTFILE;
    const char *searchWord = (argc > 2) ? argv[2] : DEFAULT_WORD;

    FILE *fd = fopen(filename, "r");
    if (!fd) {
        perror(filename);
        return EXIT_FAILURE;
    }

    int hits = SearchWord(fd, searchWord);
    printf("%d hits\n", hits);

    fclose(fd);
    return EXIT_SUCCESS;
}

