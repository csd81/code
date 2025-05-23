2.55.2.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "date.txt" #define YEAR_MIN 1000 
#define YEAR_MAX 3000 #define MONTH_MAX 12 #define DAY_MAX 31 const char * 
Months_Strings[12] = { "January", "February", "March", "April", "May", "June", 
"July", "August", "September", "October", "November", "December" };
enum Months{ jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};
struct TDate { int Year;
int Month;
int Day;
};
void ReadDate(FILE * fd, struct TDate * Date) { fscanf(fd, "%d.", &Date->Year);
fscanf(fd, "%d.", &Date->Month);
fscanf(fd, "%d.", &Date->Day);
} void PrintDate(struct TDate * Date) { printf("Year: %d\nMonth: %s\nDay: 
%d\n", Date->Year, ((Date->Month >= 1) && (Date->Month <= 12)) ? 
Months_Strings[Date->Month - 1] : "Bad month", Date->Day);
} int CheckYear(int Y) { int errnum = 0;
if (Y > YEAR_MAX) { errnum++;
printf("Error: %d is too high for the year!\n", Y);
} if (Y < YEAR_MIN) { errnum++;
printf("Error: %d is too low for the year!\n", Y);
} return errnum;
} int CheckMonth(int M) { } int errnum = 0;
if (M > MONTH_MAX) { errnum++;
printf("Error: %d is too high for the month!\n", M);
} if (M < 1) { errnum++;
printf("Error: %d is too low for the month!\n", M);
} return errnum;
int LeapYear(int y) { if (y % 4 == 0) { if (y % 100 == 0) { if (y % 400 == 0) 
return 1;
else return 0;
} else return 1;
} return 0;
} int CheckDay(struct TDate * Date) { int errnum = 0;
switch (Date->Month) { case jan: case mar: case may: case jul: case aug: case 
oct: case dec: if (Date->Day > 31) { errnum++;
printf("Error: In %s there are 31 days!\n", Months_Strings[ Date-> Month - 1]);
} break;
case apr: case jun: case sep: case nov: if (Date->Day > 30) { errnum++;
printf("Error: In %s there are 30 days!\n", Months_Strings[ Date-> Month - 1]);
} break;
case feb: if (LeapYear(Date->Year)) { if (Date->Day > 29) { errnum++;
printf("Error: In %dth %s there are 29 days!\n", Date->Year, Months_Strings[ 
Date-> Month - 1 ]);
} } else { if (Date->Day > 28) { errnum++;
printf("Error: In %dth %s there are 28 days!\n", Date->Year, Months_Strings[ 
Date-> Month - 1 ]);
} } break;
} return errnum;
} void CheckDate(struct TDate * Date) { int errnum = CheckYear(Date->Year);
errnum += CheckMonth(Date->Month);
if (!errnum) errnum = CheckDay(Date);
printf("*******************************\nI found %d errors\n", errnum);
} int main(int argc, char *argv[]) { struct TDate Date;
FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, "r");
if (fd == 0) { perror("Error");
return 0;
} ReadDate(fd, &Date);
PrintDate(&Date);
CheckDate(&Date);
fclose(fd);
return 0;
} 
2.55.2. Írja át az előző programot úgy, hogy csak szemantikai ellenőrzés 
legyen, de abból szigorúbb! Az év 1000 és 3000 közti érték lehet. A 
hónap 1 és 12 közti érték lehet. A nap értéke 1 és 31 között lehet 
januárban, márciusban, májusban, júliusban, augusztusban, októberben és 
decemberben. A nap értéke 1 és 30 közti értéket vehet fel áprilisban, 
júniusban, szeptemberben és novemberben. Ha az év szökőév, februárban a 
nap értéke 1 és 29 közt lehet, ha nem, akkor 1 és 28 között. Szökőév 
minden 4-gyel osztható év, de a 100-zal oszthatóak nem. A 400-zal osztható 
évek mindig szökőévek. Például 1992, 1996, 2000, 1600 szökőév, de 
1800, 1900 nem az. A program elsőként az évet és a hónapot ellenőrizze, 
majd ha ezek megfelelőek, akkor a napot is! Írja ki a képernyőre a 
felfedezett hibákat! 2.56. Pascal háromszög
