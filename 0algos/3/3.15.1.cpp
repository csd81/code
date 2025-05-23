
// 3.15.1. Írjon programot, amely bekért mondatot formáz adott választás szerint! Menüből választhatóak a következő lehetőségek: UPPER CASE (mindent nagybetűre), lower case (mindent kisbetűre), tOGGLE CASE (kis betűket nagyra és nagyokat kicsire), Sentense case (a sor első betűje nagy csak), Title Case (minden szókezdő betű nagy). Mind a konvertálások, mind a menü függvénnyel legyen megoldva! 
3.15.1.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h> char* upperCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) result[idxI]=toupper(result[idxI]);
return result;
} char* lowerCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) result[idxI]=tolower(result[idxI]);
return result;
} char* toggleCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) { if (isupper(result[idxI])) result[idxI]=tolower(result[idxI]);
else result[idxI]=toupper(result[idxI]);
} return result;
} char* sentenceCase(char* string) { char* result=0;
int len, idxI;
result = strdup(string);
len = strlen(string);
result[0]=toupper(result[0]);
for (idxI=1;
idxI<len;
idxI++) result[idxI]=tolower(result[idxI]);
return result;
} char* titleCase(char* string) { char* result=0;
int len, idxI, startWord=1;
result = strdup(string);
len = strlen(string);
for (idxI=0;
idxI<len;
idxI++) { if (startWord) result[idxI]=toupper(result[idxI]);
else result[idxI]=tolower(result[idxI]);
if (result[idxI]==' ') startWord = 1;
else startWord = 0;
} return result;
} int menu() { int select;
printf("UPPER CASE - 1\n");
printf("lower case - 2\n");
printf("tOGGLE CASE - 3\n");
printf("Sentence case - 4\n");
printf("Title Case - 5\n");
scanf("%d", &select);
return select;
} int main() { char myString[200], *result;
int cheoice;
printf("orinigal string=");
gets(myString);
choice = menu();
switch (choice) { case 1: result = upperCase(myString);
break;
case 2: result = lowerCase(myString);
break;
case 3: result = toggleCase(myString);
break;
case 4: result = sentenceCase(myString);
break;
case 5: result = titleCase(myString);
break;
} printf("\nresult=\"%s\"", result);
free(result);
return 0;
} 

