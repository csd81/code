2.22.2.
#include <stdio.h> int main(int argc, char* argv[]) { int idxI = argc-1;
do { printf("The %d. parameter is: %s\n", idxI, argv[idxI]);
idxI--;
} while (idxI>=0);
return 0;
} 
2.22.2. Írja át úgy a programot, hogy elől tesztelős ciklust használ és 
a program nevét nem írja ki! 2.23. continue, break
