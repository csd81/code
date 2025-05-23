// 3.33. Sudoku  ellenőrző

// 3.33.1. Írjon programot, amely leellenőriz egy kitöltött Sudoku táblát! A 
// tábla értékeit olvassa be fájlból! Egy tábla akkor van helyesen 
// kitöltve, ha minden sorban, minden oszlopban és minden kis 3x3-as kis 
// négyzetben az 1-9 közti számjegyek mindegyike egyszer szerepel. Az ábrán 
// egy helyesen kitöltött tábla szerepel. 9 5 8 2 7 4 6 3 1 1 4 7 5 3 6 9 2 8 2 
// 6 3 9 8 1 4 7 5 8 3 1 4 6 9 2 5 7 4 2 5 3 1 7 8 9 6 7 9 6 8 5 2 1 4 3 3 1 4 7 2 
// 8 5 6 9 5 8 9 6 4 3 7 1 2 6 7 2 1 9 5 3 8 4 Ábra: Sudoku tábla Az input fájl 
// formátuma: Az input fájl 9 sort és 9 oszlopot tartalmaz. A számjegyek 
// egy-egy szóköz karakterrel vannak elválasztva. Példa bemenet: 7 4 6 8 3 1 5 
// 9 2 9 2 3 5 7 4 8 6 1 8 1 5 2 9 6 4 7 3 1 3 4 7 5 2 6 8 9 6 9 7 3 1 8 2 5 4 5 8 
// 2 4 6 9 1 3 7 4 7 9 6 2 8 3 1 8 3 6 8 1 4 7 9 2 5 2 5 1 9 8 3 7 4 6 Kimenet: 
// This is a wrong table! 


// 3.33.1.


#include <stdio.h>
#include <stdlib.h>

#define SIZE 9
#define TRUE 1
#define FALSE 0
#define DEFAULT_INPUTFILE "sudoku1.txt"

typedef int TTable[SIZE][SIZE];

void ReadTable(FILE* fd, TTable T) {
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            fscanf(fd, "%d", &T[i][j]);
}

void PrintTable(TTable T) {
    printf("\nSudoku Table:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j)
            printf("%d ", T[i][j]);
        printf("\n");
    }
    printf("\n");
}

int isValidGroup(int values[SIZE]) {
    int seen[SIZE + 1] = {0}; // index 1..9
    for (int i = 0; i < SIZE; ++i) {
        int val = values[i];
        if (val < 1 || val > 9 || seen[val])
            return FALSE;
        seen[val] = 1;
    }
    return TRUE;
}

int CheckRows(TTable T) {
    for (int i = 0; i < SIZE; ++i) {
        int row[SIZE];
        for (int j = 0; j < SIZE; ++j)
            row[j] = T[i][j];
        if (!isValidGroup(row)) return FALSE;
    }
    return TRUE;
}

int CheckColumns(TTable T) {
    for (int j = 0; j < SIZE; ++j) {
        int col[SIZE];
        for (int i = 0; i < SIZE; ++i)
            col[i] = T[i][j];
        if (!isValidGroup(col)) return FALSE;
    }
    return TRUE;
}

int CheckBoxes(TTable T) {
    for (int boxY = 0; boxY < 3; ++boxY) {
        for (int boxX = 0; boxX < 3; ++boxX) {
            int values[SIZE];
            int idx = 0;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                    values[idx++] = T[boxY * 3 + i][boxX * 3 + j];
            if (!isValidGroup(values)) return FALSE;
        }
    }
    return TRUE;
}

void Check(TTable T) {
    if (CheckRows(T) && CheckColumns(T) && CheckBoxes(T)) {
        printf("This table is correct!\n");
    } else {
        printf("This is a wrong table!\n");
    }
}

int main(int argc, char* argv[]) {
    TTable table;
    FILE* fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
    if (!fd) {
        perror("Error opening input file");
        return 1;
    }

    ReadTable(fd, table);
    fclose(fd);

    PrintTable(table);
    Check(table);

    return 0;
}
