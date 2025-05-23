
2.26.1.
#include <stdio.h> int main() { int side;
int *side1=&side, *side2=&side, *side3=&side;
int surface, volume;
} printf("The side of the cube is: ");
scanf("%d", &side);
surface = 6**side1*(*side2);
volume = *side1*(*side2)**side3;
printf("The volume of the cube is: %d\n", volume);
printf("The surface of the cube is: %d\n", surface);
return 0;

2.26.1. Írjon programot, amelyben egy kocka felületét és térfogatát számolja ki! Úgy írja fel a képletet, hogy két ugyanolyan nevű változó ne szerepeljen benne, hanem használjon alias változókat mutatók segítségével. 
2.26.2. Demonstrálja, hogy a * és a & ellentétes hatású műveletek! 
2.26.2. printf("The volume of the cube is: %d\n", *&*&volume);
