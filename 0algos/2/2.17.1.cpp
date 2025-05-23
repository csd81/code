


2.17.1. Írjon programot, amely a víz hőmérséklete alapján megállapítja 
annak halmazállapotát! 

#include <stdio.h> int main() { float temperature;
printf("temperature of water=");
} scanf("%f", &temperature);
if (temperature < 0) { printf("Solid water\n");
} else if (temperature < 100) { printf("Liquid water\n");
} else { printf("Gaseous water\n");
} return 0;
