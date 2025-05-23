
2.37.1. Feladat: Írjon programot fájlok átnevezésére! A régi és az új 
fájlnév a program paraméterében legyen adott! Ha valamelyik paraméter 
hiányzik, akkor írja ki a helyes használatot! Ha hiba történik átnevezés 
közben, akkor írja ki a megfelelő hibaüzenetet a hibakód alapján! 2.38. 
Szövegfájl
2.37.1.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> extern int errno;
int main(int argc, char* argv[]) { char oldName[50], newName[50];
int result;
if (argc != 3) { printf("Usage:\n prgName oldName newName\n");
exit(1);
} strcpy(oldName, argv[1]);
strcpy(newName, argv[2]);
rename(oldName, newName);
result = errno;
switch (result) { case 0: printf("Done! ");
break;
case EEXIST: printf("%s already exists!", newName);
break;
case ENOENT: printf("%s does not exist!", oldName);
break;
case EINVAL: printf("Wrong characters in '%s'!", newName);
break;
} } return 0;
