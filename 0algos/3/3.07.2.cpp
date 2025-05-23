3.7.2. Határozza meg a legnagyobb szintkülönbséget a teljes területen, csak a szárazföldön, csak a tengerben! 3.8. Kockadobás
3.7.2.
#include <stdio.h>
#include <float.h> int main() { const int xSize = 10, ySize = 10;
float matrix[10][10] = { {4, 5, 6, 4, 2, 3, 4, 2, 4, 2}, {2, 2, 6, 5, 8, 7, 5, 3, 4, 2}, {4, 3, 6, 2, 6, 3, 4, 6, 7, 2}, {7, 2, 6, -2, -3, -3, -4, 6, 1, 2}, {4, 1, 6, -7, -2, -3, -2, -8, 4, 2}, {8, 1, 6, -7, -4, -3, -7, -6, -4, -2}, {4, 3, 6, 7, 3, -3, -4, -8, -2, -2}, {9, 2, 6, 6, 2, 2, -4, -8, -4, 2}, {4, 3, 6, 8, 3, 2, 4, -6, 4, 2}, {3, 3, 6, 7, 1, 3, 5, 6, 4, 2} };
int biggestWaterIndexX, biggestWaterIndexY, lowestWaterIndexX, lowestWaterIndexY;
int biggestLandIndexX, biggestLandIndexY, lowestLandIndexX, lowestLandIndexY;
int idxI, idxJ;
float highestLand=-1, lowestLand=-1, deepestWater = 1, shallowestWater = 1;
for (idxI=0;
idxI<xSize && highestLand == -1;
idxI++) { for (idxJ=0;
idxJ<ySize && highestLand == -1;
idxJ++) { if (matrix[idxI][idxJ]>0) highestLand = lowestLand = matrix[idxI][idxJ];
} } for (idxI=0;
idxI<xSize && deepestWater == 1;
idxI++) { for (idxJ=0;
idxJ<ySize && deepestWater == 1;
idxJ++) { if (matrix[idxI][idxJ]<=0) deepestWater = shallowestWater = matrix[idxI][idxJ];
} } for (idxI = 0;
idxI < xSize;
idxI++) { for (idxJ = 0;
idxJ < ySize;
idxJ++) { if (matrix[idxI][idxJ] > 0) { if (matrix[idxI][idxJ] > highestLand) highestLand = matrix[idxI][idxJ];
else if (matrix[idxI][idxJ] < lowestLand) lowestLand = matrix[idxI][idxJ];
} else { if (matrix[idxI][idxJ] < deepestWater) deepestWater = matrix[idxI][idxJ];
else if (matrix[idxI][idxJ] > shallowestWater) shallowestWater = matrix[idxI][idxJ];
} } } if(highestLand != -1) printf("The level difference on land is %f\n", highestLand lowestLand);
if (deepestWater != 1) printf("The level difference in water is %f\n", shallowestWater deepestWater);
if (highestLand != -1 && deepestWater != 1) printf("The biggest global level difference is %f\n", highestLand - deepestWater);
else printf("There's no global level difference!\n");
return 0;
} 
