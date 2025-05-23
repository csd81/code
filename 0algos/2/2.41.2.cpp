2.41.2.
#include <stdio.h>
#include <stdlib.h>
#include <time.h> int main() { clock_t actClock;
double actSec=0;
int intActSec=0, intOldSec=0;
while (actSec < 11) { actClock = clock();
actSec = (double)actClock / CLOCKS_PER_SEC;
intActSec = (int)actSec;
if (intActSec>intOldSec) { printf("\n%d", intActSec);
intOldSec = intActSec;
} } return 0;
} 
2.41.2. Módosítsa a programot úgy, hogy csak minden egész másodpercben 
írja ki az eltelt időt! 2.42. Időpont formázása

