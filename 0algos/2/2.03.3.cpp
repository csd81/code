2.3.3. Bővítse ki a programot úgy, hogy az oldalak hossza csak pozitív érték lehet, síkidomválasztáskor a kis és a nagy betűket is fogadjuk el, ha rossz választ adtunk, akkor az jelezzük, vegyük be a választható idomok közé a szabályos háromszöget! 2.4. Számláló ciklus
2.3.3.
#include <stdio.h>
#include <math.h> int main() { float a, b;
char figure, prop;
printf("Program to calculate the area or perimeter of a rectengular, square or triangle.\n");
printf("Calculate rectengular (r) or square (s) or triangle (t)");
scanf("%c", &figure);
if (figure == 'r' || figure == 'R') { printf("a= ");
");
");
scanf("%f", &a);
if (a < 0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("b= ");
scanf("%f", &b);
if (b < 0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("Would you like to calculate area (a) or perimeter (p) ? scanf("%c", &prop);
if (prop == 'a') { printf("The area of the rectengular is: %f", a*b);
} else { printf("The perimeter of the rectengular is: %f", (a+b)*2);
} } else if (figure == 's' || figure == 'S') { printf("a= ");
scanf("%f", &a);
if (a<0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("Would you like to calculate area (a) or perimeter (p) ? scanf("%c", &prop);
if (prop == 'a') { printf("The area of the square is: %f", a*a);
} else { printf("The perimeter of the square is: %f", a*4);
} } else if (figure == 't' || figure == 'T') { printf("a=");
scanf("%f", &a);
if (a<0) { printf("This must be a positive value!\n");
return 1;
} _flushall();
printf("Would you like to calculate area (a) or perimeter (p) ? ");
scanf("%c", &prop);
if (prop == 'a') { printf("The area of the trianegle is: %f", a*a*sqrt(3)/4);
} else { printf("The perimeter of the triangle is: %f", a*3);
} } else { printf("Incorrect type of shape!\n");
return 1;
} return 0;
} 