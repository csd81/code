2.2.3. Egy adott sor kirajzolásához is használjon ciklust! Keresse meg egy sor ismétlődő mintáját és az kerüljön a ciklus magjába! Figyeljen különösen a fejlécek helyes megjelenítésére. 2.3. Terület és kerületszámítás
2.2.3.
#include <stdio.h> #define SIZE 8 int main() { int id1, id2;
printf(" |");
for (id1 = 'a';
id1 < 'a'+SIZE;
id1++) { printf("%c |",id1);
} printf("\n -|");
for (id2 = 0;
id2 < SIZE;
id2++) { printf("--|");
} for (id1 = 0;
id1 < SIZE;
id1++) { printf("\n %d|", id1+1);
for (id2 = 0;
id2 < SIZE;
id2++) { printf(" |");
} printf("\n -|");
for (id2 = 0;
id2 < SIZE;
id2++) { printf("--|");
} } printf("\n");
return 0;
} 