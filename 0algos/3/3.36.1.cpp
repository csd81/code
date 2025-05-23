3.36.1.
#include <stdio.h>
#include <stdlib.h>
#include <memory.h> #define SIZE 3 typedef double Matrix[SIZE][SIZE];
void PrintMatrix(Matrix m) { int i, j;
printf("\n");
for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) printf("%2g ", m[i][j]);
printf("\n");
} printf("\n");
} double GetDeterminant(Matrix m) { return m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1] m[0][2] * m[1][1] * m[2][0] m[0][1] * m[1][0] * m[2][2] m[0][0] * m[1][2] * m[2][1];
} void MakeAdjMatrix(Matrix m) { int i, j, x1, y1, x2, y2;
Matrix m2;
for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) { x1 = j == 0;
0 y1 = i == 0;
x2 = (j != 2) + 1;
y2 = (i != 2) + 1;
m2[j][i] = (i + j) % 2 ? -1 : 1;
m2[j][i] *= (m[y1][x1] * m[y2][x2] - m[y1][x2] * m[y2][x1]);
} } memcpy(m, m2, sizeof(double) * SIZE * SIZE);
} void InvertMatrix(Matrix m) { int i, j;
double det;
det = GetDeterminant(m);
printf("Adjugate matrix: \n");
MakeAdjMatrix(m);
PrintMatrix(m);
} printf("Determinant of the matrix: %g\n", det);
if (det != 0.0) { for (i = 0;
i < SIZE;
i++) { for (j = 0;
j < SIZE;
j++) m[i][j] /= det;
} printf("Inverse matrix: \n");
PrintMatrix(m);
} else printf("We cannot invert this matrix!\n");
int main() { Matrix matrix= { {1, 2, 3}, {2, 4, 5}, {3, 5, 6} };
printf("Original matrix:\n");
PrintMatrix(matrix);
InvertMatrix(matrix);
return 0;
} 
3.36.1. Írjon programot, amely kiszámítja egy 3x3-as mátrix inverzét! A program írja ki a képernyőre a mátrix adjungáltját, determinánst és az inverz mátrixot. Az inverz mátrixot a következőképpen számíthatjuk ki: A-1 = adj(A) / det(A), ahol adj(A) az A mátrix adjungáltja, és det(A) az A mátrix determinánsa. Ha det(A) = 0, akkor A nem invertálható. = Ábra: Mátrix elemeinek az indexelése Determináns: A 2x2-es mátrix determinánsa a következő: a11*a22 - a21*a12 A 3x3-as mátrix determinánsa: a11 * a22 * a33 + a12 * a23 * a31 + a13 * a21 * a32 - a13 * a22 * a31 - a12 * a21 * a33 - a11 * a23 * a32 Adjungált: A A ⎛ A adj( ) = ⎜− ⎜ A A + ⎝ A + ahol A A A A A A A A A + A A − A − = det A A A A A A A A A − A A + A + A A A A A A ⎞ ⎟ ⎟ ⎠ ;
Példa bemenet: Original matrix: 1 2 3 2 4 5 3 5 6 Adjugate matrix: -1 3 -2 3 -3 1 -2 1 0 Determinant of the matrix: -1 Inverse matrix: 1 -3 2 -3 3 -1 2 -1 -0 3.37. Mátrixműveletek
