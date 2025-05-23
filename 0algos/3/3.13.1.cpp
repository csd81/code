// 3.13.1. Írja meg a „tuvudsz ivigy beveszevelnivi” programot! A kimenet csupa nagybetű legyen! írja meg azt a függvényt, amely eldönti, hogy egy betű magánhangzó-e! 
3.13.1.
#include <stdio.h>
#include <string.h>
#include <ctype.h> int in(char c) { char s[]="AEIOU";
unsigned int idxI;
idxI=0;
do { if (c == s[idxI]) return 1;
idxI++;
} while (idxI <= strlen(s));
return 0;
} int main() { char orig[255], newVer[255], kar;
unsigned int idxI;
int idxJ;
printf("sentence=\n");
gets(orig);
idxJ=-1;
for(idxI=0;
idxI<strlen(orig);
idxI++) { idxJ++;
kar=toupper(orig[idxI]);
newVer[idxJ]=kar;
if( in(kar) ) { newVer[++idxJ]='V';
newVer[++idxJ]=kar;
} } newVer[++idxJ]='\0';
printf("%s", newVer);
return 0;
} 

