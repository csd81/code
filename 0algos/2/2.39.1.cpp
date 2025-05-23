
2.39.1.
#include <stdio.h>
#include <stdlib.h> double average(char* fileName) { double result, sum=0;
int counter=0, data;
FILE* file;
file = fopen(fileName, "r");
while ( !feof(file) ) { fscanf(file, "%d", &data);
counter++;
sum += data;
} } fclose(file);
file = NULL;
result = sum / counter;
return result;
int main() { FILE *orig=NULL, *even=NULL, *odd=NULL;
int evenCounter=0, oddCounter=0, data;
char origFileName[200], evenFileName[200]="even.txt", oddFileName[200]="odd.txt";
double evenAverage, oddAverage;
printf("This program will divide a bunch of number according to parity.\n");
printf("file name=");
scanf("%s", origFileName);
orig = fopen(origFileName, "r");
if (orig == NULL) { fprintf(stderr, "File open to read has failed!\n");
exit(-1);
} even = fopen(evenFileName, "w");
odd = fopen(oddFileName, "w");
while ( !feof(orig) ) { fscanf(orig, "%d", &data);
if (data%2 == 0) { evenCounter++;
fprintf(even, "%d\n", data);
} else { oddCounter++;
fprintf(odd, "%d\n", data);
} } fclose(orig);
orig = NULL;
fclose(even);
even = NULL;
fclose(odd);
odd = NULL;
printf("There were %d even and %d odd number, their ratio is: %8lg\n", evenCounter, oddCounter, (double)evenCounter/oddCounter);
evenAverage = average(evenFileName);
oddAverage = average(oddFileName);
printf("The average of the even numbers: %.9lg\nThe average of the odd numbers: %.9lg\n", evenAverage, oddAverage);
return 0;
} 
2.39.1. Írjon programot, amely egy már meglévő, véletlen számokat tartalmazó fájlban lévő számokat szétválogatja párosság alapján! A páros és páratlan számokat tárolja külön fájlokban! Írjon függvényt, amely kiszámolja az egy fájlban lévő számok átlagát! Alkalmazza a függvényt a két fájlra és határozza meg a két fájlban lévő számok mennyiségének az arányát! 2.40. XML
