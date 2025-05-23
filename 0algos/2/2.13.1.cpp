2.13.1. Kérjen be egy előjel nélküli karakter típusú változót egészként és írja ki a kettes számrendszerbeli alakját! 
2.13.1.
#include <stdio.h>
#include <math.h> int main() { unsigned char number=0, result, delMask=0x80;
int idxI;
printf("number=");
scanf("%d", &number);
printf("Its value in number system 2: ");
} for (idxI=0;
idxI<8;
idxI++) { result = number & delMask;
printf("%u", result?1:0);
delMask = delMask>>1;
} printf("\n");
return 0;