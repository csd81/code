
2.15.2. Határozza meg az eredeti és a konvertált értékek közötti különbségeket! 2.16. DeMorgan


#include <stdio.h> int main() { double number;
printf("Mennyi legyen a szam? ");
scanf("%lf", &number);
printf("Double-float: %lf\n", number - (float)number);
printf("Double-int: %lf\n", number - (int)number);
printf("Double-short: %.2lf\n", number - (short)number);
printf("Double-char: %.2lf\n", number - (char)number);
return 0;
} 