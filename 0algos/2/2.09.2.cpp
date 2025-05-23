2.9.2. Alakítsuk át a programot úgy, hogy ne a tipp helyességét kérjük 
be, hanem magát a tippet! Használjunk sprintf parancsot és használjuk ki 
azt, hogy normál forma mindig tartalmaz egy 'e' betűt. A program elején 
kérjük be a tömb nagyságát, a program végén, %-ban adjuk meg a helyes 
megoldások számát! 
2.9.2.
#include <stdio.h> int main() { int size = 5;
double myArray [] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
int idxI, idxJ, points = 0;
char choice;
char correctChoice;
char buffer [50];
int stringSizeOfAnswer;
printf("How do you think the %%g will display the next numbers? Regular or 
normal?\n");
for (idxI = 0;
idxI < size;
idxI++) { printf("\n%15.10lf ", myArray[idxI]);
stringSizeOfAnswer = sprintf (buffer, "%g", myArray[idxI]);
printf("Decide, rather %%(e) or %%(f)");
scanf("%c", &choice);
getchar();
correctChoice = 'f';
for(idxJ=0;
idxJ < stringSizeOfAnswer;
++idxJ) { if(buffer[idxJ] == 'e') correctChoice = 'e';
} if (choice == correctChoice) { printf("Correct!\n");
points++;
} else printf("Incorrect!\n");
} printf("You achieved a(n) %.lf %% result.\n", 
(double)points/(double)size*100);
return 0;
} 
