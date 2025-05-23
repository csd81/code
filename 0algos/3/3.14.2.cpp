// 3.14.2. Módosítsa úgy a programot, hogy a második sztring minden előfordulását kiveszi az elsőből! 3.15. Kisbetű - nagybetű
3.14.2.
#include <stdio.h>
#include <string.h> void substract(char* from, char* what) { char* subString = 0;
int length;
subString = strstr(from, what);
if (!subString) return;
length = strlen(what);
strcpy(subString, subString + length);
substract(from, what);
} int main() { char from[200], what[100];
printf("Substract from=");
scanf("%s", from);
printf("Substract what=");
scanf("%s", what);
substract(from, what);
printf("\nThe reduced word is: %s\n", from);
return 0;
} 
