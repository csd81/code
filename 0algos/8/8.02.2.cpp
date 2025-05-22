// 8.2.2. Valósítsa meg a Fibonacci sort rekurzívan! Az előző program szerint tabulálással jelölje, hogy milyen mélyen van a rekurzióban! 8.3. Névsor

8.2.2.
#include <stdio.h>
#include <malloc.h> void fibonacci(long int * fibonacciArray, long int first, long int second, int count) { static int level = 0;
long int sum;
int idxI;
if (count) { level++;
for (idxI = 0;
idxI < level - 1;
idxI++) printf("\t");
printf("Begin of Fibonacci series at level %d\n", level);
fibonacciArray[count + idxI + 1] = second + first;
fibonacci(fibonacciArray, second, first + second, count - 1);
for (idxI = 0;
idxI < level - 1;
idxI++) printf("\t");
printf("End of Fibonacci series at level %d\n", level);
level--;
} } int main() { int idxI;
int maxIndex;
long int *fibonacciArray;
printf("Max index of the Fibonacci series? ");
scanf("%d", &maxIndex);
if (maxIndex < 3) { for (idxI = 0;
idxI < maxIndex;
++idxI) printf("%d. element: %d\n", idxI+1, 1);
} else { fibonacciArray = (long int *) malloc (sizeof(long int) * maxIndex);
fibonacciArray[0] = fibonacciArray[1] = 1;
for (idxI = 3;
idxI <= maxIndex;
++idxI) { meghatarozasa printf("\n");
fibonacci(fibonacciArray, 1, 1, idxI-2);
} printf("\n");
for (idxI = 0;
idxI < maxIndex;
++idxI) printf("%d. element: %ld\n", idxI + 1, fibonacciArray[idxI]);
free(fibonacciArray);
} return 0;
} 