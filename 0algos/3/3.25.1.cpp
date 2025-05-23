3.25.1.
#include <stdio.h>
#include <stdlib.h>
#include <math.h> #define DEFAULT_A 0 #define DEFAULT_B 1 #define DEFAULT_NUM 1000000 #define min(a, b) ((a) > (b)) ? ( b ) : ( a ) #define max(a, b) ((a) > (b)) ? ( a ) : ( b ) double f1(double x) { return sqrt( (2.0 - x) * x } ) * 4.0;
double f2(double x) { return x * x;
} void Integral(int a, int b, int num, double (*fptr)(double), char * funct ) { int i;
double res = 0.0;
double interval = b - a;
double mini = interval / num;
double t;
for (i = 0;
i < num - 1;
i++) { t = min(fptr(mini * i), fptr(mini * (i + 1))) * mini;
res += t;
} printf("The Riemann integral of %s over x from %d to %d: %g\n", funct, a, b, res);
} int main(int argc, char * argv[]) { int a, b, num;
a = argc > 1 ? atoi(argv[1]) : DEFAULT_A;
b = argc > 2 ? atoi(argv[2]) : DEFAULT_B;
num = argc > 3 ? atoi(argv[3]) : DEFAULT_NUM;
printf("\n");
Integral(a, b, num, f1, "f1(x) ");
Integral(a, b, num, f2, "f2(x) ");
Integral(a, b, num, sin, "sin(x) ");
Integral(a, b, num, tan, "tan(x) ");
printf("\n");
return 0;
} 
3.25.1. Írjon programot, amely négy függvény Riemann-integrálját számítja ki 0 és 1 között! Elsőként az [a, b] intervallumot felosztjuk N db (1000000) részre, azaz egy kis intervallum hossza: h = (b - a)/N. N téglalapot képzünk úgy, hogy egyik téglalap se lógjon a függvény fölé. Az i-dik téglalap alapja tehát h magassága pedig f(h*i) és f(h*(i + 1)) közül a kisebbik. Az integrál a téglalapok összege. A számolandó függvények: f1(x) = f2(x) = x2 f3(x) = sin(x) f4(x) = tan(x) Ábra: Riemann integrál szemléltetése Példa bemenet: The Riemann integral of f1(x) over x from 0 to 1: 3.14159 The Riemann integral of f2(x) over x from 0 to 1: 0.333332 The Riemann integral of sin(x) over x from 0 to 1: 0.459696 The Riemann integral of tan(x) over x from 0 to 1: 0.615624 3.26. Polinomok összeadása
