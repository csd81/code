2.9.3. Alakítsuk át a programot úgy, hogy minden iterációban kérje be a %g-ben használt pontosságot is! A válasz ne csak az legyen, hogy hagyományos vagy normál formában történik a kiírás, hanem pontosan meg kell adni számot a megfelelő formában! 2.10. Szorzótábla
2.9.3.
#include <stdio.h> int main() { int size = 5;
double myArray [] = {3.456, 45697.678, -659.23, -0.0000965, 6.0000001};
int idxI, idxJ, points = 0;
int correct;
char buffer [50];
char tip [50];
int stringSizeOfAnswer;
int precision;
printf("How do you think the %%g will display the next numbers? Regular or normal?\n");
for (idxI=0;
idxI < size;
idxI++) { printf("\n%15.10lf ", myArray[idxI]);
printf("How long should the %%g precision be? ");
scanf("%d", &precision);
stringSizeOfAnswer = sprintf (buffer, "%.*g", precision, myArray[idxI]);
printf("Your tip: ");
scanf("%s", tip);
correct = 1;
for(idxJ = 0;
idxJ < stringSizeOfAnswer;
++idxJ) { if(buffer[idxJ] == tip[idxJ]) ;
else correct = 0;
} printf("%s\n", buffer);
if (correct) { printf("Correct!\n");
points++;
} else printf("Incorrect!\n");
} printf("You achieved a(n) %.lf %% result.\n", (double)points/(double)size*100);
return 0;
} 
