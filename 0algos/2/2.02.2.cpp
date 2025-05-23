2.2.2. Az azonos sorok kiírásához használjon ciklust! 
2.2.2.
#include <stdio.h> #define SIZE 8 int main() { int id;
printf(" |a |b |c |d |e |f |g |h |\n");
printf(" -|--|--|--|--|--|--|--|--|\n");
for (id = 0;
id < SIZE;
id++) { printf(" %d| | | | | | | | |\n", id + 1);
printf(" -|--|--|--|--|--|--|--|--|\n");
} return 0;
} 