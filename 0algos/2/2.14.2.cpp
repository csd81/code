

2.14.2. Kérjünk be egy pontosságot és határozzuk meg, hogy a sor hány 
tagját kell figyelembe venni, az adott pontosság eléréséhez! 
#include <math.h>
#include <stdio.h> int main() { double result = 1, accurateResult, value;
int length = 0, faktor = 1, idxI;
double accuracy, difference;
ala printf("The accuracy of power series calculating e^x\n");
printf("x= " );
scanf("%lf", &value);
printf("How big the accuracy should be? ");
scanf("%lf", &accuracy);
accurateResult = exp(value);
difference = accuracy+1;
for (idxI = 1;
difference > accuracy;
idxI++) { result += pow(value, idxI) /faktor;
faktor *= (idxI+1);
difference = accurateResult - result;
length = idxI;
} printf("A length of %d was necessary to get a difference lower than %lf\n", 
length, accuracy);
return 0;
} 