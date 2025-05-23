// 3.17.1. Írjon programot két dinamikus mátrix összeszorzására! 
// Függvényben foglaljon helyet a mátrixoknak, amelyeket véletlen egészekkel 
// töltsön fel! Írjon függvényt a mátrixszorozásra, ellenőrizze, hogy a 
// mátrix mértek kompatibilisek-e, a függvény visszatérési értéke legyen 
// az új eredmény mátrix! Írassa ki az eredetei és az eredmény mátrixokat 
// függvényben, majd szabadítsa fel azokat! 
// 3.17.1.

#include <stdio.h>
#include <malloc.h>
#include <memory.h>
#include <time.h> double** allocMatrix(int rows, int cols) { double** 
result=NULL;
int idxI;
if (rows<=0 || cols<=0) return NULL;
result = (double**)malloc(rows * sizeof(double*));
for (idxI=0;
idxI<rows;
idxI++) { result[idxI] = (double*)malloc(cols * sizeof(double));
} return result;
} void freeMatrix(double** mat, int rows) { int idxI;
if (rows<=0) return;
if (!mat) return;
for (idxI=0;
idxI<rows;
idxI++) { if (!mat[idxI]) free(mat[idxI]);
} free(mat);
} void randMatrix(double** mat, int rows, int cols, int min, int max) { int 
idxI, idxJ;
if (rows<=0 || cols<=0) return;
srand((unsigned int)time(NULL));
for (idxI=0;
idxI<rows;
idxI++) { for (idxJ=0;
idxJ<cols;
idxJ++) { mat[idxI][idxJ] = rand()%(max-min+1)+min;
} } } double** multMatrix(double** matA, int rowA, int colA, double** matB, int 
rowB, int colB, int *rowC, int *colC) { double** result=NULL, sum;
int idxI, idxJ, idxK;
if (colA != rowB) } return NULL;
*rowC = rowA;
*colC = colB;
result = allocMatrix(*rowC, *colC);
srand((unsigned int)time(NULL));
for (idxI=0;
idxI<rowA;
idxI++) { for (idxJ=0;
idxJ<colB;
idxJ++) { sum = 0;
for (idxK=0;
idxK<colA;
idxK++) { sum += matA[idxI][idxK]*matB[idxK][idxJ];
} result[idxI][idxJ] = sum;
} } return result;
void printMatrix(double** mat, int rows, int cols) { int idxI, idxJ;
if (rows<=0 || cols<=0) return;
for (idxI=0;
idxI<rows;
idxI++) { printf("[");
for (idxJ=0;
idxJ<cols;
idxJ++) { printf("%lf, ", mat[idxI][idxJ]);
} printf("]\n");
} } int main() { int rowA, colA, rowB, colB, rowC, colC;
double **matA=NULL, **matB=NULL, **matC=NULL;
printf("Number of rows of matrix A: ");
scanf("%d", &rowA);
printf("Number of columns of matrix A: ");
scanf("%d", &colA);
printf("Number of rows of matrix B: ");
scanf("%d", &rowB);
printf("Number of columns of matrix B: ");
scanf("%d", &colB);
matA = allocMatrix(rowA, colA);
matB = allocMatrix(rowB, colB);
randMatrix(matA, rowA, colA, 12, 16);
randMatrix(matB, rowB, colB, -4, 5);
matC = multMatrix(matA, rowA, colA, matB, rowB, colB, &rowC, &colC);
printf("matrix A =\n");
printMatrix(matA, rowA, colA);
printf("matrix B =\n");
printMatrix(matB, rowB, colB);
printf("matrix A*B =\n");
printMatrix(matC, rowC, colC);
freeMatrix(matA, rowA);
matA = NULL;
freeMatrix(matB, rowB);
matB = NULL;
freeMatrix(matC, rowC);
matC = NULL;
return 0;
} 
