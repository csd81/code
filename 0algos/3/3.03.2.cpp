3.3.2. A kezdeti sztringben 3 double típusú szám legyen, az elsőt eggyel, a másodikat kettővel, a harmadikat hárommal növeljük meg! A megnövelt értékeket egy új tömbbe írjuk ki normál alakban, 8 tizedes pontossággal és előjellel! 3.4. Sztring bekérés
3.3.2.
#include <stdio.h> int main() { int idxI;
char string[] = "48.1658745 -654686835454.321635432435421 9.8765432e-11";
double doubleValue[3], sum = 0;
sscanf(string, "%lf %lf %lf", &doubleValue[0], &doubleValue[1], &doubleValue[2]);
for (idxI = 0;
idxI < 3;
idxI++) { doubleValue[idxI] = doubleValue[idxI] +idxI +1;
sum += doubleValue[idxI];
} sprintf(string, "%+.8lf %+.8lf %+.8lf", doubleValue[0], doubleValue[1], doubleValue[2]);
printf("The new string array is %s\n", string);
return 0;
} 
