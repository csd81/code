//3.11.2. Módosítsa úgy a programot, hogy a magánhangzókat hagyja ki, de csak akkor, ha nem egy szó elején vannak! 
3.11.2.
#include <stdio.h>
#include <string.h>
#include <ctype.h> int main() { char string[] = "The project will scale up to 1,200 marine sites,\n" "including different conditions such as surface waters,\n" "waters near methane emissions from the sea floor, and deepseasediments.";
int idxI, size;
size = strlen(string);
for (idxI = 0;
idxI < size;
idxI++) { if ( (toupper(string[idxI]) == 'A' || toupper(string[idxI]) == 'E' || toupper(string[idxI]) == 'I' || toupper(string[idxI]) == 'O' || toupper(string[idxI])== 'U') && string[idxI - 1] != ' ') ;
keudobetu, akkor nem csinal semmit else printf("%c", string[idxI]);
} return 0;
} 

