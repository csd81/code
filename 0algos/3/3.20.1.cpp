
// 3.20.1. Írjon programot két nagyon nagy pozitív egész szám összeadására! A számok legfeljebb 100 jegyűek. Írja ki a képernyőre a két számot, majd az összegüket, a következő formátumban. A két számot fájlból olvassa be, a számok szóközzel vannak elválasztva. A számokat statikus karaktertömbökben tárolja! Példa bemenet: 434234643643746 575434253245430 Kimenet: 434234643643746 + 575434253245430 = 1009668896889176 3. 

3.20.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define INPUT_FILE "numbers.txt" #define MAX_NUMBER_LENGTH 101 #define max(a, b) ((a) > (b) ? (a) : (b)) #define min(a, b) ((a) > (b) ? (b) : (a)) char AddChar(char A, char B, char C) { int n = (A - '0') + (B - '0') + (C - '0');
return ( (n % 10)) + '0';
} char AddM(char A, char B, char C) { int n = (A - '0') + (B - '0') + (C - '0');
return ( (n / 10)) + '0';
} void Add(char * NA, char * NB, char * C) { char m;
int AI, BI;
char * A;
char * B;
int i, j;
AI = strlen(NA);
BI = strlen(NB);
A = (AI > BI) ? NA : NB;
B = (AI <= BI) ? NA : NB;
if (BI > AI) { int temp = BI;
BI = AI;
AI = temp;
} C[0] = '0';
strcpy(C + 1, A);
j = BI - 1;
m = '0';
for (i = AI - 1;
i >= 0;
i--) { if (j >= 0) { C[i + 1] = AddChar(A[i], B[j], m);
m = AddM(A[i], B[j], m);
j--;
} else { if (m != '0') { } } } C[i + 1] = AddChar(A[i], '0', m);
m = AddM(A[i], '0', m);
} C[0] = m;
if (C[0] == '0') strcpy(C, C + 1);
void Read(FILE * fd) { char Num1[MAX_NUMBER_LENGTH];
char Num2[MAX_NUMBER_LENGTH];
char Num3[MAX_NUMBER_LENGTH];
fscanf(fd, "%s %s", Num1, Num2);
printf("%s + %s = ", Num1, Num2);
Add(Num1, Num2, Num3);
printf("%s\n", Num3);
} int main() { FILE * fd = fopen(INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} Read(fd);
return 0;
} 
