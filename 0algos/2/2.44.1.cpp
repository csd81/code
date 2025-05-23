2.44.1.
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h> int main() { int year, month, day, guessWeekDay, 
guessYearDay;
tm tmBuffer;
char string[30];
tmBuffer.tm_hour = 0;
tmBuffer.tm_min = 0;
tmBuffer.tm_sec = 0;
tmBuffer.tm_isdst = -1;
srand((unsigned)time(NULL));
year = rand()%40+1970;
month = rand()%12+1;
day = rand()%30+1;
tmBuffer.tm_year = year-1900;
tmBuffer.tm_mon = month;
tmBuffer.tm_mday = day;
printf("What is the day of the week on %d/%d %d?\n", month, day, year);
printf("0 - Sunday, 1 - Monday, ...;
your guess: ");
scanf("%d", &guessWeekDay);
mktime(&tmBuffer);
strftime(string, 30, "%A", &tmBuffer);
if (tmBuffer.tm_wday == guessWeekDay) { printf("You are rigth %d/%d %d is 
really %s.\n", month, day, year, string);
} else { printf("You are wrong %d/%d %d is %s.\n", month, day, year, string);
} printf("\nWhat is the day of the year on the same date? ");
scanf("%d", &guessYearDay);
if (tmBuffer.tm_yday == guessYearDay) { printf("You are rigth %d/%d %d is the 
%d day of the year.\n", month, day, year, tmBuffer.tm_yday);
} else { printf("You are wrong %d/%d %d is the %d day of the year.\n", month, 
day, year, tmBuffer.tm_yday);
} return 0;
} 
2.44.1. Írjon programot, amely véletlenszerűen meghatároz egy évet, 
hónapot, napot és utána tippelni kell, hogy az a hét illetve év napjai 
közül a hányadik! Adja meg hogy helyesek voltak-e a tippek! 2.45. Hérón 
képlet
