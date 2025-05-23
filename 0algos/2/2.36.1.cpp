
2.36.1.
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h> int main() { char buffer[50];
char dosCommand[200] = "echo >> ";
printf("file name=");
scanf("%s", buffer);
if( _chmod(buffer, _S_IREAD | _S_IREAD) == -1 ) printf("File not found\n");
else printf("Mode changed to read-only\n");
strcat(dosCommand, buffer);
system(dosCommand);
if( _chmod(buffer, _S_IWRITE ) == -1) printf("File not found\n");
else printf("Mode changed to read/write\n");
system(dosCommand);
return 0;
} 
2.36.1. Írjon programot, amely beállítja egy fájl „csak olvasható” 
tulajdonságát! Kérje be egy szöveges fájl nevét! Állítsa be a fájl 
csak olvasható tulajdonságát, majd próbáljon meg a fájl végéhez fűzni 
egy szöveget C-ből hívott DOS parancs segítségével (DOS parancs: echo 
text >>fileName)! Futtassa a DOS parancsot C-ből: system(char*) 
segítségével! Törölje a csak olvasható tulajdonságot és próbáljon 
ismét a fájl végéhez fűzni egy szöveget! 
