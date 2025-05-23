
2.28.2
#include <stdio.h> int main() { double** myMatrix;
int *pData=&myMatrix, **ppData=&pData, ***pppData=&ppData;
int idxI, idxJ, idxK, temp = 0;
myMatrix = (double**)malloc(2 * sizeof(double*));
for (idxI=0;
idxI<2;
idxI++) { myMatrix[idxI] = (double*)malloc(3 * sizeof(double));
} for(idxI = 0;
idxI < 2;
idxI++) for(idxJ = 0;
idxJ < 3;
idxJ++) myMatrix[idxI][idxJ] = ++temp;
printf("****Adresses****\n");
printf("myMatrix**: [%#p] -> myMatrix[0,1]*: [%#p, %#p]\n", &myMatrix, &myMatrix[0], &myMatrix[1]);
printf("myMatrix[0]*: [%#p]-> myMatrix[0][0,1,2]: [%#p, %#p, %#p]\n", &myMatrix[0], &myMatrix[0][0], &myMatrix[0][1], &myMatrix[0][2]);
printf("myMatrix[1]*: [%#p]-> myMatrix[1][0,1,2]: [%#p, %#p, %#p]\n", &myMatrix[1], &myMatrix[1][0], &myMatrix[1][1], &myMatrix[1][2]);
printf("\n***Values****\n");
printf("myMatrix**: [%#p] : myMatrix[0,1]*: [%#p, %#p]\n", myMatrix, myMatrix[0], myMatrix[1]);
printf("myMatrix[0]*: [%#p] : myMatrix[0][0,1,2]: [%.2lf, %.2lf, %.2lf]\n", myMatrix[0], myMatrix[0][0], myMatrix[0][1], myMatrix[0][2]);
printf("myMatrix[1]*: [%#p] : myMatrix[1][0,1,2]: [%.2lf, %.2lf, %.2lf]\n", myMatrix[1], myMatrix[1][0], myMatrix[1][1], myMatrix[1][2]);
} for (idxI=0;
idxI<2;
idxI++) free(myMatrix[idxI]);
free(myMatrix);
return 0;

2.28.2. Írjon programot, amely a konzolos képernyőn szemléltet egy 2*3 dinamikus double tömböt! 
