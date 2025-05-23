2.41.1.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { clock_t actClock;
double actSec=0;
while (actSec < 11) { actClock = clock();
actSec = (double)actClock / CLOCKS_PER_SEC;
printf("\n%lf", actSec);
} return 0;
} 
2.41.1. Készítsünk stopperórát, amely a program indításától eltelt 
időt írja ki folyamatosan! A program 11 másodperc után álljon meg! 
