//3.11.1. Írjon programot, amely egy szöveg minden negyedik karakterét 
kihagyja, ha az nem white space! inicializálja úgy a sztringet, hogy abban 
több sor legyen és ezek a sorok a program kódban is sorokban legyenek 
(külön idézőjel párok felhasználásával)! A néggyel való 
oszthatóságot külön függvénnyel valósítsa meg! 
3.11.1.
#include <stdio.h>
#include <string.h> int devisableBy4(int num) { if (num/4==num/4.) return 1;
return 0;
} int main() { char s[]="The project will scale up to 1,200 marine sites,\n" 
"including different conditions such as surface waters,\n" "waters near methane 
emissions from the sea floor, and deep-sea sediments. ";
int idxI, size;
size = strlen(s);
for (idxI=0;
idxI<size;
idxI++) { if (!devisableBy4(idxI) || (s[idxI]=='\n' || s[idxI]=='\t' || 
s[idxI]==' ')) printf("%c", s[idxI]);
} return 0;
} 

