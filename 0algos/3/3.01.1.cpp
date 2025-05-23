// 3.1.1. Készítsünk programot, amely bekér egy legfeljebb 6 karakter hosszú sztringet és a karakteres képernyőn megjeleníti azt úgy, hogy kiírja az egyes karakterek értékeit, karakteresen és ASCII kóddal 16-os számrendszerben, valamint kiírja az egyes karakter változóknak a neveit és ezeknek a címeit. Ötlet mutatók kiírásához használja a %p-t!  

// 3.1.1.
#include <stdio.h> int main() { const int size=6;
int idxI;
char string[size+1];
printf("string=");
scanf("%6s", string);
printf("The string is: %s\n", string);
printf("The static string address, string: %p\n", string);
printf("The dynamic string address, &string: %p\n", &string);
for (idxI=0;
idxI<size;
idxI++) { printf("\'%c\' ", string[idxI]);
} printf("\n");
for (idxI=0;
idxI<size;
idxI++) { if (string[idxI]==0) printf("0x");
printf("%#-2x ", string[idxI]);
} printf("\n");
for (idxI=0;
idxI<size;
idxI++) { printf("string[%d] ", idxI);
} printf("\n");
for (idxI=0;
idxI<size;
idxI++) { printf("%p ", &(string[idxI]));
} return 0;
} 

