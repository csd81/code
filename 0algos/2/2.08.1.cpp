2.8.1.
#include <stdio.h> int main() { float a=12.45, b=-234.1, c=57967.2, d=134567;
printf("%+7.2f\n", a);
printf("%7.1f\n", b);
printf("%+8.1f\n", c);
printf("%+6.0f\n", d);
return 0;
} 
2.8.1. printf segítségével írja ki a következő sorokat, úgy hogy 
változókban tárolja az egyes értékeket! A szóközt „_”-al jelöljük. 
A kiírandó szöveg: _+12.45 _-234.1 +57967.2 +134567 
