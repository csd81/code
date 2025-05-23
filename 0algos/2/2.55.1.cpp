2.55.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h> #define DEFAULT_INPUTFILE "date.txt" #define DOT '.' #define MAX_LENGTH 10 struct TDate { char Year[MAX_LENGTH];
char Month[MAX_LENGTH];
char Day[MAX_LENGTH];
};
void InitDate(struct TDate * Date) { Date->Year[0] = Date->Month[0] = Date->Day[0] = 0;
} void ReadDate(FILE * fd, struct TDate * Date) { fscanf(fd, "%s", Date->Year);
fscanf(fd, "%s", Date->Month);
fscanf(fd, "%s", Date->Day);
} void PrintDate(struct TDate * Date) { printf("%s %s %s\n", Date->Year, Date->Month, Date->Day);
} int CheckNumAndDots(char * S, char * A) { int i;
int len = strlen(S);
int errnum = 0;
for (i = 0;
i < len - 1;
i++) { if ((S[i] > '9') || (S[i] < '0')) { errnum++;
printf("Error: the %s cannot contain %c character!\n", A, S[i]);
} } if (S[len - 1] != DOT) { errnum++;
printf("Error: A \"%c\" have to follow the number, not \”%c\”!\n", DOT, S[len - 1]);
} return errnum;
} int CheckNums(struct TDate * Date) { int errnum = 0;
int month = atoi(Date->Month);
int day = atoi(Date->Day);
if ((month > 12) || (month < 1)) { errnum++;
printf("Error: There are only 12 months!\n");
} if ((day > 31) || (day < 1)) { errnum++;
printf("Error: There are atmost 31, at least 1 days in a month!\n");
} return errnum;
} void CheckDate(struct TDate * Date) { int errnum = CheckNumAndDots(Date->Year, "Year");
errnum += CheckNumAndDots(Date->Month, "Month");
errnum += CheckNumAndDots(Date->Day, "Day");
if (errnum == 0) errnum += CheckNums(Date);
printf("*******************************\nI found %d errors\n", errnum);
} int main(int argc, char *argv[]) { struct TDate Date;
InitDate(&Date);
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == 0) { perror("Error");
return 0;
} ReadDate(fd, &Date);
PrintDate(&Date);
CheckDate(&Date);
fclose(fd);
return 0;
} 
2.55.1. Írjon programot, amely beolvas egy dátumot egy fájlból, szintaktikai és szemantikai ellenőrzést végez rajta és kiírja az esetleges hibákat! Szintaktikai ellenőrzés: A dátum 3 számot tartalmaz, mindegyik szám után egy pont szerepel. A számok csak számjegyet tartalmazhatnak! Például a „2007.” megfelelő, de a következők nem: „2A07.”, „2007”. Szemantikai ellenőrzés: Akkor hajtódik végre, ha a szintaktikai ellenőrzés nem jelzett hibát. A hónap értéke 1 és 12 közt, a napé 1 és 31 közt változhat. Ha az értékek valamelyike hibás, ezt a program írja ki a képernyőre. Az input fájl formátuma: Év. Hónap. Nap. Példa bemenet: 2007. 12. 31. Kimenet: 2007. 12. 31. ******************************* I found 0 errors Példa bemenet: 2007 1u2. 31 Kimenet: 2007 1u2. 31 Error: A "." have to follow the number, not "7"! Error: the Month cannot contain u character! Error: A "." have to follow the number, not "1"! ******************************* I found 3 errors Példa bemenet: 2007. 13. 0. Kimenet: 2007. 13. 0. Error: There are only 12 months! Error: There are at most 31, at least 1 days in a month! ******************************* I found 1 errors 

