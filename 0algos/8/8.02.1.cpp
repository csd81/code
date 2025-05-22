// 8.2.1. Valósítsa meg a gyorsrendezést! Mindig írja ki, hogy milyen mélyen van a rekurzióban statikus változó segítségével, és hogy mely résztömböt rendezi éppen! A kiírásokat a rekurzió mélysége alapján tabulálja! 


8.2.1.
#include <stdio.h> void print(double* tomb, int size) { int idxI;
printf("[");
for (idxI=0;
idxI<size;
idxI++) printf("%lf ", tomb[idxI]);
printf("]");
} void swap(double* tomb, int id1, int id2) { double temp;
temp=tomb[id1];
tomb[id1]=tomb[id2];
tomb[id2]=temp;
} int partition(double* tomb, int left, int right) { create a new array and copy values into the begining and ending from the old one, and copy back the values into the original array double val=tomb[left];
int lm = left-1;
int rm = right+1;
while (1) { do rm--;
while (tomb[rm] > val);
do lm++;
while(tomb[lm] < val);
if(lm < rm) swap(tomb, rm, lm);
else return rm;
} } return 0;
void quickSort(double* tomb, int left, int right) { index, right=last valid index static int level=0;
int idxI;
level++;
for (idxI=0;
idxI<level-1;
idxI++) printf("\t");
printf("Begin of quickSort at level %d, [%d, %d]\n", level, left, right);
if(left < right) { int split_pt = partition(tomb,left, right);
quickSort(tomb, left, split_pt);
quickSort(tomb, split_pt+1, right);
} for (idxI=0;
idxI<level-1;
idxI++) printf("\t");
printf("End of quickSort at level %d, [%d, %d]\n", level, left, right);
level--;
} int main() { double myArray[]={0, -6, 7, -42, 6, 9};
int size = sizeof myArray / sizeof (double);
static arrays } printf("The original myArray: ");
print(myArray, size);
quickSort(myArray, 0, size-1);
printf("\nThe quick sorted myArray: ");
print(myArray, size);
return 0;
