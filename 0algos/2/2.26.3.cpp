
2.26.3.
#include <stdio.h> #define _USE_MATH_DEFINES
#include <math.h> int main() { float radius;
float *radius1 = &radius, *radius2 = &radius, *radius3 = &radius;
float surface, volume;
} printf("The radius of the ball is: ");
scanf("%f", &radius);
surface = 4 * (*radius1) * (*radius2) * (*radius3) * (M_PI) / 3;
volume = 4 * (*radius1) * (*radius2) * (M_PI);
printf("The volume of the ball is: %f\n", volume);
printf("The surface of the ball is: %f\n", surface);
return 0;

2.26.3. Írjon az előzőhöz hasonló programot gömbre vonatkozóan! 2.27. 
Két kulcsos hozzáférés
