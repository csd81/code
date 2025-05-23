2.59.1. Egy fájl több törtet tartalmaz. Írjon programot, amely beolvassa a törteket, és összeadja őket! Minden összeadás után számolja ki az aktuális összeg számlálójának és nevezőjének legnagyobb közös osztóját az Euklideszi algoritmus segít- ségével, és ha lehet, akkor egyszerűsítse a törtet, majd folytassa az összeadást! Minden műveletet írjon ki a képernyőre a példában látható módon! Az Euklideszi algoritmus megadja két szám legnagyobb közös osztóját. procedure Euclidean(A, B) M = B while M is not zero { B = M M = A mod B A = B } Az input fájl formátuma: Első sor: a törtek száma A többi sorban két pozitív egész található, az első a számláló, a második a nevező értéke. A két érték szóköz karakterrel van elválasztva. Példa bemenet: 3 2 3 4 5 6 11 Kimenet: 2 4 ------ + ------ = 3 5 -----15 6 ------ + ------ = -----165 4 ------ + ------ = 3 1656 ------ = -----55 2.60. Nevezetes számok Számelmélettel már az ókori Görögországban is sokat foglalkoztak, például sok nevezetes tulajdonságú számot próbáltak meghatározni.
2.59.1.
#include <stdio.h>
#include <stdlib.h> #define DEFAULT_INPUTFILE "nums.txt" int Eukl(int a, int b) { int m = b;
while (m != 0) { b = m;
m = a % b;
a = b;
} } return b;
void ReadAndAdd(FILE * fd) { int count, i;
int num1, num2;
int den = 0, numer = 0;
int tmp1, tmp2;
int d;
fscanf(fd, "%d", &count);
for (i = 0;
i < count;
i++) { fscanf(fd, "%d %d", &num1, &num2);
if (den != 0) { tmp2 = den * num2;
tmp1 = num2 * numer + den * num1;
d = Eukl(tmp1, tmp2);
if (d != 1) { printf("%4d %4d %4d %4d\n", numer, num1, tmp1, tmp1 / d);
printf("------ + ------ = ------ = ------\n");
printf("%4d %4d %4d %4d\n\n", den, num2, tmp2, tmp2 / d);
} else { printf("%4d %4d %4d\n", numer, num1, tmp1);
printf("------ + ------ = ------\n");
printf("%4d %4d %4d\n\n", den, num2, tmp2);
} numer = tmp1 / d;
den = tmp2 / d;
}else { den = num2;
numer = num1;
} } } int main(int argc, char * argv[]) { FILE * fd = fopen(argc > 1 ? argv[1] : DEFAULT_INPUTFILE, „r”);
if (fd == NULL) { perror("Error");
return 0;
} ReadAndAdd(fd);
fclose(fd);
return 0;
} 
