

2.17.2. Alakítsa át a programot, hogy ne Celsius fokot, hanem Farenheit-t 
kér be. Külön függvény végezze el a konvertálást! 2.18. Római számok
2.17.2.
#include <stdio.h> float changer(float);
int main() { float celsius;
float fahrenheit;
printf("temperature of water(in fahrenheit): ");
scanf("%f",&fahrenheit);
celsius = changer(fahrenheit);
if (celsius < 0) printf("The water is solid now.\n");
else if (celsius > 100) printf("The water is gaseous now.\n");
else printf("The water is liquid now.\n");
return 0;
} float changer(float temp) { return temp = (temp-32) * 5 / 9;
} 

