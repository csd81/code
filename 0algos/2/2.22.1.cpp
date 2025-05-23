

2.22.1.
#include <stdio.h> int main(int argc, char* argv[]) { int idxI;
for (idxI=argc-1;
idxI>=0;
idxI--) { printf("The %d. parameter is: %s\n", idxI, argv[idxI]);
} return 0;
} 
2.22.1. Írjon programot, amely kiírja a program paramétereit fordított 
sorrendben! 
