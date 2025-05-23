2.1.2. Kérjen be pontszámot, amelynek -25 és 50 közé kell esnie! A vizsga sikerességét csak akkor vizsgálja, ha a pontszám a helyes intervallumban van! A siker feltétele a 25 pontnál jobb eredmény. 

2.1.2.
#include <stdio.h> int main() { float result;
printf("result=");
_flushall();
scanf("%f", &result);
if (result>50) { printf("Passed\n");
} else { printf("Failed\n");
} return 0;
} 