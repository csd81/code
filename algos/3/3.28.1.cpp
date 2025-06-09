// 3.28. CD  katalógus
// 3.28.1. Rendelkezik egy CD katalógussal, amit fájlban tárol. Írjon 
// programot, amely képes arra, hogyha begépeli egy szoftver nevét, akkor 
// megmondja, melyik CD-n van a szoftver! A szoftverek nevei maximum 15 karakter 
// hosszúak, és minden CD-nek van egy neve, amely szintén maximum 15 karakter 
// hosszú. Használjon struktúrákat, illetve dinamikus tömböket a fájlból 
// beolvasott adatok tárolására! Az input fájl formátuma: Első sor: A CD-k 
// száma. A további sorok: String: A CD neve Egész szám: A CD-n lévő 
// szoftverek száma Ezután a CD-n lévő szoftverek neve következik. Példa 
// bemenet: 2 2007/11 2 BurningStudio RadioRama 2005/4 3 Doc2PDF Apollo Stellarium 
// A példában Jamesnek 2 CD-je van, az első neve „2007/11”, ezen a CD-n 
// két szoftver van: BurningStudio és RadioRama. A másik CD 3 szoftvert 
// tartalmaz. Kimenet: Software name: Apollo The Apollo is here: 2005/4 
// 3.28.1.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_INPUTFILE "cds.txt"
#define MAX_WORD_LENGTH 16

typedef char TWord[MAX_WORD_LENGTH];

struct TCD {
    char Name[MAX_WORD_LENGTH];
    int Num;
    TWord* P; // Dinamikusan foglalt szoftverlista
};

void ReadCD(FILE* fd, struct TCD* cd) {
    fscanf(fd, "%s", cd->Name);
    fscanf(fd, "%d", &cd->Num);
    cd->P = (TWord*)malloc(sizeof(TWord) * cd->Num);
    for (int i = 0; i < cd->Num; ++i) {
        fscanf(fd, "%s", cd->P[i]);
    }
}

int ReadCDs(FILE* fd, struct TCD** outCDs) {
    int count;
    fscanf(fd, "%d", &count);
    *outCDs = (struct TCD*)malloc(sizeof(struct TCD) * count);
    for (int i = 0; i < count; ++i) {
        ReadCD(fd, &(*outCDs)[i]);
    }
    return count;
}

void Search(struct TCD* cds, int num, const char* query) {
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < cds[i].Num; ++j) {
            if (strcmp(cds[i].P[j], query) == 0) {
                printf("The %s is here: %s\n", query, cds[i].Name);
                return;
            }
        }
    }
    printf("%s does not exist!\n", query);
}

void FreeCDs(struct TCD* cds, int num) {
    for (int i = 0; i < num; ++i) {
        free(cds[i].P);
    }
    free(cds);
}

int main(int argc, char* argv[]) {
    const char* filename = (argc > 1) ? argv[1] : DEFAULT_INPUTFILE;
    FILE* fd = fopen(filename, "r");

    if (!fd) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    struct TCD* cds = NULL;
    int cdCount = ReadCDs(fd, &cds);
    fclose(fd);

    TWord software;
    printf("Program name: ");
    scanf("%15s", software);

    Search(cds, cdCount, software);

    FreeCDs(cds, cdCount);
    return EXIT_SUCCESS;
}

