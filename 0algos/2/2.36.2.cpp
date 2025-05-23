
2.36.2.
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h> int main() { char buffer[50];
char dosCommand[200] = "echo >> ";
printf("file name=");
scanf("%s", buffer);
strcat(dosCommand, buffer);
if (_chmod(buffer, _S_IWRITE) == -1) printf("File not found\n");
else { printf("Mode changed to read/write\n");
remove(buffer);
printf("File deleted\n");
} return 0;
} 
2.36.2. Írja meg a tuti törlés programot! A program először törli a csak 
olvasható tulajdonságot és utána DOS parancs segítségével törli a 
fájlt. 2.37. Átnevezés
