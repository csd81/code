
3.7.1. Feladat: Írjon programot, amelyben egy 10*10-es statikus, 
inicializált, float értékeket tartalmazó mátrix tengerszint feletti 
magasság adatokat reprezentál! Adja meg a szárazföld és a tenger 
arányát, ha a negatív magasság tengerfeneket reprezentál! Adja meg a 
legmagasabb pontot és adja meg a legmagasabb pontot a tengerben feltételes 
maximum keresés segítségével! Azt az esetet is kezelni kell, amikor nincs 
tenger! Számolja ki a terület átlagos magasságát! 
 
#include <stdio.h>
#include <float.h> int main() { const int xSize=10, ySize=10;
float matrix[xSize][ySize]={ {4, 5, 6, 4, 2, 3, 4, 2, 4, 2}, {2, 2, 6, 5, 8, 7, 
5, 3, 4, 2}, {4, 3, 6, 2, 6, 3, 4, 6, 7, 2}, {7, 2, 6, -2, -3, -3, -4, 6, 1, 
2}, {4, 1, 6, -7, -2, -3, -2, -8, 4, 2}, {8, 1, 6, -7, -4, -3, -7, -6, -4, -2}, 
{4, 3, 6, 7, 3, -3, -4, -8, -2, -2}, {9, 2, 6, 6, 2, 2, -4, -8, -4, 2}, {4, 3, 
6, 8, 3, 2, 4, -6, 4, 2}, {3, 3, 6, 7, 1, 3, 5, 6, 4, 2}};
int water, land, biggestIndexX, biggestIndexY, biggestWaterIndexX, 
biggestWaterIndexY, idxI, idxJ;
float mostShallowWater, sum, avg;
water=0;
land=0;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { if (matrix[idxI][idxJ]>0) land++;
else water++;
} } printf("The ration to land to water is = %d:%d\n", land, water);
{ biggestIndexX=0;
biggestIndexY=0;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { if (matrix[idxI][idxJ] > matrix[biggestIndexX][biggestIndexY]) } } 
biggestIndexX=idxI;
biggestIndexY=idxJ;
} printf("The heighest point is at row: %d, column: %d and its height is: 
%f\n", biggestIndexX, biggestIndexY, matrix[biggestIndexX][biggestIndexY]);
biggestWaterIndexX=-1;
biggestWaterIndexY=-1;
mostShallowWater=-FLT_MAX;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { if (matrix[idxI][idxJ] < 0 && matrix[idxI][idxJ] > mostShallowWater) 
{ biggestWaterIndexX=idxI;
biggestWaterIndexY=idxJ;
mostShallowWater=matrix[biggestWaterIndexX][biggestWaterIndexY];
} } } if (biggestWaterIndexX == -1) { printf("There is no water so the search 
is meaningless.\n");
} else { printf("The most shallow water is at row: %d, column: %d and its depth 
is: %f\n", biggestWaterIndexX, biggestWaterIndexY, mostShallowWater);
} sum=0;
for (idxI=0;
idxI<xSize;
idxI++) { for (idxJ=0;
idxJ<ySize;
idxJ++) { sum+=matrix[idxI][idxJ];
} } avg=sum /(xSize*ySize);
printf("The average height is: %f\n", avg);
} return 0;

