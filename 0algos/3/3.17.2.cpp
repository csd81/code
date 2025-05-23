
// 3.17.2. Készítse el az újraméretez függvényt, amely vagy levág a 
mátrixból egy darabot, és/vagy a mátrix jobb oldalához illetve aljához 
hozzáfűz egy új részt! Az új rész egységmátrix szerűen tartalmazzon 
0-kat és 1-ket, ha az új rész nem négyzet alakú, akkor az egyesek 
fűrészfog szerűen helyezkedjenek el! 1 1 1 1 1 1 1 3.3. ábra: Téglalap 
alakú egységmátrix 3.18. Virtuális memória
3.17.2.
#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h> double** allocMatrix(int rows, int cols) { double** result = 
NULL;
int idxI;
if (rows <= 0 || cols <= 0) return NULL;
result = (double**) malloc(rows * sizeof(double*));
for (idxI = 0;
idxI < rows;
idxI++) { result[idxI] = (double*) malloc(cols * sizeof(double));
} return result;
} void freeMatrix(double** mat, int rows) { int idxI;
if (rows <= 0) return;
if (!mat) return;
for (idxI = 0;
idxI < rows;
idxI++) { free(mat[idxI]);
} free(mat);
} void randMatrix(double** mat, int rows, int cols, int min, int max) { int 
idxI, idxJ;
if (rows <= 0 || cols <= 0) return;
srand((unsigned int) time(NULL));
for (idxI = 0;
idxI < rows;
idxI++) { for (idxJ = 0;
idxJ < cols;
idxJ++) { mat[idxI][idxJ] = rand() % (max - min + 1) + min;
} } } void printMatrix(double** mat, int rows, int cols) { int idxI, idxJ;
if (rows <= 0 || cols <= 0) return;
for (idxI = 0;
idxI < rows;
idxI++) { printf("[");
for (idxJ = 0;
idxJ < cols;
idxJ++) { printf("%.2lf, ", mat[idxI][idxJ]);
} printf("]\n");
} } void cutMatrix(double ** mat, int rows, int cols) { double** result = NULL;
int selected, newcols = 0, newrows = 0, i, j, db = 0;
printf("1. Cut the bottom and add to the right side.\n");
printf("2. Cut the bottom\n");
printf("3. Add to the right side\n");
printf("Choose: ");
scanf("%d", &selected);
switch (selected) { case 1: printf("How many rows whould you like to delete? ");
scanf("%d", &newrows);
printf("How many columns whould you like to add to the right side? ");
scanf("%d", &newcols);
newcols += cols;
newrows = cols - newrows;
result = allocMatrix(newrows, newcols);
for (i = 0;
i < newrows;
i++) { for (j = 0;
j < newcols;
j++) { result[i][j] = mat[i][j];
} } for (i = 0;
i < cols;
i++) { if ((i + 1) % (newrows) == 0) { db++;
} } 1) for (i = cols;
i < newcols;
i++) { for (j = 0;
j < newrows;
j++) { if ((((i + 1) - (newrows * db)) / (j + 1)) == 1 && (((i + - (newrows * 
db)) % (j + 1)) == 0) { result[j][i] = 1;
} else { result[j][i] = 0;
} } if ((i + 1) % (newrows) == 0) { db++;
} } break;
break;
case 2: printf("How many rows whould you like to delete? ");
scanf("%d", &newrows);
newcols += cols;
newrows = rows - newrows;
result = allocMatrix(newrows, newcols);
for (i = 0;
i < newrows;
i++) { for (j = 0;
j < newcols;
j++) { result[i][j] = mat[i][j];
} } break;
case 3: printf("How many columns whould you like to add to the right side? ");
1) scanf("%d", &newcols);
newcols += cols;
newrows += rows;
result = allocMatrix(newrows, newcols);
for (i = 0;
i < rows;
i++) { for (j = 0;
j < cols;
j++) { result[i][j] = mat[i][j];
} } for (i = 0;
i < cols;
i++) { if ((i + 1) % (newrows) == 0) { db++;
} } for (i = cols;
i < newcols;
i++) { for (j = 0;
j < newrows;
j++) { if ((((i + 1) - (newrows * db)) / (j + 1)) == 1 && (((i + - (newrows * 
db)) % (j + 1)) == 0) { result[j][i] = 1;
} else { result[j][i] = 0;
} } if ((i + 1) % (newrows) == 0) { db++;
} } break;
} } printf("matrix A =\n");
printMatrix(mat, rows, cols);
printf("new matrix A =\n");
printMatrix(result, newrows, newcols);
freeMatrix(result, newrows);
int main() { int rowA, colA;
double **matA = NULL;
printf("Number of rows of matrix A: ");
scanf("%d", &rowA);
printf("Number of columns of matrix A: ");
scanf("%d", &colA);
matA = allocMatrix(rowA, colA);
randMatrix(matA, rowA, colA, 12, 16);
cutMatrix(matA, rowA, colA);
} freeMatrix(matA, rowA);
matA = NULL;
return 0;
