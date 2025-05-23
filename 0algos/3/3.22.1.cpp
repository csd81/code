//  3.22.1. Írjon programot, amely kiszámítja a hallgatók ösztöndíját a tanulmányi átlaguk alapján! Fájl tartalmazza a hallgatók adatait: neptun kódjukat, és a tárgyaik kreditértékét, illetve a szerzett érdemjegyeket. A program írja ki a képernyőre minden hallgató esetében a neptun kódot, a felvett tárgyak számát, a szerzett érdemjegyek kredittel súlyozott átlagát, a felvett és a teljesített kreditek összegét, és a hallgató számára megítélt ösztöndíjat! Egy tárgy teljesített, ha a hallgató átment az adott tárgyból. Az átlagba a felvett tárgyak és nem a teljesítettek tartoznak. Az ösztöndíjak összege: · 0 <= átlag < 2 → 0 HUF · 2 <= átlag < 3 → 15 000 HUF · 3 <= átlag < 4 → 20 000 HUF · 4 <= átlag < 4.5 → 25 000 HUF · 4.5 <= átlag <= 5 → 30 000 HUF Az input fájl formátuma: Első sor: A hallgatók száma. A hallgatók adatait tartalmazó sor: Sztring number1 Az egyes tárgyakhoz tartozó sor: number2 number3 Példa bemenet: 2 TGDS32 3 4 2 3 5 3 4 FBG4SW 3 4 5 2 3 4 1 A TGDS32 és FBG4SW neptun kódú hallgató adatait látjuk. TGDS32 3 tárgyat vett fel, az első tárgya 4 kredit értékű, az érdemjegye belőle 2. Kimenet: Neptun: TGDS32 3 subjects Neptun: FBG4SW 3 subjects TGDS32: Credits: 10/10 Average: 3.5 Bursary: 20000 HUF FBG4SW: Credits: 10/6 Average: 3 Bursary: 20000 HUF 3.23. Szavak keresése
3.22.1.
#include <stdio.h>
#include <stdlib.h> #define INPUT_FILE "students.txt" #define MIN_AVERAGE 2.0 #define MIDDLE_AVERAGE 3.0 #define GOOD_AVERAGE 4.0 #define EXCELLENT_AVERAGE 4.5 #define MIN_BURSARY 15000 #define MIDDLE_BURSARY 20000 #define GOOD_BURSARY 25000 #define EXCELLENT_BURSARY 30000 struct TSubject { int credit;
int mark;
};
struct TStudent { char Neptun[7];
int SubjNum;
struct TSubject * Subjects;
};
void ReadStudent(FILE * fd, struct TStudent * S) { int i;
fscanf(fd, "%s %d", S->Neptun, &S->SubjNum);
printf("Neptun: %s %d subjects\n", S->Neptun, S->SubjNum);
S->Subjects = (struct TSubject *)malloc(sizeof(struct TSubject) * S>SubjNum);
for (i = 0;
i < S->SubjNum;
i++) fscanf(fd, "%d %d", &(S->Subjects + i)->credit, &(S->Subjects + i)>mark);
} void Calc(struct TStudent * S, int SNum) { int i, j, sum;
int Credits, MaxCredits, Bursary;
double Average;
struct TSubject * Subj;
for (i = 0;
i < SNum;
i++) { Subj = S->Subjects;
Credits = MaxCredits = 0;
sum = 0;
for (j = 0;
j < S->SubjNum;
j++) { sum += Subj->credit * Subj->mark;
MaxCredits += Subj->credit;
if (Subj->mark >= 2) Credits += Subj->credit;
Subj++;
} Average = (double)sum / MaxCredits;
if (Average < MIN_AVERAGE) Bursary = 0;
else if (Average < MIDDLE_AVERAGE) Bursary = MIN_BURSARY;
else if (Average < GOOD_AVERAGE) Bursary = MIDDLE_BURSARY;
else if (Average < EXCELLENT_AVERAGE) Bursary = GOOD_BURSARY;
else Bursary = EXCELLENT_BURSARY;
printf("%s:\n\tCredits: %d/%d\n\tAverage: %g\n\tBursary: %d HUF\n",S>Neptun, MaxCredits, Credits, Average, Bursary);
S++;
} } int Read(FILE * fd, struct TStudent ** S) { int num, i;
fscanf(fd, "%d", &num);
*S = (struct TStudent *)malloc(sizeof(struct TStudent) * num);
for (i = 0;
i < num;
i++) ReadStudent(fd, (*S) + i);
return num;
} void FreeStudents(struct TStudent * S, int SNum) { int i;
for (i = 0;
i < SNum;
i++) { free(S[i].Subjects);
S[i].Subjects = NULL;
} } int main() { int StudentNum;
struct TStudent * Students;
FILE * fd = fopen(INPUT_FILE, "r");
if (fd == NULL) { perror("Error");
return 0;
} StudentNum = Read(fd, &Students);
fclose(fd);
Calc(Students, StudentNum);
FreeStudents(Students, StudentNum);
return 0;
} 


