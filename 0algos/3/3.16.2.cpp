
// 3.16.2. Alakítsa át úgy az előző programot, hogy függvényben kérje 
// be tömb méretet és ott hozza azt létre!  
// 3.16.2.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double* allocArray(int* size) {
    printf("\nArray size: ");
    scanf("%d", size);
    double* result = (double*)malloc(*size * sizeof(double));
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    return result;
}

int main() {
    int size, idxI;
    double *array = NULL, *temp = NULL;

    // 1. Kezdeti tömb létrehozása és feltöltése
    array = allocArray(&size);
    for (idxI = 0; idxI < size; idxI++) {
        printf("%d. element: ", idxI);
        scanf("%lf", &array[idxI]);
    }

    // 2. Méret duplázása
    temp = (double*)realloc(array, size * 2 * sizeof(double));
    if (temp == NULL) {
        perror("Memory reallocation failed");
        free(array);
        exit(EXIT_FAILURE);
    }
    array = temp;

    // 3. Új elemek bekérése
    for (idxI = size; idxI < size * 2; idxI++) {
        printf("%d. element: ", idxI);
        scanf("%lf", &array[idxI]);
    }

    size *= 2; // frissített méret

    // 4. Kiírás (opcionális)
    printf("\nThe full array:\n");
    for (idxI = 0; idxI < size; idxI++) {
        printf("%.2lf ", array[idxI]);
    }
    printf("\n");

    // 5. Felszabadítás
    free(array);
    array = NULL;

    return 0;
}

