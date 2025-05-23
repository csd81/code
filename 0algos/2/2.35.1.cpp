
2.35.1.
#include <stdio.h> typedef enum { awfull, bad, weak, good, excelent } Result;
void printResult(Result value) { switch (value) { case awfull: printf("awfull");
break;
case bad: printf("bad");
break;
case weak: printf("weak");
break;
case good: printf("good");
break;
case excelent: printf("excelent");
break;
} } int main() { Result exam1, exam2;
int dummy;
printf("Provide the result of your exam:\nawfull - %d, bad - %d, weak - %d, good- %d, excelent - %d ", awfull, bad, weak, good, excelent);
scanf("%d", &dummy);
exam1 = (Result)dummy;
printf("\nYour result is: ");
printResult(exam1);
printf("\n\nProvide the result of your repeating exam:\nawfull - %d, bad - %d, weak - %d, good- %d, excelent - %d ", awfull, bad, weak, good, excelent);
scanf("%d", &dummy);
exam2 = (Result)dummy;
} if (exam1 < exam2) { printf("Very good, you improved!");
} if (exam1 == exam2) { printf("At least you tried!");
} if (exam1 > exam2) { printf("You must be very unlucky!");
} return 0;

2.35.1. Írjon programot, amelyben bekéri egy szóbeli vizsga minősítését! A minősítés lehet: szörnyű, rossz, gyenge, jó, kiváló. Használjon felsorolás típust! Írjon függvényt a minősítés szöveges kiírására! Kérje be az ismétlő vizsga eredményét, határozza meg, hogy javított-e az illető! 
