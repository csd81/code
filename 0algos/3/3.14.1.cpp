// 3.14.1. Írjon programot, amely egy sztringből kivon egy másikat! 
Például: almafavirág - fa = almavirág. Ha a második paraméter nincs az 
elsőben, akkor ne változzon az első paraméter érétke! 
3.14.1.
#include <stdio.h>
#include <string.h> void substract(char* from, char* what) { char* subString=0;
int len;
subString=strstr(from, what);
if (!subString) return;
len = strlen(what);
strcpy(subString, subString+len);
} int main() { char from[200], what[100];
} printf("Substract from=");
scanf("%s", from);
printf("Substract what=");
scanf("%s", what);
substract(from, what);
printf("\nThe reduced word is: %s", from);
return 0;

