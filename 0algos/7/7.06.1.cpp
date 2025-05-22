7.6.1. Valósítsuk meg a Bellman-Ford algoritmust egy gráfon! Az algoritmus egy irányított gráf adott pontjától keresi meg a minimális költségű utakat a gráf többi pontjába. Először az egy, majd a kettő él hosszú legrövidebb utakat keresi meg és így tovább. Ha a gráf negatív kört tartalmaz, az algoritmus nem ad vissza jó értéket. 


7.6.1.
#include <stdio.h> typedef struct { int u, v, weight;
}Edge;
#define INFINITY 10000 #define SIZE 5 void BellmanFord(int, int, int, int*, Edge*);
void PrintDistances(int, int[]);
int main() { Edge edges[1024];
int i, j;
int edges_num = 0, source_node = 2;
int distances_from_source[SIZE];
int adjacenci_matrix[SIZE][SIZE] = { {0, 6, 0, 7, 0}, {0, 0, 5, 8, -4}, {0, -2, 0, 0, 0}, {0, 0, -3, 9, 0}, {2, 0, 7, 0, 0} };
printf("The adjacenci matrix:\n");
for (i = 0;
i < SIZE;
++i) { for (j = 0;
j < SIZE;
++j) { printf("%d ", adjacenci_matrix[i][j]);
if (adjacenci_matrix[i][j] != 0) { edges[edges_num].u = i;
edges[edges_num].v = j;
edges[edges_num].weight = adjacenci_matrix[i][j];
edges_num++;
} } printf("\n");
} printf("\nRun Belmann-Ford algorithm to node %d\n", source_node);
BellmanFord(source_node, SIZE, edges_num, distances_from_source, edges);
printf("\nMinimal distances from node %d:\n", source_node);
PrintDistances(SIZE, distances_from_source);
return 0;
} void PrintDistances(int size, int* distances_from_source) { int i;
for (i = 0;
i < size;
++i) printf("to %d\t", i + 1);
printf("\n");
for (i = 0;
i < size;
++i) printf("%d\t", distances_from_source[i]);
} printf("\n");
void BellmanFord(int source, int size, int edges_num, int* distances_from_source, Edge* edges) { int i, j;
for (i = 0;
i < size;
++i) distances_from_source[i] = INFINITY;
distances_from_source[source] = 0;
for (i = 0;
i < size - 1;
++i) for (j = 0;
j < edges_num;
++j) if (distances_from_source[edges[j].u] + edges[j].weight < distances_from_source[edges[j].v]) distances_from_source[edges[j].v] = distances_from_source[edges[j].u] + edges[j].weight;
} 
