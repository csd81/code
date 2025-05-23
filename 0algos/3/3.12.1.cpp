// 3.12.1. Készítsen magánhangzó statisztikát egy bekért sorról! A magánhangzó kis és nagy betűs alakját nem különböztetjük meg, csak az angol magánhangzókat tekintjük. 
3.12.1.
#include <stdio.h>
#include <string.h> int main() { char sz[80];
char c;
int n, a, o, i, e, u, idxI;
printf("text=\n");
gets(sz);
n = strlen(sz);
a = o = i = e = u = 0;
for(idxI = 0;
idxI < n;
idxI++) { c = sz[idxI];
switch (c) { case 'a': case 'A': a++;
break;
case 'o': case 'O': o++;
break;
case 'i': case 'I': i++;
break;
case 'e': case 'E': e++;
break;
case 'u': case 'U': u++;
break;
} } } printf("Vowel statistics:\n");
printf(" a,A: %d\n", a);
printf(" e,E: %d\n", e);
printf(" i,I: %d\n", i);
printf(" o,O: %d\n", o);
printf(" u,U: %d\n", u);
return 0;
