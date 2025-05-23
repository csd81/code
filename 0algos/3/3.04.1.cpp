3.4.1.
#include <stdio.h>
#include <conio.h> int main() { char string1[100], string2[100], string3[100];
int c, idxI;
printf("String input with getchar. Press enter, ctrl+z and enter to end input!\n");
idxI=0;
while((c=getchar()) != EOF) { string1[idxI]=c;
idxI++;
} string1[--idxI]=0;
printf("String input with gets: ");
gets(string2);
printf("String input with scanf: ");
scanf(„%s”, string3);
printf("\nstring1 with getchar = %s\n", string1);
printf("string2 with gets = %s\n", string2);
printf("string3 with scanf = %s\n", string3);
printf("Press any key to exit!");
c=getch();
return 0;
} 
3.4.1. Kérjen be egy-egy sztringet gets, getchar és scanf segítségével! Írja ki a sztringeket puts, putchar és printf segítségével! 

