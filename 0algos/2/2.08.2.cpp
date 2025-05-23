2.8.2. Az előző feladathoz hasonlóan írassuk ki a következő sorokat: _ 
_+235 _-1.291E4 00026 0XAB2 1.64e-003 2.9. Hagyományos vagy normál forma
2.8.2.
#include <stdio.h> int main() { int a = 235, c = 26, d = 2*1+11*16+10*16*16;
float b = -12910;
float e = 0.00164;
printf("%+6d\n", a);
printf("%12.3E\n", b);
printf("%05d\n", c);
printf("%#X\n", d);
printf("%.2e\n", e);
return 0;
} 
