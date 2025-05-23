// 3.15.2. Valósítsa meg a „Nice Title Case” formázást! A szavak első betűje nagy kivéve az alábbi szavak esetén: and, of, the, a, an, from, for, in. A kivételt nem kell figyelembe venni a sor első karakterénél és egy kettős pont után. Például: „The Life of an English Man and the War” 3.16. Tömbnövelés
3.15.2.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h> char* lowerCase(char* string) { char* result=0;
int len, idxI;
result = _strdup(string);
len = strlen(string);
for (idxI = 0;
idxI < len;
idxI++) result[idxI] = tolower(result[idxI]);
return result;
} char* sentenceCase(char* string) { char* result = 0;
int len, idxI;
result = _strdup(string);
len = strlen(string);
result[0] = toupper(result[0]);
for (idxI = 1;
idxI < len;
idxI++) result[idxI] = tolower(result[idxI]);
return result;
} char* niceTitleCase(char* string) { char* result = 0;
int len, idxI, startWord = 1;
result = _strdup(string);
len = strlen(string);
result = lowerCase(result);
result = sentenceCase(result);
for (idxI = 0;
idxI < len;
idxI++) { if (result[idxI] == ':') { legyen mindenfele keppen nagybetu result[idxI+1] = toupper(result[idxI+1]);
idxI++;
} else if( result[idxI] == 'f' && result[idxI+1] == 'o' && result[idxI+2] == 'r' && result[idxI+3] == ' ') idxI += 3;
else if (result[idxI] == 'a' && result[idxI+1] == 'n' && result[idxI+2] == 'd' && result[idxI+3] == ' ') idxI += 3;
else if (result[idxI] == 't' && result[idxI+1] == 'h' && result[idxI+2] == 'e' && result[idxI+3] == ' ') idxI += 3;
else if (result[idxI] == 'f' && result[idxI+1] == 'r' && result[idxI+2] == 'o' && result[idxI+3] == 'm' && result[idxI+4] == ' ') idxI += 4;
else if (result[idxI] == 'o' && result[idxI+1] == 'f' && result[idxI+2] == ' ') idxI += 2;
else if (result[idxI] == 'i' && result[idxI+1] == 'n' && result[idxI+2] == ' ') idxI += 2;
else if (startWord) result[idxI] = toupper(result[idxI]);
else result[idxI] = tolower(result[idxI]);
if (result[idxI] == ' ' || result[idxI] == '\t' || result[idxI] == '\n') startWord = 1;
else startWord = 0;
} return result;
} int main() { char myString[200], *result;
printf("original string=");
gets(myString);
result = niceTitleCase(myString);
} printf("\nresult= \"%s\"\n", result);
free(result);
return 0;

